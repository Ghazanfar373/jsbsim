#include "TacticalAircraftsSplDcps.h"
#include "ccpp_TacticalAircrafts.h"

const char *
__TacticalAircrafts_TacticalAircraftsData__name(void)
{
    return (const char*)"TacticalAircrafts::TacticalAircraftsData";
}

const char *
__TacticalAircrafts_TacticalAircraftsData__keys(void)
{
    return (const char*)"ID";
}

#include <v_kernel.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>

c_bool
__TacticalAircrafts_TacticalAircraftsData__copyIn(
    c_base base,
    struct ::TacticalAircrafts::TacticalAircraftsData *from,
    struct _TacticalAircrafts_TacticalAircraftsData *to)
{
    c_bool result = TRUE;

    to->ID = (c_long)from->ID;
    {
        typedef c_bool _DestType[5];
        _DestType *dest = &to->TEAircraftExists;
        memcpy (dest, from->TEAircraftExists, sizeof (*dest));
    }
    {
        typedef c_string _DestType[5];
        _DestType *dest = &to->TEAircraftName;
        int i1;

        for (i1 = 0; (i1 < 5) && result; i1++) {
#ifdef OSPL_BOUNDS_CHECK
            if((from->TEAircraftName)[i1]){
                (*dest)[i1] = c_stringNew(base, (from->TEAircraftName)[i1]);
            } else {
                result = FALSE;
            }
#else
            (*dest)[i1] = c_stringNew(base, (from->TEAircraftName)[i1]);
#endif
        }
    }
    {
        typedef c_double _DestType[5];
        _DestType *dest = &to->TEAircraftVelocity;
        memcpy (dest, from->TEAircraftVelocity, sizeof (*dest));
    }
    {
        typedef c_double _DestType[5];
        _DestType *dest = &to->TEAircraftLatitude;
        memcpy (dest, from->TEAircraftLatitude, sizeof (*dest));
    }
    {
        typedef c_double _DestType[5];
        _DestType *dest = &to->TEAircraftLongitude;
        memcpy (dest, from->TEAircraftLongitude, sizeof (*dest));
    }
    {
        typedef c_double _DestType[5];
        _DestType *dest = &to->TEAircraftAltitude;
        memcpy (dest, from->TEAircraftAltitude, sizeof (*dest));
    }
    {
        typedef c_double _DestType[5];
        _DestType *dest = &to->TEAircraftHeading;
        memcpy (dest, from->TEAircraftHeading, sizeof (*dest));
    }
    {
        typedef c_double _DestType[5];
        _DestType *dest = &to->TEAircraftPitchAngle;
        memcpy (dest, from->TEAircraftPitchAngle, sizeof (*dest));
    }
    {
        typedef c_double _DestType[5];
        _DestType *dest = &to->TEAircraftRollAngle;
        memcpy (dest, from->TEAircraftRollAngle, sizeof (*dest));
    }
    {
        typedef c_double _DestType[5];
        _DestType *dest = &to->TEAircraftRateOfClimb;
        memcpy (dest, from->TEAircraftRateOfClimb, sizeof (*dest));
    }
    {
        typedef c_bool _DestType[5];
        _DestType *dest = &to->TEAircraftOnCollissionCourse;
        memcpy (dest, from->TEAircraftOnCollissionCourse, sizeof (*dest));
    }
    {
        typedef c_double _DestType[5];
        _DestType *dest = &to->TEAircraftTimeToCollision;
        memcpy (dest, from->TEAircraftTimeToCollision, sizeof (*dest));
    }
    return result;
}

void
__TacticalAircrafts_TacticalAircraftsData__copyOut(
    void *_from,
    void *_to)
{
    struct _TacticalAircrafts_TacticalAircraftsData *from = (struct _TacticalAircrafts_TacticalAircraftsData *)_from;
    struct ::TacticalAircrafts::TacticalAircraftsData *to = (struct ::TacticalAircrafts::TacticalAircraftsData *)_to;
    to->ID = (::DDS::Long)from->ID;
    {
        typedef c_bool _DestType[5];
        _DestType *src = &from->TEAircraftExists;

        memcpy (to->TEAircraftExists, src, sizeof (*src));
    }
    {
        typedef c_string _DestType[5];
        _DestType *src = &from->TEAircraftName;

        int i1;

        for (i1 = 0; (i1 < 5); i1++) {
            (to->TEAircraftName)[i1] = CORBA::string_dup((*src)[i1]);
        }
    }
    {
        typedef c_double _DestType[5];
        _DestType *src = &from->TEAircraftVelocity;

        memcpy (to->TEAircraftVelocity, src, sizeof (*src));
    }
    {
        typedef c_double _DestType[5];
        _DestType *src = &from->TEAircraftLatitude;

        memcpy (to->TEAircraftLatitude, src, sizeof (*src));
    }
    {
        typedef c_double _DestType[5];
        _DestType *src = &from->TEAircraftLongitude;

        memcpy (to->TEAircraftLongitude, src, sizeof (*src));
    }
    {
        typedef c_double _DestType[5];
        _DestType *src = &from->TEAircraftAltitude;

        memcpy (to->TEAircraftAltitude, src, sizeof (*src));
    }
    {
        typedef c_double _DestType[5];
        _DestType *src = &from->TEAircraftHeading;

        memcpy (to->TEAircraftHeading, src, sizeof (*src));
    }
    {
        typedef c_double _DestType[5];
        _DestType *src = &from->TEAircraftPitchAngle;

        memcpy (to->TEAircraftPitchAngle, src, sizeof (*src));
    }
    {
        typedef c_double _DestType[5];
        _DestType *src = &from->TEAircraftRollAngle;

        memcpy (to->TEAircraftRollAngle, src, sizeof (*src));
    }
    {
        typedef c_double _DestType[5];
        _DestType *src = &from->TEAircraftRateOfClimb;

        memcpy (to->TEAircraftRateOfClimb, src, sizeof (*src));
    }
    {
        typedef c_bool _DestType[5];
        _DestType *src = &from->TEAircraftOnCollissionCourse;

        memcpy (to->TEAircraftOnCollissionCourse, src, sizeof (*src));
    }
    {
        typedef c_double _DestType[5];
        _DestType *src = &from->TEAircraftTimeToCollision;

        memcpy (to->TEAircraftTimeToCollision, src, sizeof (*src));
    }
}

