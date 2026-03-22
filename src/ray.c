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

/*
 *         A = np.dot(ray.d, ray.d)
        B = np.dot(2 * ray.d, ray.o - self.center)
        C = (np.dot(ray.o - self.center, ray.o - self.center) - self.radius**2)
        det = B**2 - (4 * A * C)
        if (det < 0):
            return None
        pos_root = (-B + np.sqrt(det)) / (2 * A)
        neg_root = (-B - np.sqrt(det)) / (2 * A)
        if neg_root < 0 and pos_root > 0:
            t = pos_root
            normal = (ray.evaluate(t) - self.center) / self.radius
            return HitRecord(self, pos_root, normal)
        t = min(pos_root, neg_root)
        if neg_root < 0 and pos_root < 0:
            return None
        normal = (ray.evaluate(t) - self.center) / self.radius
        return HitRecord(self, min(pos_root, neg_root), normal)
*/
HitRecord* hitSphere(Surface* surface, Ray* ray) {
    float A = dot_product(ray->direction, ray->direction);
    float B = (-dot_product(mult_sv(2, ray->direction), 
                            add_vv(ray->origin, mult_sv(-1, surface->center))));
    float C = dot_product(add_vv(ray->origin, mult_sv(-1, surface->center)), 
                          add_vv(ray->origin, mult_sv(-1, surface->center)))
              - (surface->radius*surface->radius);
    float det = B*B - (4 * A * C);
    if (det < 0) return NULL;
    float pos_root = (-B + sqrt(det)) / (2*A);
    float neg_root = (-B - sqrt(det)) / (2*A);
    float t = pos_root > neg_root ? neg_root : pos_root;
    if (neg_root < 0 && pos_root < 0) return NULL;
    Vector* norm = mult_sv(1/surface->radius, add_vv(evaluate(ray, t), mult_sv(-1, surface->center)));
    HitRecord* hr = (HitRecord *)malloc(sizeof(HitRecord));
    hr->surface = surface;
    hr->t = t;
    hr->normal = norm;
    return hr;
}   

