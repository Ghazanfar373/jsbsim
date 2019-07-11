
#include "FGFDMExec.h"
#include "TacticalEnvironment.h"


using namespace std;
namespace JSBSim{
TacticalEnvironment::TacticalEnvironment(FGFDMExec *fdmex):FGModel(fdmex)
{
    DeltaTime = 0.0;
    NumberOfAircrafts = 0;
}

bool TacticalEnvironment::InitModel()
{
    CurrentLatitude = 0.0;
    CurrentLongitude = 0.0;
    CurrentHeading = 0.0;
    CurrentAltitude = 0.0;
    CurrentVelocity = 0.0;
    CurrentRateOfClimb =0.0;
    //Initialize Current aircraft data
    for (int i=0;i<NUMBEROFAIRCRAFTS;i++)
    {
        InitializeAircraft(i);
    }
    bind();
    return true;
}

void TacticalEnvironment::InitializeAircraft(int aircraftumber)
{
    AircraftCurrentLatitude[aircraftumber] = 0.0;
    AircraftCurrentLongitude[aircraftumber] = 0.0;
    AircraftCurrentAltitude[aircraftumber] = 0.0;
    AircraftCurrentHeading[aircraftumber] = 0.0;
    AircraftCurrentVelocity[aircraftumber] = 0.0;
    AircraftTargetHeading[aircraftumber] = 0.0;
    AircraftName[aircraftumber] = "Not created";
    CreateNewAircraft[aircraftumber] = false;
    AircraftCreated[aircraftumber] = false;
    AircraftEffective[aircraftumber] = false;
    TotalNumberOfPoints[aircraftumber] = 0;
    TotalNumberOfPointsPrevious[aircraftumber] = 0;
    AircraftRateOfClimbExternal[aircraftumber] = 10000;
    AircraftRateOFTurn[aircraftumber] = 360*2;
    AircraftIntersectionLatitude[aircraftumber] = 0.0;
    AircraftIntersectionLongitude[aircraftumber] = 0.0;
    AircraftIntersectionAltitude[aircraftumber] = 0.0;
    AircraftOnCollisionCourse[aircraftumber] = false;
    AircraftCollisionTime[aircraftumber] = 0.0;
    AircraftPreviousAltitude[aircraftumber] = 0.0;
    AircraftCurrentRateOfClimb[aircraftumber] = 0.0;
    for (int j=0;j<NUMBEROFAIRCRAFTPATH;j++)
    {
        AircraftPathLatitude[aircraftumber][j] = 0.0;
        AircraftPathLongitude[aircraftumber][j] = 0.0;
        AircraftPathAltitude[aircraftumber][j] = 0.0;
        AircraftPathHeading[aircraftumber][j] = 0.0;
    }
}
void TacticalEnvironment::UpdateMiscellaneous()
{
    DeltaTime = PropertyManager->GetNode()->GetDouble("simulation/deltaTime",0);
    CurrentLatitude = PropertyManager->GetNode()->GetDouble("position/lat-gc-deg",0);
    CurrentLongitude = PropertyManager->GetNode()->GetDouble("position/long-gc-deg",0);
    CurrentAltitude = PropertyManager->GetNode()->GetDouble("position/h-sl-ft",0);
    CurrentHeading = PropertyManager->GetNode()->GetDouble("attitude/psi-deg",0);
    CurrentVelocity = PropertyManager->GetNode()->GetDouble("velocities/vc-kts",0);
    CurrentRateOfClimb = PropertyManager->GetNode()->GetDouble("velocities/v-down-fpm",0);
}


bool TacticalEnvironment::Run(bool Holding)
{
    if (FGModel::Run(Holding)) return true;  // Fast return if we have nothing to do ...
    if (Holding) return false;
    UpdateMiscellaneous();

    for (int i=0;i<NUMBEROFAIRCRAFTS;i++)
    {
        if (CreateNewAircraft[i])
        {
            AddNewAircraft(i);
        }
        else
        {
            DeleteAircraft(i);
        }
        if (AircraftCreated[i])
        {
            UpdateTEAircraftPosition(i);
        }
        TotalNumberOfPointsPrevious[i] = TotalNumberOfPoints[i];
    }
    UpdateTEAircraftCurrentLocation();

//	double tempLat = 33.702754*degtorad;
//	double tempLong = 73.294800*degtorad;
//	double vel = 200;
//	double dist = 5*NMTOMT;
//	double temprelHead = 0;
//	double targetHead = 270;
//	DestinationPointAlongGreatCircle(tempLat,tempLong,targetHead,dist,tempLat,tempLong,temprelHead);
//	cout<<"LAt: "<<tempLat*radtodeg<<endl;
//	cout<<"Long: "<<tempLong*radtodeg<<endl;
    //UpdateTEAircraftPosition(NewAircraft);
    //cout<<"Lat: "<<PropertyManager->GetNode()->GetDouble("TacticalEnvironment/TEAircraft/Path[0][0]/Latitude")<<endl;
}

void TacticalEnvironment::AddNewAircraft(int aircraftnumber)
{
    if (!AircraftCreated[aircraftnumber])
    {
        TEAircraftsArray[aircraftnumber] = new TEAircraft();
        AircraftCreated[aircraftnumber] = true;
        //AircraftCurrentAltitude[aircraftnumber] =
        NumberOfAircrafts++;
    }
    if (AircraftCreated[aircraftnumber])
    {
        UpdateAircraftData(aircraftnumber);
    }


}

void TacticalEnvironment::DeleteAircraft(int aircraftnumber)
{

    if (AircraftCreated[aircraftnumber])
    {
        delete TEAircraftsArray[aircraftnumber];
        NumberOfAircrafts--;
        InitializeAircraft(aircraftnumber);
    }

}
void TacticalEnvironment::UpdateAircraftData(int aircraftnumber)
{
    TEAircraftsArray[aircraftnumber]->SetAircraftName(AircraftName[aircraftnumber]);
    TEAircraftsArray[aircraftnumber]->SetAircraftVelocity(AircraftCurrentVelocity[aircraftnumber]);
    TEAircraftsArray[aircraftnumber]->SetTotalNumberOfPoints(TotalNumberOfPoints[aircraftnumber]);
    Location aircraftpath[NUMBEROFAIRCRAFTPATH];
    for (int i=0;i<TotalNumberOfPoints[aircraftnumber];i++)
    {
        aircraftpath[i].Latitude = AircraftPathLatitude[aircraftnumber][i];
        aircraftpath[i].Longitude = AircraftPathLongitude[aircraftnumber][i];
        aircraftpath[i].Altitude = AircraftPathAltitude[aircraftnumber][i];
        aircraftpath[i].Heading = AircraftPathHeading[aircraftnumber][i];
        TEAircraftsArray[aircraftnumber]->SetAircraftPathLocation(aircraftpath[i],i);
    }
    if (!AircraftEffective[aircraftnumber])
    {
        if (TEAircraftsArray[aircraftnumber]->GetTotalNumberOfPoints() == 1)
        {
            AircraftCurrentAltitude[aircraftnumber] = TEAircraftsArray[aircraftnumber]->GetAircraftPathLocation(0).Altitude;
        }
        else
        {
            AircraftCurrentAltitude[aircraftnumber] = TEAircraftsArray[aircraftnumber]->GetAircraftPathLocation(1).Altitude;
        }

    }
    AircraftEffective[aircraftnumber] = AircraftCreated[aircraftnumber];
}

void TacticalEnvironment::UpdateTEAircraftPosition(int aircraftnumber)
{
    Location currentLocation = TEAircraftsArray[aircraftnumber]->GetCurrentLocation();
    Location aircraftPath[NUMBEROFAIRCRAFTPATH];
    for (int i=0;i<TotalNumberOfPoints[aircraftnumber];i++)
    {
        aircraftPath[i] = TEAircraftsArray[aircraftnumber]->GetAircraftPathLocation(i);
    }

    bool turnToNextPathFlag = TEAircraftsArray[aircraftnumber]->GetTurnToNextPathFlag();
    int aircraftPathNumber = TEAircraftsArray[aircraftnumber]->GetAircraftPathNumber();
    double destinationLat = 0.0;
    double destinationLong = 0.0;
    double destinationAlt = 0.0;
    double destinationHeading = 0.0;
    double targetHeading = 0.0;
    double relativeHeading = 0.0;
    double distanceRemaining = 0.0;


    if (currentLocation.Latitude == 0 && currentLocation.Longitude == 0)
    {
        currentLocation = aircraftPath[0];
    }
    double currentLat = currentLocation.Latitude*degtorad;
    double currentLong = currentLocation.Longitude*degtorad;
    double currentVelocity = TEAircraftsArray[aircraftnumber]->GetAircraftVelocity()*NMTOMT/(60*60);  // knots to meter per sec
    double currentHeading = currentLocation.Heading*degtorad;
    double distanceTravelledPerIteration = currentVelocity*DeltaTime;

    //
    if (TotalNumberOfPoints[aircraftnumber] == 1)
    {
        AircraftCurrentAltitude[aircraftnumber] = Seek(&AircraftCurrentAltitude[aircraftnumber],aircraftPath[0].Altitude,
                AircraftRateOfClimbExternal[aircraftnumber]/60,AircraftRateOfClimbExternal[aircraftnumber]/60);
        targetHeading = aircraftPath[0].Heading*degtorad;
//			AircraftTargetHeading[aircraftnumber] = Seek(&AircraftTargetHeading[aircraftnumber],targetHeading,10*degtorad,10*degtorad);
        CalculateRequiredTargetHeading(targetHeading,aircraftnumber);
        DestinationPointAlongGreatCircle(currentLat,currentLong,AircraftTargetHeading[aircraftnumber],distanceTravelledPerIteration,
                    currentLat,currentLong,relativeHeading);
    }
    //
    else
    {
        destinationLat = aircraftPath[aircraftPathNumber].Latitude*degtorad;
        destinationLong = aircraftPath[aircraftPathNumber].Longitude*degtorad;
        AircraftCurrentAltitude[aircraftnumber] = Seek(&AircraftCurrentAltitude[aircraftnumber],aircraftPath[aircraftPathNumber].Altitude,
                AircraftRateOfClimbExternal[aircraftnumber]/60,AircraftRateOfClimbExternal[aircraftnumber]/60);
        destinationHeading = aircraftPath[aircraftPathNumber].Heading*degtorad;
        targetHeading = HeadingCalculation(currentLat,currentLong,destinationLat,destinationLong)*degtorad;
        CalculateRequiredTargetHeading(targetHeading,aircraftnumber);
        DestinationPointAlongGreatCircle(currentLat,currentLong,AircraftTargetHeading[aircraftnumber],distanceTravelledPerIteration,
                currentLat,currentLong,relativeHeading);
        distanceRemaining = RangeCalculation(currentLat,currentLong,destinationLat,destinationLong);

        if (distanceRemaining <= 15)
        {
            TEAircraftsArray[aircraftnumber]->SetTurnToNextPathFlag(true);
        }
        else
        {
            TEAircraftsArray[aircraftnumber]->SetTurnToNextPathFlag(false);
        }
        if (TEAircraftsArray[aircraftnumber]->GetTurnToNextPathFlag())
        {
            if (TEAircraftsArray[aircraftnumber]->GetAircraftPathNumber() == (TEAircraftsArray[aircraftnumber]->GetTotalNumberOfPoints()-1))
            {
                TEAircraftsArray[aircraftnumber]->SetAircraftPathNumber(0);
            }
            else
            {
                TEAircraftsArray[aircraftnumber]->SetAircraftPathNumber(TEAircraftsArray[aircraftnumber]->GetAircraftPathNumber()+1);
            }
        }
    }

    currentLocation.Latitude = currentLat*radtodeg;
    currentLocation.Longitude = currentLong*radtodeg;
    currentLocation.Heading = AircraftTargetHeading[aircraftnumber]*radtodeg;
    currentLocation.Altitude = AircraftCurrentAltitude[aircraftnumber];

    TEAircraftsArray[aircraftnumber]->SetCurrentLocation(currentLocation);
    CalculateRateOfClimb(aircraftnumber);
    // Calculate intersection with aircraft
    GreatCircleIntersectionPoint(CurrentLatitude,CurrentLongitude,CurrentHeading,AircraftCurrentLatitude[aircraftnumber],AircraftCurrentLongitude[aircraftnumber],
            AircraftCurrentHeading[aircraftnumber],AircraftIntersectionLatitude[aircraftnumber],AircraftIntersectionLongitude[aircraftnumber]);
    DetectCollision(aircraftnumber);

}



double TacticalEnvironment::CalculateRequiredTargetHeading(double targetHeading, int aircraftnumber)
{
    double rateofturn = AircraftRateOFTurn[aircraftnumber]/60;
    if ((AircraftTargetHeading[aircraftnumber]*radtodeg - targetHeading*radtodeg) > 180
             || (AircraftTargetHeading[aircraftnumber]*radtodeg - targetHeading*radtodeg) < -180)
    {
        AircraftTargetHeading[aircraftnumber] = Seek(&AircraftTargetHeading[aircraftnumber],targetHeading,-rateofturn*degtorad,-rateofturn*degtorad);
        if (AircraftTargetHeading[aircraftnumber]*radtodeg < 0)
        {
            AircraftTargetHeading[aircraftnumber] = 360*degtorad + AircraftTargetHeading[aircraftnumber];
        }
        else if (AircraftTargetHeading[aircraftnumber]*radtodeg > 360)
        {
            AircraftTargetHeading[aircraftnumber] =AircraftTargetHeading[aircraftnumber] -  360*degtorad ;
        }
    }
    else
    {
        AircraftTargetHeading[aircraftnumber] = Seek(&AircraftTargetHeading[aircraftnumber],targetHeading,rateofturn*degtorad,rateofturn*degtorad);
        if (AircraftTargetHeading[aircraftnumber]*radtodeg < 0)
        {
            AircraftTargetHeading[aircraftnumber] = 360*degtorad + AircraftTargetHeading[aircraftnumber];
        }
        else if (AircraftTargetHeading[aircraftnumber]*radtodeg > 360)
        {
            AircraftTargetHeading[aircraftnumber] =AircraftTargetHeading[aircraftnumber] -  360*degtorad ;
        }
    }

    return AircraftTargetHeading[aircraftnumber];
}

//
void TacticalEnvironment::UpdateTEAircraftCurrentLocation()
{
    for (int i=0;i<NUMBEROFAIRCRAFTS;i++)
    {
        if (AircraftCreated[i])
        {
            AircraftCurrentLatitude[i] = TEAircraftsArray[i]->GetCurrentLocation().Latitude;
            AircraftCurrentLongitude[i] = TEAircraftsArray[i]->GetCurrentLocation().Longitude;
            AircraftCurrentAltitude[i] = TEAircraftsArray[i]->GetCurrentLocation().Altitude;
            AircraftCurrentHeading[i] = TEAircraftsArray[i]->GetCurrentLocation().Heading;
        }
    }
}

// return in meters
double TacticalEnvironment::RangeCalculation(double lat1,double long1,double lat2,double long2){

    double deltaLatitude = lat2 - lat1;
    double 	deltaLongitude = long2 - long1;
    double d1 = (sin((deltaLatitude/2)))*(sin((deltaLatitude/2))) + (cos(lat1))*(cos(lat2))*(sin((deltaLongitude/2)))*(sin((deltaLongitude/2)));

    double d2 = 2*atan2(sqrt(d1),sqrt(1-d1));

    return 6378137.0*d2;
}
// return in degrees
double TacticalEnvironment::HeadingCalculation(double lat1,double long1,double lat2,double long2){

    double 	deltaLongitude = long2 - long1;
    double theta = atan2(sin(deltaLongitude)*cos(lat2),cos(lat1)*sin(lat2)-sin(lat1)*cos(lat2)*cos(deltaLongitude));
    return (int)((theta*(180/M_PI))+360)%360;

}

void TacticalEnvironment::DestinationPointAlongGreatCircle(double lat,double lng, double brng, double dist,
                                double &lat2,double &lng2, double &brng2){
    lat2 = asin( sin(lat)*cos(dist/EARTH_RADIUS) + cos(lat)*sin(dist/EARTH_RADIUS)*cos(brng) );
    lng2 = lng + atan2(sin(brng)*sin(dist/EARTH_RADIUS)*cos(lat),cos(dist/EARTH_RADIUS)-sin(lat)*sin(lat2));
    brng2 = HeadingCalculation(lat2,lng2,lat,lng);
}

void TacticalEnvironment::GreatCircleIntersectionPoint(double lat1,double lng1,double theta1,double lat2,double lng2,double theta2,
                 double &lat, double &lng)
{
    lat1 = lat1*degtorad;
    lng1 = lng1*degtorad;
    theta1 = theta1*degtorad;
    lat2 = lat2*degtorad;
    lng2 = lng2*degtorad;
    theta2 = theta2*degtorad;
    double d12,d13;
    double deltaLat = lat2 - lat1;
    double deltaLong = lng2 - lng1;
    double theta12;
    double theta21;
    double alpha1,alpha2,alpha3,theta3,deltaLamda13;
    double brngA,brngB;


    d12 = 2*asin(sqrt(sin(deltaLat/2)*sin(deltaLat/2)+cos(lat1)*cos(lat2)*sin(deltaLong/2)*sin(deltaLong/2)));
    brngA = acos((sin(lat2)-sin(lat1)*cos(d12))/(sin(d12)*cos(lat1)));
    if (isnan(brngA)) brngA = 0;
    brngB = acos((sin(lat1)-sin(lat2)*cos(d12))/(sin(d12)*cos(lat2)));
    if (isnan(brngB)) brngB = 0;

    if (sin(deltaLong) > 0)
    {
        theta12 = brngA;
        theta21 = 2*M_PI - brngB;
    }
    else
    {
        theta12 = 2*M_PI - brngA;
        theta21 = brngB;
    }
    alpha1 = fmod(theta1 -theta12 + M_PI,2*M_PI) - M_PI;
    alpha2 = fmod(theta21 - theta2 + M_PI,2*M_PI) - M_PI;
    if ((sin(alpha1) == 0 && sin(alpha2) == 0) ||(sin(alpha1)*sin(alpha2)<0)) return;

    alpha3 = acos(-cos(alpha1)*cos(alpha2) + sin(alpha1)*sin(alpha2)*cos(d12));
    d13 = atan2(sin(d12)*sin(alpha1)*sin(alpha2),cos(alpha2)+cos(alpha1)*cos(alpha3));
    lat = (asin(sin(lat1)*cos(d13) + cos(lat1)*sin(d13)*cos(theta1)))*radtodeg;
    deltaLamda13 = atan2(sin(theta1)*sin(d13)*cos(lat1),cos(d13)-sin(lat1)*sin(lat));
    lng = (fmod(lng1 + deltaLamda13 + M_PI,2*M_PI) - M_PI)*radtodeg;
}

void TacticalEnvironment::DetectCollision(int aircraftnumber)
{
    double distanceFromRefAircraft = 0.0;
    double distanceFromTEAircraft = 0.0;
    double timeToReachIntsRefAircraft = 0.0;
    double timeToReachIntsTEAircraft = 0.0;
    double refAircraftVelocity = CurrentVelocity*ktstomps;
    double teAircraftVelocity = AircraftCurrentVelocity[aircraftnumber]*ktstomps;
    double refAircraftInstAltitude = 0.0;
    double teAircraftInstAltitude = 0.0;

    distanceFromRefAircraft = RangeCalculation(CurrentLatitude*degtorad,CurrentLongitude*degtorad,AircraftIntersectionLatitude[aircraftnumber]*degtorad,
            AircraftIntersectionLongitude[aircraftnumber]*degtorad);
    distanceFromTEAircraft = RangeCalculation(AircraftCurrentLatitude[aircraftnumber]*degtorad,AircraftCurrentLongitude[aircraftnumber]*degtorad,
            AircraftIntersectionLatitude[aircraftnumber]*degtorad,AircraftIntersectionLongitude[aircraftnumber]*degtorad);

    if (refAircraftVelocity !=0)
    {
        timeToReachIntsRefAircraft = distanceFromRefAircraft/refAircraftVelocity;
    }
    if (teAircraftVelocity !=0)
    {
        timeToReachIntsTEAircraft = distanceFromTEAircraft/teAircraftVelocity;
    }

    if (fabs(timeToReachIntsRefAircraft - timeToReachIntsTEAircraft) > 3)
    {
        AircraftOnCollisionCourse[aircraftnumber] = false;
        AircraftCollisionTime[aircraftnumber] = 0.0;
        return;
    }
    else
    {
        refAircraftInstAltitude = CurrentAltitude - ((CurrentRateOfClimb/60)*timeToReachIntsRefAircraft);
        teAircraftInstAltitude = AircraftCurrentAltitude[aircraftnumber] - (AircraftCurrentRateOfClimb[aircraftnumber]/60*timeToReachIntsRefAircraft);
        if (fabs(refAircraftInstAltitude - teAircraftInstAltitude) < 15)
        {
            AircraftOnCollisionCourse[aircraftnumber] = true;
            AircraftCollisionTime[aircraftnumber] = timeToReachIntsRefAircraft;
        }
        else
        {
            AircraftOnCollisionCourse[aircraftnumber] = false;
            AircraftCollisionTime[aircraftnumber] = 0.0;
        }
    }


}

void TacticalEnvironment::CalculateRateOfClimb(int aircraftnumber)
{
    double deltaAltitude = AircraftPreviousAltitude[aircraftnumber] - AircraftCurrentAltitude[aircraftnumber];
    AircraftCurrentRateOfClimb[aircraftnumber] = (deltaAltitude/DeltaTime)*60;
    AircraftPreviousAltitude[aircraftnumber] = AircraftCurrentAltitude[aircraftnumber];

}

void TacticalEnvironment::TieNewAircraftPath(int aircraftNumber)
{
    string property_name,base_property_name;
    // Aircraft Path Data
    for (int j=TotalNumberOfPointsPrevious[aircraftNumber];j<TotalNumberOfPoints[aircraftNumber];j++)
    {
        base_property_name = CreateIndexedPropertyName("TacticalEnvironment/TEAircraft/Path", aircraftNumber,j);
        property_name = base_property_name + "/Latitude";
        PropertyManager->Tie( property_name.c_str(), &AircraftPathLatitude[aircraftNumber][j]);
        property_name = base_property_name + "/Longitude";
        PropertyManager->Tie( property_name.c_str(), &AircraftPathLongitude[aircraftNumber][j]);
        property_name = base_property_name + "/Altitude";
        PropertyManager->Tie( property_name.c_str(), &AircraftPathAltitude[aircraftNumber][j]);
        property_name = base_property_name + "/Heading";
        PropertyManager->Tie( property_name.c_str(), &AircraftPathHeading[aircraftNumber][j]);
    }

}

void TacticalEnvironment::UnTieNewAircraftPath(int aircraftNumber)
{
    string property_name,base_property_name;

    for (int j=TotalNumberOfPoints[aircraftNumber];j<TotalNumberOfPointsPrevious[aircraftNumber];j++)
    {
        base_property_name = CreateIndexedPropertyName("TacticalEnvironment/TEAircraft/Path", aircraftNumber,j);
        property_name = base_property_name + "/Latitude";
        PropertyManager->Untie( property_name.c_str());
        property_name = base_property_name + "/Longitude";
        PropertyManager->Untie( property_name.c_str());
        property_name = base_property_name + "/Altitude";
        PropertyManager->Untie( property_name.c_str());
        property_name = base_property_name + "/Heading";
        PropertyManager->Untie( property_name.c_str());
    }


}
double TacticalEnvironment::Seek(double* var, double target, double accel, double decel)
{
    double v = *var;
      if (v > target) {
        v -= DeltaTime * decel;
        if (v < target) v = target;
      } else if (v < target) {
        v += DeltaTime * accel;
        if (v > target) v = target;
      }
      return v;
}

void TacticalEnvironment::bind()
{
    string property_name,base_property_name;
    //Aircraft Current Data
    for (int i=0; i<NUMBEROFAIRCRAFTS; i++)
    {
        base_property_name = CreateIndexedPropertyName("TacticalEnvironment/TEAircraft", i);
        property_name = base_property_name + "/Latitude";
        PropertyManager->Tie( property_name.c_str(), &AircraftCurrentLatitude[i]);
        property_name = base_property_name + "/Longitude";
        PropertyManager->Tie( property_name.c_str(), &AircraftCurrentLongitude[i]);
        property_name = base_property_name + "/Altitude";
        PropertyManager->Tie( property_name.c_str(), &AircraftCurrentAltitude[i]);
        property_name = base_property_name + "/Velocity";
        PropertyManager->Tie( property_name.c_str(), &AircraftCurrentVelocity[i]);
        property_name = base_property_name + "/Heading";
        PropertyManager->Tie( property_name.c_str(), &AircraftCurrentHeading[i]);
        property_name = base_property_name + "/AircraftCurrentRateOfClimb";
        PropertyManager->Tie( property_name.c_str(), &AircraftCurrentRateOfClimb[i]);
        property_name = base_property_name + "/AircraftName";
        PropertyManager->Tie( property_name.c_str(), &AircraftName[i]);
        property_name = base_property_name + "/CreateNewAircraft";
        PropertyManager->Tie( property_name.c_str(), &CreateNewAircraft[i]);
        property_name = base_property_name + "/AircraftCreated";
        PropertyManager->Tie( property_name.c_str(), &AircraftCreated[i]);
        property_name = base_property_name + "/TotalNumberOfPoints";
        PropertyManager->Tie( property_name.c_str(), &TotalNumberOfPoints[i]);
        property_name = base_property_name + "/TotalNumberOfPointsPrevious";
        PropertyManager->Tie( property_name.c_str(), &TotalNumberOfPointsPrevious[i]);
        property_name = base_property_name + "/AircraftRateOfClimbExternal";
        PropertyManager->Tie( property_name.c_str(), &AircraftRateOfClimbExternal[i]);
        property_name = base_property_name + "/AircraftRateOFTurn";
        PropertyManager->Tie( property_name.c_str(), &AircraftRateOFTurn[i]);
        property_name = base_property_name + "/AircraftCollisionTime";
        PropertyManager->Tie( property_name.c_str(), &AircraftCollisionTime[i]);
        property_name = base_property_name + "/AircraftOnCollisionCourse";
        PropertyManager->Tie( property_name.c_str(), &AircraftOnCollisionCourse[i]);

    }
    // Aircraft Path Data
    for (int i=0;i<NUMBEROFAIRCRAFTS;i++)
    {
        for (int j=0;j<NUMBEROFAIRCRAFTPATH;j++)
        {
            base_property_name = CreateIndexedPropertyName("TacticalEnvironment/TEAircraft/Path", i,j);
            property_name = base_property_name + "/Latitude";
            PropertyManager->Tie( property_name.c_str(), &AircraftPathLatitude[i][j]);
            property_name = base_property_name + "/Longitude";
            PropertyManager->Tie( property_name.c_str(), &AircraftPathLongitude[i][j]);
            property_name = base_property_name + "/Altitude";
            PropertyManager->Tie( property_name.c_str(), &AircraftPathAltitude[i][j]);
            property_name = base_property_name + "/Heading";
            PropertyManager->Tie( property_name.c_str(), &AircraftPathHeading[i][j]);
        }
    }

}

TacticalEnvironment::~TacticalEnvironment() {
    // TODO Auto-generated destructor stub
}

}

