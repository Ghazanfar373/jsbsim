#include "FDMSplDcps.h"
#include "ccpp_FDM.h"

const char *
__FDM_fdmdata__name(void)
{
    return (const char*)"FDM::fdmdata";
}

const char *
__FDM_fdmdata__keys(void)
{
    return (const char*)"ID";
}

#include <v_kernel.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>

c_bool
__FDM_fdmdata__copyIn(
    c_base base,
    struct ::FDM::fdmdata *from,
    struct _FDM_fdmdata *to)
{
    c_bool result = TRUE;

    to->ID = (c_long)from->ID;
    to->Velocity_Kts = (c_double)from->Velocity_Kts;
    to->MachNumber = (c_double)from->MachNumber;
    to->GValue = (c_double)from->GValue;
    to->SideSlip = (c_double)from->SideSlip;
    to->Roll_deg = (c_double)from->Roll_deg;
    to->Pitch_deg = (c_double)from->Pitch_deg;
    to->AtmosphereTemperature = (c_double)from->AtmosphereTemperature;
    to->Heading_deg = (c_double)from->Heading_deg;
    to->Altitude_ft = (c_double)from->Altitude_ft;
    to->VerticleVelocity_fpm = (c_double)from->VerticleVelocity_fpm;
    to->Latitude = (c_double)from->Latitude;
    to->Longitude = (c_double)from->Longitude;
    to->AltitudeAboveSeaLevel_ft = (c_double)from->AltitudeAboveSeaLevel_ft;
    to->SimTime = (c_double)from->SimTime;
    to->AngleOFAttack = (c_double)from->AngleOFAttack;
    to->TrueAirSpeed = (c_double)from->TrueAirSpeed;
    to->GroundAirSpeed = (c_double)from->GroundAirSpeed;
    to->thetadot = (c_double)from->thetadot;
    to->phidot = (c_double)from->phidot;
    to->psidot = (c_double)from->psidot;
    to->WindSpeed = (c_double)from->WindSpeed;
    to->WindDirection = (c_double)from->WindDirection;
    to->GeneratorStatus = (c_bool)from->GeneratorStatus;
    to->GeneratorIndicatorLight = (c_bool)from->GeneratorIndicatorLight;
    to->ACBusVoltage = (c_double)from->ACBusVoltage;
    to->ACBusIndicatorLight = (c_bool)from->ACBusIndicatorLight;
    to->DCBusVoltage = (c_double)from->DCBusVoltage;
    to->DCBusIndicatorLight = (c_bool)from->DCBusIndicatorLight;
    to->BatteryVoltage = (c_double)from->BatteryVoltage;
    return result;
}

void
__FDM_fdmdata__copyOut(
    void *_from,
    void *_to)
{
    struct _FDM_fdmdata *from = (struct _FDM_fdmdata *)_from;
    struct ::FDM::fdmdata *to = (struct ::FDM::fdmdata *)_to;
    to->ID = (::DDS::Long)from->ID;
    to->Velocity_Kts = (::DDS::Double)from->Velocity_Kts;
    to->MachNumber = (::DDS::Double)from->MachNumber;
    to->GValue = (::DDS::Double)from->GValue;
    to->SideSlip = (::DDS::Double)from->SideSlip;
    to->Roll_deg = (::DDS::Double)from->Roll_deg;
    to->Pitch_deg = (::DDS::Double)from->Pitch_deg;
    to->AtmosphereTemperature = (::DDS::Double)from->AtmosphereTemperature;
    to->Heading_deg = (::DDS::Double)from->Heading_deg;
    to->Altitude_ft = (::DDS::Double)from->Altitude_ft;
    to->VerticleVelocity_fpm = (::DDS::Double)from->VerticleVelocity_fpm;
    to->Latitude = (::DDS::Double)from->Latitude;
    to->Longitude = (::DDS::Double)from->Longitude;
    to->AltitudeAboveSeaLevel_ft = (::DDS::Double)from->AltitudeAboveSeaLevel_ft;
    to->SimTime = (::DDS::Double)from->SimTime;
    to->AngleOFAttack = (::DDS::Double)from->AngleOFAttack;
    to->TrueAirSpeed = (::DDS::Double)from->TrueAirSpeed;
    to->GroundAirSpeed = (::DDS::Double)from->GroundAirSpeed;
    to->thetadot = (::DDS::Double)from->thetadot;
    to->phidot = (::DDS::Double)from->phidot;
    to->psidot = (::DDS::Double)from->psidot;
    to->WindSpeed = (::DDS::Double)from->WindSpeed;
    to->WindDirection = (::DDS::Double)from->WindDirection;
    to->GeneratorStatus = (::DDS::Boolean)from->GeneratorStatus;
    to->GeneratorIndicatorLight = (::DDS::Boolean)from->GeneratorIndicatorLight;
    to->ACBusVoltage = (::DDS::Double)from->ACBusVoltage;
    to->ACBusIndicatorLight = (::DDS::Boolean)from->ACBusIndicatorLight;
    to->DCBusVoltage = (::DDS::Double)from->DCBusVoltage;
    to->DCBusIndicatorLight = (::DDS::Boolean)from->DCBusIndicatorLight;
    to->BatteryVoltage = (::DDS::Double)from->BatteryVoltage;
}

