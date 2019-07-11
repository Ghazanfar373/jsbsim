/*
 * DDSInterface.cpp
 *
 *  Created on: Nov 8, 2012
 *      Author: sim-paf
 */

#include "DDSInterface.h"
#include "ccpp_FDM.h"
#include "ccpp_QTControl.h"
#include "FDM.h"
#include "TacticalAircrafts.h"
#include "TacticalEnvironment.h"
#include "ImageGeneration.h"
#include "AutoPilot.h"

#include <iostream>
#include <fstream>



char *topicName[]={"FDMDATA","QTCONTROLDATA","QTTACTICALENVIRONMENT","TACTICALAIRCRAFTS","IMAGEGENERATIONDATA", "AUTOPILOTDATA"};
namespace JSBSim {

using namespace DDS;
using namespace QTControl;


DDSInterface::DDSInterface( JSBSim::FGFDMExec *FDMExec):FGModel(FDMExec){

	QuitFromIOS = false;
	bool autodispose_unregistered_instances = false;
    system("./startDomain.sh");

	createParticipant("DDSDomain","DDSDomain"); //same name for domain and partition
	cout<<"Participant Created!"<<endl;
	fdmdataType = new fdmdataTypeSupport();
	QtControlDataType = new QtControlDataTypeSupport();
    TacticalAircraftsDataType = new TacticalAircraftsDataTypeSupport();
    QTTacticalEnvironmentDataType = new QTTacticalEnvironmentDataTypeSupport();
    ImageGenerationDataType = new ImageGenerationDataTypeSupport();
    AutoPilotDataType = new AutoPilotDataTypeSupport();



    createTopic(fdmdataType,topicName[0],fdmdataTopic);
	cout<<"fdmdata Topic Created!"<<endl;

	createTopic(QtControlDataType,topicName[1],QtControlDataTopic);
	cout<<"Qt Controldata Topic Created!"<<endl;

    createTopic(QTTacticalEnvironmentDataType,topicName[2],QTTacticalEnvironmentDataTopic);
    cout<<"QTTacticalEnvironmentData Topic created! "<<endl;

    createTopic(TacticalAircraftsDataType,topicName[3],TacticalAircraftsDataTopic);
    cout<<"TacticalAircraftsData Topic created! "<<endl;

    createTopic(ImageGenerationDataType,topicName[4],ImageGenerationDataTopic);
    cout<<"ImageGenerationData Topic created!"<<endl;

    createTopic(AutoPilotDataType,topicName[5],AutoPilotDataTopic);
    cout<<"AutoPilot Topic Created! "<<endl;


    createPublisher();
	cout<<"Publisher Created! "<<endl;
	createSubscriber();
	cout<<"Subscriber Created! "<<endl;
	//bool autodispose_unregistered_instances = false;

	QtControlDataReader = QtControlDataDataReader::_narrow(createQtControlReader(QtControlDataTopic));
	cout<<"QtControlData Data Created!"<<endl;

	fdmdataWriter = fdmdataDataWriter::_narrow(createDataWriter(autodispose_unregistered_instances, fdmdataTopic));
	cout<<"DataWriter for fdmdata Created!"<<endl;

    QTTacticalEnvironmentDataReader = QTTacticalEnvironmentDataDataReader::_narrow(createQtControlReader(QTTacticalEnvironmentDataTopic));
    cout<<"QTTacticalEnvironmentData reader created! "<<endl;

    TacticalAircraftDataWriter = TacticalAircraftsDataDataWriter::_narrow(createDataWriter(autodispose_unregistered_instances, TacticalAircraftsDataTopic));
    cout<<"DataWriter for Tactical Aircrafts Created! "<<endl;

    ImageGenerationDataWriter = ImageGenerationDataDataWriter::_narrow(createDataWriter(autodispose_unregistered_instances,ImageGenerationDataTopic));
    cout<<"DataWriter for ImageGeneration Created!"<<endl;

    AutoPilotDataReader = AutoPilotDataDataReader::_narrow(createQtControlReader(AutoPilotDataTopic));
    cout<<"AutoPilot Reader Created!"<<endl;

	// TODO Auto-generated constructor stub

}

DDSInterface::DDSInterface():FGModel()
{

	AllDoneFromIos = false;
	QuitFromIOS = false;
	QuickStart = false;
	bool autodispose_unregistered_instances = false;
	createParticipant("MirageIFSim","MirageIFSim"); //same name for domain and partition
	cout<<"Participant Created!"<<endl;

}

bool DDSInterface::InitRun()
{
	//readFDMCMDIOSTopic();
	return true;
}
void DDSInterface::createParticipant(const char *domainName, const char * partitionName){
	dpf = DomainParticipantFactory::get_instance();
	checkHandle(dpf.in(), "DDS::DomainParticipantFactory::get_instance");
	participant = dpf->create_participant(domainName, PARTICIPANT_QOS_DEFAULT, NULL,
	  STATUS_MASK_NONE);
	checkHandle(participant.in(),
	  "DDS::DomainParticipantFactory::create_participant");
	partition = partitionName;
}


void DDSInterface::deleteParticipant(){
	status = dpf->delete_participant(participant.in());
		 checkStatus(status, "DDS::DomainParticipant::delete_participant ");
}


void DDSInterface::createTopic(TypeSupport *ts, char *topicName, Topic_var &topic){


	 CORBA::String_var typeName;
	 typeName = ts->get_type_name();

	 ts->register_type(participant.in(),typeName);
	 checkStatus(status, "register_type");
	 Duration_t t;
	 t.sec = 1;
     topic = participant->find_topic(topicName, t);
	 status = participant->get_default_topic_qos(reliable_topic_qos);
	 checkStatus(status, "DDS::DomainParticipant::get_default_topic_qos");
	 //reliable_topic_qos.reliability.kind = RELIABLE_RELIABILITY_QOS;
	 //reliable_topic_qos.durability.kind = TRANSIENT_DURABILITY_QOS;

	 /* Make the tailored QoS the new default. */
	 status = participant->set_default_topic_qos(reliable_topic_qos);
	 checkStatus(status, "DDS::DomainParticipant::set_default_topic_qos");

	 /* Use the changed policy when defining the HelloWorld topic */
	 if(topic == NULL)
	 {
         cout <<"topic not found creating topic"<<endl;
                 
	 topic = participant->create_topic(topicName, typeName, reliable_topic_qos,
			 NULL, STATUS_MASK_NONE);
	 checkHandle(topic.in(), "DDS::DomainParticipant::create_topic ()");
	 } else cout << "topic found!"<<endl;

}

void DDSInterface::createPublisher(){
	DataReaderQos qos;
	//qos.reliability.kind = BEST_EFFORT_RELIABILITY_QOS;
	qos.reliability.kind = RELIABLE_RELIABILITY_QOS;
	status = participant->get_default_publisher_qos(pub_qos);
	checkStatus(status, "DDS::DomainParticipant::get_default_publisher_qos");
	pub_qos.partition.name.length(1);
	pub_qos.partition.name[0] = partition;

	publisher = participant->create_publisher(pub_qos, NULL, STATUS_MASK_NONE);
	checkHandle(publisher.in(), "DDS::DomainParticipant::create_publisher");
}

void DDSInterface::deletePublisher()
{
	status = participant->delete_publisher(publisher.in());
    checkStatus(status, "DDS::DomainParticipant::delete_publisher ");
}

void DDSInterface::createSubscriber()
{//Aileron Command:
  int status = participant->get_default_subscriber_qos(sub_qos);
  checkStatus(status, "DDS::DomainParticipant::get_default_subscriber_qos");
  sub_qos.partition.name.length(1);
  sub_qos.partition.name[0] = partition;
  subscriber = participant->create_subscriber(sub_qos, NULL, STATUS_MASK_NONE);
  checkHandle(subscriber.in(), "DDS::DomainParticipant::create_subscriber");
}

void DDSInterface::deleteSubscriber()
{
  status = participant->delete_subscriber(subscriber);
  checkStatus(status, "DDS::DomainParticipant::delete_subscriber ");
}

DataWriter_ptr DDSInterface::createDataWriter(bool autodispose_unregistered_instances, Topic_var &topic){
	DataWriter_ptr writer;
	status = publisher->get_default_datawriter_qos(dw_qos);
	checkStatus(status, "DDS::DomainParticipant::get_default_publisher_qos");
	status = publisher->copy_from_topic_qos(dw_qos, reliable_topic_qos);
	checkStatus(status, "DDS::Publisher::copy_from_topic_qos");
	// Set autodispose to false so that you can start
	// the subscriber after the publisher
	dw_qos.writer_data_lifecycle.autodispose_unregistered_instances =
	autodispose_unregistered_instances;
	writer = publisher->create_datawriter(topic.in(), dw_qos, NULL,
    STATUS_MASK_NONE);//Aileron Command:
	checkHandle(writer, "DDS::Publisher::create_datawriter");
	return writer;
}

void DDSInterface::deleteDataWriter(DataWriter_ptr writer){
	status = publisher->delete_datawriter(writer);
		checkStatus(status, "DDS::Publisher::delete_datawriter ");
}

DataReader_ptr DDSInterface::createDataReader(Topic_var &topic)
{
	DataReaderQos qos;
	subscriber->get_default_datareader_qos(qos);
	qos.history.depth = 5;
	qos.reliability.kind = RELIABLE_RELIABILITY_QOS;
	//qos.durability.kind = TRANSIENT_LOCAL_DURABILITY_QOS;
	DataReader_ptr reader = subscriber->create_datareader(topic.in(),
    qos, NULL, STATUS_MASK_NONE);
	checkHandle(reader, "DDS::Subscriber::create_datareader ()");
	return reader;
}


DataReader_ptr DDSInterface::createQtControlReader(Topic_var &topic)
{
	DataReaderQos qos;
	qos.reliability.kind = RELIABLE_RELIABILITY_QOS;
	subscriber->get_default_datareader_qos(qos);
	DataReader_ptr reader = subscriber->create_datareader(topic.in(),
	qos, NULL, STATUS_MASK_NONE);
	checkHandle(reader, "DDS::Subscriber::create_datareader ()");
	return reader;
}


void DDSInterface::deleteDataReader(DataReader_ptr reader)
{
	status = subscriber->delete_datareader(reader);
	checkStatus(status, "DDS::Subscriber::delete_datareader ");
}


bool DDSInterface::InitModel(){
	 if (!FGModel::InitModel()) return false;
	return true;
}


bool DDSInterface::Run(bool Holding)
{
	if (FGModel::Run(Holding)) return true;
	if (Holding) return false;
//	if (FGModel::Run()) return true;
//	if (FDMExec->Holding()) return false; // if paused don't execute
//	publishAtitudeTopic();

	publishfdmdataTopic();
    publishTacticalAircraftDataTopic();
    publishImageGenerationData();
	readQtControlTopic();
    readQTTacticalEnvironmentTopic();
    readAutoPilotTopic();

	return false;
}

void DDSInterface::publishfdmdataTopic(){

	    fdmdata fdmdataInstance;
	    fdmdataInstance.ID = 1;

	    fdmdataInstance.Velocity_Kts = PropertyManager->GetNode()->GetDouble("velocities/vc-kts",0);
		fdmdataInstance.MachNumber = PropertyManager->GetNode()->GetDouble("velocities/mach",0);
		fdmdataInstance.GValue = PropertyManager->GetNode()->GetDouble("accelerations/Nz",0);
		fdmdataInstance.SideSlip = PropertyManager->GetNode()->GetDouble("aero/beta-deg",0);
		fdmdataInstance.Roll_deg = PropertyManager->GetNode()->GetDouble("attitude/phi-deg",0);
        fdmdataInstance.Pitch_deg = PropertyManager->GetNode()->GetDouble("attitude/theta-deg",0);
		fdmdataInstance.Heading_deg = PropertyManager->GetNode()->GetDouble("attitude/psi-deg",0);
        fdmdataInstance.Altitude_ft = PropertyManager->GetNode()->GetDouble("ElevationModel/CalculatedAGL",0);
		fdmdataInstance.VerticleVelocity_fpm = PropertyManager->GetNode()->GetDouble("velocities/v-down-fps",0)*60;
		fdmdataInstance.Latitude = PropertyManager->GetNode()->GetDouble("position/lat-gc-deg",0);
		fdmdataInstance.Longitude = PropertyManager->GetNode()->GetDouble("position/long-gc-deg",0);
		fdmdataInstance.AltitudeAboveSeaLevel_ft = PropertyManager->GetNode()->GetDouble("position/h-sl-ft",0);
		fdmdataInstance.SimTime = 12000;
		fdmdataInstance.AngleOFAttack =  PropertyManager->GetNode()->GetDouble("aero/alpha-deg",0);
		fdmdataInstance.TrueAirSpeed = PropertyManager->GetNode()->GetDouble("velocities/vtrue-kts",0);
		fdmdataInstance.GroundAirSpeed = PropertyManager->GetNode()->GetDouble("velocities/vg-fps",0)*fpstokts;  // knots
        fdmdataInstance.phidot = PropertyManager->GetNode()->GetDouble("velocities/phidot-rad_sec",0)*57.3;
        fdmdataInstance.thetadot = PropertyManager->GetNode()->GetDouble("velocities/thetadot-rad_sec",0)*57.3;
        fdmdataInstance.psidot = PropertyManager->GetNode()->GetDouble("velocities/psidot-rad_sec",0)*57.3;
        fdmdataInstance.WindDirection = PropertyManager->GetNode()->GetDouble("atmosphere/psiw-deg",0);
        fdmdataInstance.WindSpeed = PropertyManager->GetNode()->GetDouble("atmosphere/wind-mag-kts",0);
        //ElectricalSystem
        fdmdataInstance.GeneratorStatus = PropertyManager->GetNode()->GetBool("ElectricalSystem/Generator/Status",0);
        fdmdataInstance.GeneratorIndicatorLight = PropertyManager->GetNode()->GetBool("ElectricalSystem/Generator/GeneratorIndicatorLight",0);

        fdmdataInstance.ACBusIndicatorLight = PropertyManager->GetNode()->GetBool("ElectricalSystem/ACBus/ACBusIndicatorLight",0);
        fdmdataInstance.ACBusVoltage = PropertyManager->GetNode()->GetDouble("ElectricalSystem/ACBus/ACBusVoltage",0);

        fdmdataInstance.DCBusIndicatorLight = PropertyManager->GetNode()->GetBool("ElectricalSystem/DCBus/DCBusIndicatorLight",0);
        fdmdataInstance.DCBusVoltage = PropertyManager->GetNode()->GetBool("ElectricalSystem/DCBus/DCBusVoltage",0);

        fdmdataInstance.BatteryVoltage = PropertyManager->GetNode()->GetDouble("fcs/throttle-pos-norm",0)*1000;



//	    cout<<"Velocity: "<<fdmdataInstance.Velocity_Kts<<endl;
//		cout<<"Altitude: "<<fdmdataInstance.Altitude_ft<<endl;
//		cout<<"Heading: "<<fdmdataInstance.Heading_deg<<endl;
//		cout<<"Alpha: "<<fdmdataInstance.AngleOFAttack<<endl;
//	    cout<<"vel error: "<<PropertyManager->GetNode()->GetDouble("fcs/airspeed-error-lag",0)<<endl;
//	    cout<<"Vdot error: "<<PropertyManager->GetNode()->GetDouble("fcs/acceleration-error",0)<<endl;
//	    cout<<"pid: "<<PropertyManager->GetNode()->GetDouble("fcs/airspeed-hold-pid",0)<<endl;
//	    cout<<"ap throttle: "<<PropertyManager->GetNode()->GetDouble("ap/throttle-cmd-norm",0)<<endl;
		//accelerations/mag-ft-sec2
//	    cout<<"Elevator: "<<PropertyManager->GetNode()->GetDouble("fcs/elevator-pos-deg",0)<<endl;
//	    cout<<"CL: "<<PropertyManager->GetNode()->GetDouble("aero/temp/TotalCL",0)<<endl;
//	    cout<<"CD: "<<PropertyManager->GetNode()->GetDouble("aero/temp/TotalCD",0)<<endl;
//      cout<<"Phidot: "<<PropertyManager->GetNode()->GetDouble("velocities/phidot-rad_sec",0)<<endl;
//      cout<<"Thetaidot: "<<PropertyManager->GetNode()->GetDouble("velocities/thetadot-rad_sec",0)<<endl;
//      cout<<"Psidot: "<<PropertyManager->GetNode()->GetDouble("velocities/psidot-rad_sec",0)<<endl;


	    ReturnCode_t status = fdmdataWriter->write(fdmdataInstance, NULL);
	    checkStatus(status, "fdmdataWriter::write");

}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void DDSInterface::publishTacticalAircraftDataTopic()
{
//    cout<<"TA publish: "<<endl;
    TacticalAircraftsData tacticalAircraftInstance;
    tacticalAircraftInstance.ID = 1;
    string property_name,base_property_name;
    for (int i=0;i<NUMBEROFAIRCRAFTS;i++)
    {
        base_property_name = CreateIndexedPropertyName("TacticalEnvironment/TEAircraft", i);
        property_name = base_property_name + "/AircraftName";
        tacticalAircraftInstance.TEAircraftName[i] = PropertyManager->GetNode(property_name)->getStringValue();
        property_name = base_property_name + "/AircraftCreated";
        tacticalAircraftInstance.TEAircraftExists[i] = PropertyManager->GetNode()->GetBool(property_name,0);
        property_name = base_property_name + "/Velocity";
        tacticalAircraftInstance.TEAircraftVelocity[i] = PropertyManager->GetNode()->GetDouble(property_name,0);
        property_name = base_property_name + "/Heading";
        tacticalAircraftInstance.TEAircraftHeading[i] = PropertyManager->GetNode()->GetDouble(property_name,0);
        property_name = base_property_name + "/Altitude";
        tacticalAircraftInstance.TEAircraftAltitude[i] = PropertyManager->GetNode()->GetDouble(property_name,0);
        property_name = base_property_name + "/Latitude";
        tacticalAircraftInstance.TEAircraftLatitude[i] = PropertyManager->GetNode()->GetDouble(property_name,0);
        property_name = base_property_name + "/Longitude";
        tacticalAircraftInstance.TEAircraftLongitude[i] = PropertyManager->GetNode()->GetDouble(property_name,0);
        property_name = base_property_name + "/AircraftCurrentRateOfClimb";
        tacticalAircraftInstance.TEAircraftRateOfClimb[i] = PropertyManager->GetNode()->GetDouble(property_name,0);
        property_name = base_property_name + "/AircraftOnCollisionCourse";
        tacticalAircraftInstance.TEAircraftOnCollissionCourse[i] = PropertyManager->GetNode()->GetBool(property_name,0);
        property_name = base_property_name + "/AircraftCollisionTime";
        tacticalAircraftInstance.TEAircraftTimeToCollision[i] = PropertyManager->GetNode()->GetDouble(property_name,0);
    }
    ReturnCode_t status = TacticalAircraftDataWriter->write(tacticalAircraftInstance, NULL);
    checkStatus(status, "TacticalAircraftDataWriter::write");
}

void DDSInterface::publishImageGenerationData()
{
    ImageGenerationData ImageGenerationInstance;
    ImageGenerationInstance.ID = 1;

    ImageGenerationInstance.Latitude = PropertyManager->GetNode()->GetDouble("position/lat-gc-deg",0);
    ImageGenerationInstance.Longitude = PropertyManager->GetNode()->GetDouble("position/long-gc-deg",0);
    ImageGenerationInstance.AltitudeAboveSeaLevel_ft = PropertyManager->GetNode()->GetDouble("position/h-sl-ft",0);
    ImageGenerationInstance.Altitude_ft = PropertyManager->GetNode()->GetDouble("ElevationModel/CalculatedAGL",0);
    ImageGenerationInstance.SimTime = 12000;
    ImageGenerationInstance.Roll_deg = PropertyManager->GetNode()->GetDouble("attitude/phi-deg",0);
    ImageGenerationInstance.Pitch_deg = PropertyManager->GetNode()->GetDouble("attitude/theta-deg",0);
    ImageGenerationInstance.Heading_deg = PropertyManager->GetNode()->GetDouble("attitude/psi-deg",0);

    ReturnCode_t status = ImageGenerationDataWriter->write(ImageGenerationInstance,NULL);
    checkStatus(status, "ImageGenerationDataWriter::write");
}

void DDSInterface::readQtControlTopic()
{
    //cout<<"In daq: "<<endl;
	QtControlDataSeq qtControlDataList;
	SampleInfoSeq info;
	//cout<<"In daqdatatopic"<<endl;
	InstanceHandleSeq insthandleseq;
//	daqDataReader->get_matched_publications(insthandleseq);
//	cout<<"length: "<<insthandleseq.length()<<endl;
	ReturnCode_t status = QtControlDataReader->take(qtControlDataList, info, LENGTH_UNLIMITED,
			ANY_SAMPLE_STATE, ANY_VIEW_STATE, ANY_INSTANCE_STATE);
	checkStatus(status, "QtControlDataReader::take");
	if( status != RETCODE_OK) return ;
	//cout<<"DAQ Data: "<<(int)daqDataList[0].Guns<<endl;
	populateQtControlTopic(qtControlDataList[0]);
}

void DDSInterface::populateQtControlTopic(QtControlData & qtControlData)
{
	// FCS System
    PropertyManager->GetNode("propulsion/starter_cmd")->setBoolValue(qtControlData.EngineStartSwitch);
    PropertyManager->GetNode("fcs/left-brake-cmd-norm")->setDoubleValue(qtControlData.LeftBrakeCommand);
    PropertyManager->GetNode("fcs/right-brake-cmd-norm")->setDoubleValue(qtControlData.RightBrakeCommand);

    if(qtControlData.ThrottleCommand<=1000 && qtControlData.ThrottleCommand>=0){
    PropertyManager->GetNode("fcs/throttle-cmd-norm")->setDoubleValue((qtControlData.ThrottleCommand)/1000);
    //PropertyManager->GetNode("fcs/mixture-cmd-norm")->setDoubleValue((qtControlData.ThrottleCommand)/1000);
  }
    if(qtControlData.AileronCommand<=1000 && qtControlData.AileronCommand>=0){
        PropertyManager->GetNode("fcs/aileron-cmd-norm")->setDoubleValue(((qtControlData.AileronCommand)/500)-1);
    }
  if(qtControlData.ElevatorCommand<=1000 && qtControlData.ElevatorCommand>=0){
      PropertyManager->GetNode("fcs/elevator-cmd-norm")->setDoubleValue(((qtControlData.ElevatorCommand)/500)-1);
  }

if(qtControlData.RudderCommand<=1000 && qtControlData.RudderCommand>=0){
    PropertyManager->GetNode("fcs/rudder-cmd-norm")->setDoubleValue(((qtControlData.RudderCommand)/500)-1);
}

    PropertyManager->GetNode("fcs/flap-cmd-norm")->setDoubleValue(qtControlData.FlapCommand);

    PropertyManager->GetNode("ElectricalSystem/Generator/GeneratorSwitch")->setBoolValue(qtControlData.GeneratorSwitch);
    PropertyManager->GetNode("ElectricalSystem/DCBus/InverterSwitch")->setBoolValue(qtControlData.InverterSwitch);
    PropertyManager->GetNode("ElectricalSystem/Battery/BatteryStatus")->setBoolValue(qtControlData.BatteryStatus);

    //For Wind Effect
    PropertyManager->GetNode("atmosphere/wind-mag-kts")->setDoubleValue(qtControlData.WindSpeedCommand);
    PropertyManager->GetNode("atmosphere/psiw-deg")->setDoubleValue(qtControlData.WindDirectionCommand);


   // cout<<"Engine State: "<<(int)qtControlData.EngineStartSwitch<<endl;
    cout<<"Throttle Command: "<<(qtControlData.ThrottleCommand)<<endl;
   cout<<"Aileron Command: "<<(((qtControlData.AileronCommand)/500)-1)<<endl;
    cout<<"Elevator Command: "<<(((qtControlData.ElevatorCommand)/500)-1)<<endl;
    cout<<"Rudder Command: "<<(((qtControlData.RudderCommand)/500)-1)<<endl;


    //cout<<qtControlData.BatteryStatus<<endl;

}

void DDSInterface::readAutoPilotTopic()
{
    //cout<<"AutoPilot: "<<endl;
    AutoPilotDataSeq autoPilotDataList;
    SampleInfoSeq info;
    //cout<<"In daqdatatopic"<<endl;
    InstanceHandleSeq insthandleseq;
    //daqDataReader->get_matched_publications(insthandleseq);
    //cout<<"length: "<<insthandleseq.length()<<endl;
    ReturnCode_t status = AutoPilotDataReader->take(autoPilotDataList, info, LENGTH_UNLIMITED, ANY_SAMPLE_STATE, ANY_VIEW_STATE, ANY_INSTANCE_STATE);
    checkStatus(status, "AutoPilotDataReader::take");
    if( status != RETCODE_OK) return;
    //cout<<"DAQ Data: "<<(int)daqDataList[0].Guns<<endl;
    populateAutoPilotTopic(autoPilotDataList[0]);
}

void DDSInterface::populateAutoPilotTopic(AutoPilotData & autoPilotData)
{
    //FCS System
    PropertyManager->GetNode("propulsion/starter_cmd")->setBoolValue(autoPilotData.EngineStartSwitch);
    PropertyManager->GetNode("fcs/throttle-cmd-norm[0]")->setDoubleValue(autoPilotData.ThrottleCommand);
    PropertyManager->GetNode("fcs/left-brake-cmd-norm")->setDoubleValue(autoPilotData.LeftBrakeCommand);
    PropertyManager->GetNode("fcs/right-brake-cmd-norm")->setDoubleValue(autoPilotData.RightBrakeCommand);
    PropertyManager->GetNode("fcs/aileron-cmd-norm")->setDoubleValue(autoPilotData.AileronCommand);
    PropertyManager->GetNode("fcs/elevator-cmd-norm")->setDoubleValue(autoPilotData.ElevatorCommand);
    PropertyManager->GetNode("fcs/rudder-cmd-norm")->setDoubleValue(autoPilotData.RudderCommand);
    PropertyManager->GetNode("fcs/flap-cmd-norm")->setDoubleValue(autoPilotData.FlapCommand);

    //cout<<"Throttle: "<<autoPilotData.ThrottleCommand<<endl;
    //cout<<"Elevator: "<<autoPilotData.ElevatorCommand<<endl;
    //cout<<"Aileron: "<<autoPilotData.AileronCommand<<endl;
    //cout<<"Rudder: "<<autoPilotData.RudderCommand<<endl;
    //cout<<"Flap: "<<autoPilotData.FlapCommand<<endl;

}
void DDSInterface::readQTTacticalEnvironmentTopic()
{
//    cout<<"In QT TE data: "<<endl;
    QTTacticalEnvironmentDataSeq qtTacticalEnvironmentList;
    SampleInfoSeq info;
    //cout<<"In daqdatatopic"<<endl;
    InstanceHandleSeq insthandleseq;

    ReturnCode_t status = QTTacticalEnvironmentDataReader->take(qtTacticalEnvironmentList, info, LENGTH_UNLIMITED,
            ANY_SAMPLE_STATE, ANY_VIEW_STATE, ANY_INSTANCE_STATE);
    checkStatus(status, "QTTacticalEnvironmentDataReader::take");
    //cout<<"Status: "<<status<<endl;
    if( status != RETCODE_OK) return ;
    //cout<<"DAQ Data: "<<(int)daqDataList[0].Guns<<endl;
    populateQTTacticalEnvironmentTopic(qtTacticalEnvironmentList[0]);
}

void DDSInterface::populateQTTacticalEnvironmentTopic(QTTacticalEnvironmentData & qtTacticalEnvironment)
{
    string property_name,base_property_name;
    for (int i=0;i<NUMBEROFAIRCRAFTS;i++)
    {
        base_property_name = CreateIndexedPropertyName("TacticalEnvironment/TEAircraft", i);
        property_name = base_property_name + "/CreateNewAircraft";
        PropertyManager->GetNode(property_name)->setBoolValue(qtTacticalEnvironment.CreatAircraft[i]);
        property_name = base_property_name + "/AircraftName";
        PropertyManager->GetNode(property_name)->setStringValue(qtTacticalEnvironment.TEAircraftName[i]);
        property_name = base_property_name + "/Velocity";
        PropertyManager->GetNode(property_name)->setDoubleValue(qtTacticalEnvironment.TEAircraftVelocity[i]);
        property_name = base_property_name + "/TotalNumberOfPoints";
        PropertyManager->GetNode(property_name)->setIntValue(qtTacticalEnvironment.TEAircraftTotalNumberOfPoints[i]);
        property_name = base_property_name + "/AircraftRateOfClimbExternal";
        PropertyManager->GetNode(property_name)->setDoubleValue(qtTacticalEnvironment.TEAircraftRateOfClimb[i]);
        property_name = base_property_name + "/AircraftRateOFTurn";
        PropertyManager->GetNode(property_name)->setDoubleValue(qtTacticalEnvironment.TEAircraftRateOFTurn[i]);
    }


    for (int i=0;i<NUMBEROFAIRCRAFTS;i++)
    {
        base_property_name = CreateIndexedPropertyName("TacticalEnvironment/TEAircraft", i);
        property_name = base_property_name + "/TotalNumberOfPointsPrevious";

        for (int j=0;j<NUMBEROFAIRCRAFTPATH;j++)
        {
            base_property_name = CreateIndexedPropertyName("TacticalEnvironment/TEAircraft/Path", i,j);
            property_name = base_property_name + "/Latitude";
            PropertyManager->GetNode(property_name)->setDoubleValue(qtTacticalEnvironment.TEAircraftPathLatitude[i][j]);
            property_name = base_property_name + "/Longitude";
            PropertyManager->GetNode(property_name)->setDoubleValue(qtTacticalEnvironment.TEAircraftPathLongitude[i][j]);
            property_name = base_property_name + "/Altitude";
            PropertyManager->GetNode(property_name)->setDoubleValue(qtTacticalEnvironment.TEAircraftPathAltitude[i][j]);
            property_name = base_property_name + "/Heading";
            PropertyManager->GetNode(property_name)->setDoubleValue(qtTacticalEnvironment.TEAircraftPathHeading[i][j]);
        }
    }

}

DDSInterface::~DDSInterface() {
	//mgr->deleteWriter();
	deletePublisher();
	deleteSubscriber();
	//mgr->deleteTopic();
	deleteParticipant();
	//delete mgr;
}



} /* namespace JSBSim */
