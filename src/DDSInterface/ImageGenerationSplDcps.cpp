#include "ImageGenerationSplDcps.h"
#include "ccpp_ImageGeneration.h"

const char *
__ImageGeneration_ImageGenerationData__name(void)
{
    return (const char*)"ImageGeneration::ImageGenerationData";
}

const char *
__ImageGeneration_ImageGenerationData__keys(void)
{
    return (const char*)"ID";
}

#include <v_kernel.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>

c_bool
__ImageGeneration_ImageGenerationData__copyIn(
    c_base base,
    struct ::ImageGeneration::ImageGenerationData *from,
    struct _ImageGeneration_ImageGenerationData *to)
{
    c_bool result = TRUE;

    to->ID = (c_long)from->ID;
    to->Roll_deg = (c_double)from->Roll_deg;
    to->Pitch_deg = (c_double)from->Pitch_deg;
    to->Heading_deg = (c_double)from->Heading_deg;
    to->Altitude_ft = (c_double)from->Altitude_ft;
    to->Latitude = (c_double)from->Latitude;
    to->Longitude = (c_double)from->Longitude;
    to->AltitudeAboveSeaLevel_ft = (c_double)from->AltitudeAboveSeaLevel_ft;
    to->SimTime = (c_double)from->SimTime;
    return result;
}

void
__ImageGeneration_ImageGenerationData__copyOut(
    void *_from,
    void *_to)
{
    struct _ImageGeneration_ImageGenerationData *from = (struct _ImageGeneration_ImageGenerationData *)_from;
    struct ::ImageGeneration::ImageGenerationData *to = (struct ::ImageGeneration::ImageGenerationData *)_to;
    to->ID = (::DDS::Long)from->ID;
    to->Roll_deg = (::DDS::Double)from->Roll_deg;
    to->Pitch_deg = (::DDS::Double)from->Pitch_deg;
    to->Heading_deg = (::DDS::Double)from->Heading_deg;
    to->Altitude_ft = (::DDS::Double)from->Altitude_ft;
    to->Latitude = (::DDS::Double)from->Latitude;
    to->Longitude = (::DDS::Double)from->Longitude;
    to->AltitudeAboveSeaLevel_ft = (::DDS::Double)from->AltitudeAboveSeaLevel_ft;
    to->SimTime = (::DDS::Double)from->SimTime;
}

