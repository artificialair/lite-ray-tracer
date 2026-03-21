#ifndef RAY_H_
#define RAY_H_

#include "obj.h"

typedef struct {
	float origin[3];
	float direction[3];
} Ray;

typedef struct {
	Surface * surface;
	float t;
	float normal[3];
} HitRecord;

HitRecord * hitPlane(Surface * surface, Ray * ray);

#endif
