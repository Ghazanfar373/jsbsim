#ifndef AUTOPILOTSPLTYPES_H
#define AUTOPILOTSPLTYPES_H

#include "ccpp_AutoPilot.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

extern c_metaObject __AutoPilot_AutoPilot__load (c_base base);

extern c_metaObject __AutoPilot_AutoPilotData__load (c_base base);
extern const char * __AutoPilot_AutoPilotData__keys (void);
extern const char * __AutoPilot_AutoPilotData__name (void);
struct _AutoPilot_AutoPilotData ;
extern  c_bool __AutoPilot_AutoPilotData__copyIn(c_base base, struct AutoPilot::AutoPilotData *from, struct _AutoPilot_AutoPilotData *to);
extern  void __AutoPilot_AutoPilotData__copyOut(void *_from, void *_to);
struct _AutoPilot_AutoPilotData {
    c_long ID;
    c_double ThrottleCommand;
    c_double ElevatorCommand;
    c_double AileronCommand;
    c_double RudderCommand;
    c_double LeftBrakeCommand;
    c_double RightBrakeCommand;
    c_double FlapCommand;
    c_bool EngineStartSwitch;
    c_double WindSpeedCommand;
    c_double WindDirectionCommand;
};

#endif
