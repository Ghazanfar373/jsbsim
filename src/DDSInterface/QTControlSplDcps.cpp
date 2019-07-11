#include "QTControlSplDcps.h"
#include "ccpp_QTControl.h"

const char *
__QTControl_QtControlData__name(void)
{
    return (const char*)"QTControl::QtControlData";
}

const char *
__QTControl_QtControlData__keys(void)
{
    return (const char*)"ID";
}

#include <v_kernel.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>

c_bool
__QTControl_QtControlData__copyIn(
    c_base base,
    struct ::QTControl::QtControlData *from,
    struct _QTControl_QtControlData *to)
{
    c_bool result = TRUE;

    to->ID = (c_long)from->ID;
    to->Throttle = (c_double)from->Throttle;
    to->ElevatorCommand = (c_double)from->ElevatorCommand;
    to->AileronCommand = (c_double)from->AileronCommand;
    to->RudderCommand = (c_double)from->RudderCommand;
    to->SteerLeft = (c_double)from->SteerLeft;
    to->SteerRight = (c_double)from->SteerRight;
    to->LeftBrakeCommand = (c_double)from->LeftBrakeCommand;
    to->RightBrakeCommand = (c_double)from->RightBrakeCommand;
    to->FlapCommand = (c_double)from->FlapCommand;
    to->EngineStartSwitch = (c_bool)from->EngineStartSwitch;
    to->ThrottleCommand = (c_double)from->ThrottleCommand;
    to->WindSpeedCommand = (c_double)from->WindSpeedCommand;
    to->WindDirectionCommand = (c_double)from->WindDirectionCommand;
    to->GeneratorSwitch = (c_bool)from->GeneratorSwitch;
    to->InverterSwitch = (c_bool)from->InverterSwitch;
    to->BatteryStatus = (c_bool)from->BatteryStatus;
    return result;
}

void
__QTControl_QtControlData__copyOut(
    void *_from,
    void *_to)
{
    struct _QTControl_QtControlData *from = (struct _QTControl_QtControlData *)_from;
    struct ::QTControl::QtControlData *to = (struct ::QTControl::QtControlData *)_to;
    to->ID = (::DDS::Long)from->ID;
    to->Throttle = (::DDS::Double)from->Throttle;
    to->ElevatorCommand = (::DDS::Double)from->ElevatorCommand;
    to->AileronCommand = (::DDS::Double)from->AileronCommand;
    to->RudderCommand = (::DDS::Double)from->RudderCommand;
    to->SteerLeft = (::DDS::Double)from->SteerLeft;
    to->SteerRight = (::DDS::Double)from->SteerRight;
    to->LeftBrakeCommand = (::DDS::Double)from->LeftBrakeCommand;
    to->RightBrakeCommand = (::DDS::Double)from->RightBrakeCommand;
    to->FlapCommand = (::DDS::Double)from->FlapCommand;
    to->EngineStartSwitch = (::DDS::Boolean)from->EngineStartSwitch;
    to->ThrottleCommand = (::DDS::Double)from->ThrottleCommand;
    to->WindSpeedCommand = (::DDS::Double)from->WindSpeedCommand;
    to->WindDirectionCommand = (::DDS::Double)from->WindDirectionCommand;
    to->GeneratorSwitch = (::DDS::Boolean)from->GeneratorSwitch;
    to->InverterSwitch = (::DDS::Boolean)from->InverterSwitch;
    to->BatteryStatus = (::DDS::Boolean)from->BatteryStatus;
}

