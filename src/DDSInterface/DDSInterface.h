/*
 * DDSInterface.h
 *
 *  Created on: Nov 8, 2012
 *      Author: sim-paf
 */

#ifndef DDSINTERFACE_H_
#define DDSINTERFACE_H_

#include "FGFDMExec.h"
#include "FDMDcps_impl.h"
#include "QTControlDcps_impl.h"
#include "ccpp_dds_dcps.h"
#include "CheckStatus.h"
#include "QTTactEnvironmentDcps_impl.h"
#include "TacticalAircraftsDcps_impl.h"
#include "ImageGenerationDcps_impl.h"
#include "AutoPilotDcps_impl.h"

using namespace DDS;
using namespace FDM;
using namespace QTControl;
using namespace QTTacticalEnvironment;
using namespace TacticalAircrafts;
using namespace ImageGeneration;
using namespace AutoPilot;


namespace JSBSim {


class DDSInterface: public FGModel {
public:
	DDSInterface(FGFDMExec*);
	DDSInterface();

	bool InitModel();
	bool Run(bool holding);
    bool InitRun();
	virtual ~DDSInterface();
	void publishDaqDataTopic();

	bool AllDoneFromIos;
	bool QuickStart;
	bool QuitFromIOS;

private:

	//DDSEntityManager *mgr;
	DomainParticipantFactory_var dpf;
	DomainParticipant_var participant;

	Publisher_var publisher;
	Subscriber_var subscriber;

	/* QosPolicy holders */
	TopicQos reliable_topic_qos;
	TopicQos setting_topic_qos;
	PublisherQos pub_qos;
	DataWriterQos dw_qos;
	SubscriberQos sub_qos;

	DataWriter_ptr createDataWriter(bool autodispose_unregistered_instances, Topic_var &topic);



	Topic_var fdmdataTopic;
	fdmdataTypeSupport_var fdmdataType;
	fdmdataDataWriter_var fdmdataWriter;

    Topic_var TacticalAircraftsDataTopic;
    TacticalAircraftsDataTypeSupport_var TacticalAircraftsDataType;
    TacticalAircraftsDataDataWriter_var TacticalAircraftDataWriter;

	Topic_var QtControlDataTopic;
	QtControlDataTypeSupport_var QtControlDataType;
	QtControlDataDataReader_var QtControlDataReader;

    Topic_var QTTacticalEnvironmentDataTopic;
    QTTacticalEnvironmentDataTypeSupport_var QTTacticalEnvironmentDataType;
    QTTacticalEnvironmentDataDataReader_var QTTacticalEnvironmentDataReader;

    Topic_var ImageGenerationDataTopic;
    ImageGenerationDataTypeSupport_var ImageGenerationDataType;
    ImageGenerationDataDataWriter_var ImageGenerationDataWriter;

    Topic_var AutoPilotDataTopic;
    AutoPilotDataTypeSupport_var AutoPilotDataType;
    AutoPilotDataDataReader_var AutoPilotDataReader;


	ReturnCode_t status;

	CORBA::String_var partition;

	void createParticipant(const char *, const char *);
	void deleteParticipant();
	void createTopic(TypeSupport *ts, char *topicName, Topic_var &topic);
	void createPublisher();
	void deletePublisher();
	void createSubscriber();
	void deleteSubscriber();


	void createDataWriter(bool autodispose_unregistered_instances, DataWriter_ptr writer, Topic_var &topic);
	void deleteDataWriter(DataWriter_ptr writer);

	DataReader_ptr createDataReader(Topic_var &topic);
	DataReader_ptr createQtControlReader(Topic_var &topic);


	void deleteDataReader(DataReader_ptr reader);


	void publishfdmdataTopic();
    void publishTacticalAircraftDataTopic();
    void publishImageGenerationData();
	void readfdmdataTopic();

	void readQtControlTopic();
	void populateQtControlTopic(QtControlData & qtControlData);

    void readQTTacticalEnvironmentTopic();
    void populateQTTacticalEnvironmentTopic(QTTacticalEnvironmentData & qtTacticalEnvironment);

    void readAutoPilotTopic();
    void populateAutoPilotTopic(AutoPilotData & autoPilotData);

};

} /* namespace JSBSim */
#endif /* DDSINTERFACE_H_ */
