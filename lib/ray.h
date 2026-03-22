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

Ray * castRay(Camera * camera, int32_t i, int32_t j, int32_t nx, int32_t ny);
HitRecord* hitPlane(Surface* surface, Ray* ray);
Vector* evaluate(Ray* ray, float t);

#endif
