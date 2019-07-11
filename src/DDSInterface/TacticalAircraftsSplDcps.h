#ifndef TACTICALAIRCRAFTSSPLTYPES_H
#define TACTICALAIRCRAFTSSPLTYPES_H

#include "ccpp_TacticalAircrafts.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

extern c_metaObject __TacticalAircrafts_TacticalAircrafts__load (c_base base);

extern c_metaObject __TacticalAircrafts_TacticalAircraftsData__load (c_base base);
extern const char * __TacticalAircrafts_TacticalAircraftsData__keys (void);
extern const char * __TacticalAircrafts_TacticalAircraftsData__name (void);
struct _TacticalAircrafts_TacticalAircraftsData ;
extern  c_bool __TacticalAircrafts_TacticalAircraftsData__copyIn(c_base base, struct TacticalAircrafts::TacticalAircraftsData *from, struct _TacticalAircrafts_TacticalAircraftsData *to);
extern  void __TacticalAircrafts_TacticalAircraftsData__copyOut(void *_from, void *_to);
struct _TacticalAircrafts_TacticalAircraftsData {
    c_long ID;
    c_bool TEAircraftExists[5];
    c_string TEAircraftName[5];
    c_double TEAircraftVelocity[5];
    c_double TEAircraftLatitude[5];
    c_double TEAircraftLongitude[5];
    c_double TEAircraftAltitude[5];
    c_double TEAircraftHeading[5];
    c_double TEAircraftPitchAngle[5];
    c_double TEAircraftRollAngle[5];
    c_double TEAircraftRateOfClimb[5];
    c_bool TEAircraftOnCollissionCourse[5];
    c_double TEAircraftTimeToCollision[5];
};

#endif
