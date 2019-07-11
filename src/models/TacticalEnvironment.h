/*
 * Added on 18-11-2014 for Tactical Environment generation
 */
#ifndef TACTICALENVIRONMENT_H_
#define TACTICALENVIRONMENT_H_


#include "FGFDMExec.h"
#include "math.h"
#include <string.h>
#include "FGModel.h"
#include "TacticalEnvironment/TacticalAircraft.h"


using namespace std;

#define NMTOFT 6076.12
#define FTTONM 1/NMTOFT
#define NMTOMT 1852
#define MTTONM 1/NMTOMT
#define FTTOMT 0.3
#define MTTOFT 1/FTTOMT

#define EARTH_RADIUS 6378137.0  // earth radius in meters
const int NUMBEROFAIRCRAFTS = 5;


namespace JSBSim{


class TacticalEnvironment:public FGModel {

public:

    TacticalEnvironment(FGFDMExec*);
    bool InitModel(void);
    void UpdateMiscellaneous();
    bool Run(bool Holding);
    void bind(void);
    ~TacticalEnvironment();
    void AddNewAircraft(int aircraftnumber);
    void DeleteAircraft(int aircraftnumber);
    void UpdateAircraftData(int aircraftnumber);
    void InitializeAircraft(int aircraftnumber);

    //return in meters
    double RangeCalculation(double lat1,double long1,double lat2,double long2);
    // return in degrees
    double HeadingCalculation(double lat1,double long1,double lat2,double long2);
    //Calculate the Destination Point and Final Bearing
    void DestinationPointAlongGreatCircle(double lat,double lng, double brng, double dist,
                                        double &lat2,double &lng2, double &brng2);
    void GreatCircleIntersectionPoint(double lat1,double lng1,double bearing1,double lat2,double lng2,double bearing2,
                 double &lat, double &lng);
    void DetectCollision(int aircraftnumber);

    void UpdateTEAircraftPosition(int aircraftnumber);
    void UpdateTEAircraftCurrentLocation();
    void TieNewAircraftPath(int aircraftNumber);
    void UnTieNewAircraftPath(int aircraftNumber);
    double CalculateRequiredTargetHeading(double targetHeading,int aircraftnumber);
    void CalculateRateOfClimb(int aircraftnumber);
    double Seek(double* var, double target, double accel, double decel);

private:

    double DeltaTime;
    // Aircraft Parameters
    double CurrentLatitude;
    double CurrentLongitude;
    double CurrentHeading;
    double CurrentAltitude;
    double CurrentVelocity;
    double CurrentRateOfClimb;
    //std::vector <TEAircraft*>   TEAircrafts;
    TEAircraft* TEAircraftsArray[NUMBEROFAIRCRAFTS];
    int NumberOfAircrafts;
    bool CreateNewAircraft[NUMBEROFAIRCRAFTS];
    bool AircraftCreated[NUMBEROFAIRCRAFTS];
    bool AircraftEffective[NUMBEROFAIRCRAFTS];
    // Aircraft Current Location data
    double AircraftCurrentLatitude[NUMBEROFAIRCRAFTS];
    double AircraftCurrentLongitude[NUMBEROFAIRCRAFTS];
    double AircraftCurrentAltitude[NUMBEROFAIRCRAFTS];
    double AircraftPreviousAltitude[NUMBEROFAIRCRAFTS];
    double AircraftCurrentHeading[NUMBEROFAIRCRAFTS];
    double AircraftCurrentVelocity[NUMBEROFAIRCRAFTS];
    double AircraftCurrentRateOfClimb[NUMBEROFAIRCRAFTS];
    char* AircraftName[NUMBEROFAIRCRAFTS];
    int TotalNumberOfPoints[NUMBEROFAIRCRAFTS];
    int TotalNumberOfPointsPrevious[NUMBEROFAIRCRAFTS];
    double AircraftTargetHeading[NUMBEROFAIRCRAFTS];
    double AircraftRateOfClimbExternal[NUMBEROFAIRCRAFTS];
    double AircraftRateOFTurn[NUMBEROFAIRCRAFTS];


    double AircraftIntersectionLatitude[NUMBEROFAIRCRAFTS];
    double AircraftIntersectionLongitude[NUMBEROFAIRCRAFTS];
    double AircraftIntersectionAltitude[NUMBEROFAIRCRAFTS];
    bool AircraftOnCollisionCourse[NUMBEROFAIRCRAFTS];
    double AircraftCollisionTime[NUMBEROFAIRCRAFTS];

    // Aircraft Path data
    double AircraftPathLatitude[NUMBEROFAIRCRAFTS][NUMBEROFAIRCRAFTPATH];
    double AircraftPathLongitude[NUMBEROFAIRCRAFTS][NUMBEROFAIRCRAFTPATH];
    double AircraftPathAltitude[NUMBEROFAIRCRAFTS][NUMBEROFAIRCRAFTPATH];
    double AircraftPathHeading[NUMBEROFAIRCRAFTS][NUMBEROFAIRCRAFTPATH];
};

}
#endif /* ELEVATIONMODEL_H_ */
