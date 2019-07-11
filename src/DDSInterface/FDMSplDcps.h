#ifndef FDMSPLTYPES_H
#define FDMSPLTYPES_H

#include "ccpp_FDM.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

extern c_metaObject __FDM_FDM__load (c_base base);

extern c_metaObject __FDM_fdmdata__load (c_base base);
extern const char * __FDM_fdmdata__keys (void);
extern const char * __FDM_fdmdata__name (void);
struct _FDM_fdmdata ;
extern  c_bool __FDM_fdmdata__copyIn(c_base base, struct FDM::fdmdata *from, struct _FDM_fdmdata *to);
extern  void __FDM_fdmdata__copyOut(void *_from, void *_to);
struct _FDM_fdmdata {
    c_long ID;
    c_double Velocity_Kts;
    c_double MachNumber;
    c_double GValue;
    c_double SideSlip;
    c_double Roll_deg;
    c_double Pitch_deg;
    c_double AtmosphereTemperature;
    c_double Heading_deg;
    c_double Altitude_ft;
    c_double VerticleVelocity_fpm;
    c_double Latitude;
    c_double Longitude;
    c_double AltitudeAboveSeaLevel_ft;
    c_double SimTime;
    c_double AngleOFAttack;
    c_double TrueAirSpeed;
    c_double GroundAirSpeed;
    c_double thetadot;
    c_double phidot;
    c_double psidot;
    c_double WindSpeed;
    c_double WindDirection;
    c_bool GeneratorStatus;
    c_bool GeneratorIndicatorLight;
    c_double ACBusVoltage;
    c_bool ACBusIndicatorLight;
    c_double DCBusVoltage;
    c_bool DCBusIndicatorLight;
    c_double BatteryVoltage;
};

#endif
