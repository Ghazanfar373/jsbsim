#ifndef QTCONTROLSPLTYPES_H
#define QTCONTROLSPLTYPES_H

#include "ccpp_QTControl.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

extern c_metaObject __QTControl_QTControl__load (c_base base);

extern c_metaObject __QTControl_QtControlData__load (c_base base);
extern const char * __QTControl_QtControlData__keys (void);
extern const char * __QTControl_QtControlData__name (void);
struct _QTControl_QtControlData ;
extern  c_bool __QTControl_QtControlData__copyIn(c_base base, struct QTControl::QtControlData *from, struct _QTControl_QtControlData *to);
extern  void __QTControl_QtControlData__copyOut(void *_from, void *_to);
struct _QTControl_QtControlData {
    c_long ID;
    c_double Throttle;
    c_double ElevatorCommand;
    c_double AileronCommand;
    c_double RudderCommand;
    c_double SteerLeft;
    c_double SteerRight;
    c_double LeftBrakeCommand;
    c_double RightBrakeCommand;
    c_double FlapCommand;
    c_bool EngineStartSwitch;
    c_double ThrottleCommand;
    c_double WindSpeedCommand;
    c_double WindDirectionCommand;
    c_bool GeneratorSwitch;
    c_bool InverterSwitch;
    c_bool BatteryStatus;
};

#endif
