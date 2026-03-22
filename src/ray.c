#include "ray.h"
#include "linalg.h"

Ray* castRay(Camera* camera, int32_t i, int32_t j, int32_t nx, int32_t ny) {
    float v        = (-camera->view_height/2) + ((camera->view_height)*(j + 0.5))/ny;
    float u        = (-camera->view_width/2)  + ((camera->view_width)*(i + 0.5))/nx;
	Vector* d      = add_vv(mult_sv((-1 * camera->proj_distance), camera->proj_normal), 
			         add_vv(mult_sv(u, camera->u_vec), mult_sv(v, camera->v_vec)));
	Ray * ray      = (Ray *) malloc(sizeof(Ray));
	ray->origin    = camera->view_point;
	ray->direction = normalize(d);
    return ray;
}

Vector* evaluate(Ray* ray, float t) {
    Vector* ret_vec;
    ret_vec = add_vv(ray->origin, mult_sv(t, ray->direction));
    return ret_vec;
}

HitRecord* hitPlane(Surface* surface, Ray* ray) {
	float bot = dot_product(ray->direction, surface->normal);
	if (abs(bot) < 0.000001) return NULL;
	float t = dot_product(add_vv(surface->point, mult_sv(-1, ray->origin)), surface->normal) / bot;
	if (t > 0) {
		HitRecord * record = (HitRecord *) malloc(sizeof(HitRecord));
		record->surface = surface;
		record->t = t;
		record->normal = surface->normal;
		return record;
	}
	return NULL;
}
