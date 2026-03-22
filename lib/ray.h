#ifndef RAY_H_
#define RAY_H_

#include "obj.h"

typedef struct {
	Vector origin[3];
	Vector direction[3];
} Ray;

typedef struct {
	Surface*  surface;
	float     t;
	Vector     normal[3];
} HitRecord;

HitRecord* hitPlane(Surface* surface, Ray* ray);

#endif
