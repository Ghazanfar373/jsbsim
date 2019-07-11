/*
 * Added on 18-11-2014 for Tactical Aircraft generation
 */
#ifndef TACTICALAircraft_H_
#define TACTICALAircraft_H_

#include "math.h"
#include <string.h>
#include "models/FGModel.h"

using namespace std;
const int NUMBEROFAIRCRAFTPATH = 4;

namespace JSBSim{

		struct Location
		{
			double Latitude;    //degrees
			double Longitude;	////degrees
			double Altitude;	//feets
			double Heading;		//degrees
			static double size()
			{
				return sizeof(double)*4;
			}
		};

class TEAircraft
		{
		private:
		Location CurrentLocation;
		Location AircraftPath[4];
		char* Aircraftname;
		double AircraftVelocity;
		int AircraftPathNumber;
		bool TurnToNextPathFlag;
		int TotalNumberOfPoints;
		double RateOfClimb;      // ft  per minute
		double RateOfTurn;       // deg per minute

		public:
		TEAircraft();
		~TEAircraft();
		void InitializeAircraft();
		void SetCurrentLocation(Location loc);
		void SetAircraftPathLocation(Location loc, int pathnumber);
		void SetAircraftName(char* name);
		void SetAircraftVelocity(double vel);
		double GetAircraftVelocity();
		char* GetAircraftName();
		Location GetCurrentLocation(){ return CurrentLocation; }
		Location GetAircraftPathLocation(int pathnumber) { return AircraftPath[pathnumber]; }
		void SetTurnToNextPathFlag(bool flag);
		bool GetTurnToNextPathFlag();
		void SetTotalNumberOfPoints(int val);
		int GetTotalNumberOfPoints();
//		void SetAircraftPath(Location first,Location second,Location third,Location fourth);
//		Location* GetAircraftPath()
//		{
//			SetAircraftPath(FirstPointLocation,SecondPointLocation,ThirdPointLocation,FourthPointLocation);
//			return AircraftPath;
//		}
		void SetAircraftPathNumber(int val) { AircraftPathNumber = val;}
		int GetAircraftPathNumber() { return AircraftPathNumber;}
		void SetAircraftRateOfClimb(double val);
		double GetAircraftRateOfClimb();
		void SetAircraftRateOfTurn(double val);
		double GetAircraftRateOfTurn();

		};

}

#endif /* ELEVATIONMODEL_H_ */
