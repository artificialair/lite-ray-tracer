#include "ray.h"
#include "linalg.h"


Ray * castRays(Camera * camera, int i, int j, int nx, int ny) {
	float u = ((camera->view_width * -1) / 2) + ((camera->view_width * (i + 0.5)) / nx);
	float v = ((camera->view_height * -1) / 2) + ((camera->view_height * (j + 0.5)) / ny);
	float d[3] = matr_mul((camera->proj_distance * -1), camera->proj_normal) + (u * camera->u) + (v * camera->v);
	Ray * ray = (Ray *) malloc(sizeof(Ray));
	ray->origin = camera->view_point;
	ray->direction = matr_div(d, normalize(d));
}

HitRecord * hitPlane(Surface * surface, Ray * ray) {
	float bot = dot_product(ray->direction, surface->normal, 3);
	if (bot < 0.000001) return NULL;
	float t = dot_product(matr_sub(surface->point, ray->origin), surface->normal) / dot;
	if (t > 0) {
		HitRecord * record = (HitRecord *) malloc(sizeof(HitRecord));
		record->surface = surface;
		record->t = t;
		record->normal = surface->normal;
		return record;
	}
	return NULL;
}
