#ifndef QTTACTENVIRONMENTSPLTYPES_H
#define QTTACTENVIRONMENTSPLTYPES_H

#include "ccpp_QTTactEnvironment.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

extern c_metaObject __QTTactEnvironment_QTTacticalEnvironment__load (c_base base);

extern c_metaObject __QTTacticalEnvironment_QTTacticalEnvironmentData__load (c_base base);
extern const char * __QTTacticalEnvironment_QTTacticalEnvironmentData__keys (void);
extern const char * __QTTacticalEnvironment_QTTacticalEnvironmentData__name (void);
struct _QTTacticalEnvironment_QTTacticalEnvironmentData ;
extern  c_bool __QTTacticalEnvironment_QTTacticalEnvironmentData__copyIn(c_base base, struct QTTacticalEnvironment::QTTacticalEnvironmentData *from, struct _QTTacticalEnvironment_QTTacticalEnvironmentData *to);
extern  void __QTTacticalEnvironment_QTTacticalEnvironmentData__copyOut(void *_from, void *_to);
struct _QTTacticalEnvironment_QTTacticalEnvironmentData {
    c_long ID;
    c_bool CreatAircraft[5];
    c_string TEAircraftName[5];
    c_double TEAircraftVelocity[5];
    c_double TEAircraftDesiredTargetHeading[5];
    c_long TEAircraftTotalNumberOfPoints[5];
    c_double TEAircraftRateOfClimb[5];
    c_double TEAircraftRateOFTurn[5];
    c_double TEAircraftPathLatitude[5][4];
    c_double TEAircraftPathLongitude[5][4];
    c_double TEAircraftPathAltitude[5][4];
    c_double TEAircraftPathHeading[5][4];
};

#endif
