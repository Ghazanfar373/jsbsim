#ifndef IMAGEGENERATIONSPLTYPES_H
#define IMAGEGENERATIONSPLTYPES_H

#include "ccpp_ImageGeneration.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

extern c_metaObject __ImageGeneration_ImageGeneration__load (c_base base);

extern c_metaObject __ImageGeneration_ImageGenerationData__load (c_base base);
extern const char * __ImageGeneration_ImageGenerationData__keys (void);
extern const char * __ImageGeneration_ImageGenerationData__name (void);
struct _ImageGeneration_ImageGenerationData ;
extern  c_bool __ImageGeneration_ImageGenerationData__copyIn(c_base base, struct ImageGeneration::ImageGenerationData *from, struct _ImageGeneration_ImageGenerationData *to);
extern  void __ImageGeneration_ImageGenerationData__copyOut(void *_from, void *_to);
struct _ImageGeneration_ImageGenerationData {
    c_long ID;
    c_double Roll_deg;
    c_double Pitch_deg;
    c_double Heading_deg;
    c_double Altitude_ft;
    c_double Latitude;
    c_double Longitude;
    c_double AltitudeAboveSeaLevel_ft;
    c_double SimTime;
};

#endif
