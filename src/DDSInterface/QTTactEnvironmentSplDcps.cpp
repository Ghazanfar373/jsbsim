#include "QTTactEnvironmentSplDcps.h"
#include "ccpp_QTTactEnvironment.h"

const char *
__QTTacticalEnvironment_QTTacticalEnvironmentData__name(void)
{
    return (const char*)"QTTacticalEnvironment::QTTacticalEnvironmentData";
}

const char *
__QTTacticalEnvironment_QTTacticalEnvironmentData__keys(void)
{
    return (const char*)"ID";
}

#include <v_kernel.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>

c_bool
__QTTacticalEnvironment_QTTacticalEnvironmentData__copyIn(
    c_base base,
    struct ::QTTacticalEnvironment::QTTacticalEnvironmentData *from,
    struct _QTTacticalEnvironment_QTTacticalEnvironmentData *to)
{
    c_bool result = TRUE;

    to->ID = (c_long)from->ID;
    {
        typedef c_bool _DestType[5];
        _DestType *dest = &to->CreatAircraft;
        memcpy (dest, from->CreatAircraft, sizeof (*dest));
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
        _DestType *dest = &to->TEAircraftDesiredTargetHeading;
        memcpy (dest, from->TEAircraftDesiredTargetHeading, sizeof (*dest));
    }
    {
        typedef c_long _DestType[5];
        _DestType *dest = &to->TEAircraftTotalNumberOfPoints;
        memcpy (dest, from->TEAircraftTotalNumberOfPoints, sizeof (*dest));
    }
    {
        typedef c_double _DestType[5];
        _DestType *dest = &to->TEAircraftRateOfClimb;
        memcpy (dest, from->TEAircraftRateOfClimb, sizeof (*dest));
    }
    {
        typedef c_double _DestType[5];
        _DestType *dest = &to->TEAircraftRateOFTurn;
        memcpy (dest, from->TEAircraftRateOFTurn, sizeof (*dest));
    }
    {
        typedef c_double _DestType[5][4];
        _DestType *dest = &to->TEAircraftPathLatitude;
        memcpy (dest, from->TEAircraftPathLatitude, sizeof (*dest));
    }
    {
        typedef c_double _DestType[5][4];
        _DestType *dest = &to->TEAircraftPathLongitude;
        memcpy (dest, from->TEAircraftPathLongitude, sizeof (*dest));
    }
    {
        typedef c_double _DestType[5][4];
        _DestType *dest = &to->TEAircraftPathAltitude;
        memcpy (dest, from->TEAircraftPathAltitude, sizeof (*dest));
    }
    {
        typedef c_double _DestType[5][4];
        _DestType *dest = &to->TEAircraftPathHeading;
        memcpy (dest, from->TEAircraftPathHeading, sizeof (*dest));
    }
    return result;
}

void
__QTTacticalEnvironment_QTTacticalEnvironmentData__copyOut(
    void *_from,
    void *_to)
{
    struct _QTTacticalEnvironment_QTTacticalEnvironmentData *from = (struct _QTTacticalEnvironment_QTTacticalEnvironmentData *)_from;
    struct ::QTTacticalEnvironment::QTTacticalEnvironmentData *to = (struct ::QTTacticalEnvironment::QTTacticalEnvironmentData *)_to;
    to->ID = (::DDS::Long)from->ID;
    {
        typedef c_bool _DestType[5];
        _DestType *src = &from->CreatAircraft;

        memcpy (to->CreatAircraft, src, sizeof (*src));
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
        _DestType *src = &from->TEAircraftDesiredTargetHeading;

        memcpy (to->TEAircraftDesiredTargetHeading, src, sizeof (*src));
    }
    {
        typedef c_long _DestType[5];
        _DestType *src = &from->TEAircraftTotalNumberOfPoints;

        memcpy (to->TEAircraftTotalNumberOfPoints, src, sizeof (*src));
    }
    {
        typedef c_double _DestType[5];
        _DestType *src = &from->TEAircraftRateOfClimb;

        memcpy (to->TEAircraftRateOfClimb, src, sizeof (*src));
    }
    {
        typedef c_double _DestType[5];
        _DestType *src = &from->TEAircraftRateOFTurn;

        memcpy (to->TEAircraftRateOFTurn, src, sizeof (*src));
    }
    {
        typedef c_double _DestType[5][4];
        _DestType *src = &from->TEAircraftPathLatitude;

        memcpy (to->TEAircraftPathLatitude, src, sizeof (*src));
    }
    {
        typedef c_double _DestType[5][4];
        _DestType *src = &from->TEAircraftPathLongitude;

        memcpy (to->TEAircraftPathLongitude, src, sizeof (*src));
    }
    {
        typedef c_double _DestType[5][4];
        _DestType *src = &from->TEAircraftPathAltitude;

        memcpy (to->TEAircraftPathAltitude, src, sizeof (*src));
    }
    {
        typedef c_double _DestType[5][4];
        _DestType *src = &from->TEAircraftPathHeading;

        memcpy (to->TEAircraftPathHeading, src, sizeof (*src));
    }
}

