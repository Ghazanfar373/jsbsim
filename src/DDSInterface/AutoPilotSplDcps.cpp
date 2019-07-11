#include "AutoPilotSplDcps.h"
#include "ccpp_AutoPilot.h"

const char *
__AutoPilot_AutoPilotData__name(void)
{
    return (const char*)"AutoPilot::AutoPilotData";
}

const char *
__AutoPilot_AutoPilotData__keys(void)
{
    return (const char*)"ID";
}

#include <v_kernel.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>

c_bool
__AutoPilot_AutoPilotData__copyIn(
    c_base base,
    struct ::AutoPilot::AutoPilotData *from,
    struct _AutoPilot_AutoPilotData *to)
{
    c_bool result = TRUE;

    to->ID = (c_long)from->ID;
    to->ThrottleCommand = (c_double)from->ThrottleCommand;
    to->ElevatorCommand = (c_double)from->ElevatorCommand;
    to->AileronCommand = (c_double)from->AileronCommand;
    to->RudderCommand = (c_double)from->RudderCommand;
    to->LeftBrakeCommand = (c_double)from->LeftBrakeCommand;
    to->RightBrakeCommand = (c_double)from->RightBrakeCommand;
    to->FlapCommand = (c_double)from->FlapCommand;
    to->EngineStartSwitch = (c_bool)from->EngineStartSwitch;
    to->WindSpeedCommand = (c_double)from->WindSpeedCommand;
    to->WindDirectionCommand = (c_double)from->WindDirectionCommand;
    return result;
}

void
__AutoPilot_AutoPilotData__copyOut(
    void *_from,
    void *_to)
{
    struct _AutoPilot_AutoPilotData *from = (struct _AutoPilot_AutoPilotData *)_from;
    struct ::AutoPilot::AutoPilotData *to = (struct ::AutoPilot::AutoPilotData *)_to;
    to->ID = (::DDS::Long)from->ID;
    to->ThrottleCommand = (::DDS::Double)from->ThrottleCommand;
    to->ElevatorCommand = (::DDS::Double)from->ElevatorCommand;
    to->AileronCommand = (::DDS::Double)from->AileronCommand;
    to->RudderCommand = (::DDS::Double)from->RudderCommand;
    to->LeftBrakeCommand = (::DDS::Double)from->LeftBrakeCommand;
    to->RightBrakeCommand = (::DDS::Double)from->RightBrakeCommand;
    to->FlapCommand = (::DDS::Double)from->FlapCommand;
    to->EngineStartSwitch = (::DDS::Boolean)from->EngineStartSwitch;
    to->WindSpeedCommand = (::DDS::Double)from->WindSpeedCommand;
    to->WindDirectionCommand = (::DDS::Double)from->WindDirectionCommand;
}

