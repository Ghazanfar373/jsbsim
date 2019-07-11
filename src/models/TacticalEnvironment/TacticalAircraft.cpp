#include "TacticalAircraft.h"

using namespace std;
namespace JSBSim{

TEAircraft::TEAircraft()
{
	InitializeAircraft();
}

void TEAircraft::InitializeAircraft()
{
	Aircraftname = "Uninitialized";
	AircraftVelocity = 0.0;
	AircraftPathNumber = 1;
	RateOfClimb = 10000.0;      // ft  per minute
	RateOfTurn = 360*2;       // deg per minute  (5 deg per sec
	CurrentLocation.Latitude = CurrentLocation.Longitude = CurrentLocation.Altitude =
			CurrentLocation.Heading = 0.0;
	for (int i=0;i<NUMBEROFAIRCRAFTPATH;i++)
	{
		AircraftPath[i].Latitude = 0.0;
		AircraftPath[i].Longitude = 0.0;
		AircraftPath[i].Altitude = 0.0;
		AircraftPath[i].Heading = 0.0;
		SetAircraftPathLocation(AircraftPath[i],i);
	}

	TurnToNextPathFlag = false;
}
void TEAircraft::SetCurrentLocation(Location loc)
{
	CurrentLocation.Latitude = loc.Latitude;
	CurrentLocation.Longitude = loc.Longitude;
	CurrentLocation.Altitude = loc.Altitude;
	CurrentLocation.Heading = loc.Heading;
}

void TEAircraft::SetAircraftPathLocation(Location loc, int pathnumber)
{
	AircraftPath[pathnumber].Latitude = loc.Latitude;
	AircraftPath[pathnumber].Longitude = loc.Longitude;
	AircraftPath[pathnumber].Altitude = loc.Altitude;
	AircraftPath[pathnumber].Heading = loc.Heading;
}

void TEAircraft::SetAircraftName(char* name)
{
	Aircraftname = name;
}
void TEAircraft::SetAircraftVelocity(double vel)
{
	AircraftVelocity = vel;
}
void TEAircraft::SetTurnToNextPathFlag(bool flag)
{
	TurnToNextPathFlag = flag;
}
bool TEAircraft::GetTurnToNextPathFlag()
{
	return TurnToNextPathFlag;
}
double TEAircraft::GetAircraftVelocity()
{
	return AircraftVelocity;
}
char* TEAircraft::GetAircraftName()
{
	return Aircraftname;
}

void TEAircraft::SetTotalNumberOfPoints(int val)
{
	TotalNumberOfPoints = val;
}

int TEAircraft::GetTotalNumberOfPoints()
{
	return TotalNumberOfPoints;
}

void TEAircraft::SetAircraftRateOfClimb(double val)
{
	RateOfClimb = val;
}
double TEAircraft::GetAircraftRateOfClimb()
{
	return RateOfClimb;
}

void TEAircraft::SetAircraftRateOfTurn(double val)
{
	RateOfTurn = val;
}
double TEAircraft::GetAircraftRateOfTurn()
{
	return RateOfTurn;
}



TEAircraft::~TEAircraft()
{

}

}
