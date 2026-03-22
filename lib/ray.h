#ifndef RAY_H_
#define RAY_H_

#include "obj.h"

typedef struct {
	Vector* origin;
	Vector* direction;
} Ray;

typedef struct {
	Surface*  surface;
	float     t;
	Vector*   normal;
} HitRecord;

HitRecord* hitPlane(Surface* surface, Ray* ray);

#endif
