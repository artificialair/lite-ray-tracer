#include "obj.h"


Scene* getDefaultScene() {
	// Initialize camera

	Camera* camera      = (Camera *) malloc(sizeof(Camera));
    Vector* view_point  = init_vector(3);
    Vector* view_dir    = init_vector(3);
    Vector* proj_normal = init_vector(3);
    Vector* view_up     = init_vector(3);
    camera->view_point  = view_point;
    camera->view_dir    = view_dir;
    camera->proj_normal = proj_normal;
    camera->view_up     = view_up;

	view_point->vector[0] = 0.0;
	view_point->vector[1] = 0.0;
	view_point->vector[2] = 0.0;
	view_point->size = 3;

	view_dir->vector[0] = 1.0;
	view_dir->vector[1] = 0.0;
	view_dir->vector[2] = 0.0;
	view_dir->size = 3;

	proj_normal->vector[0] = -1.0;
	proj_normal->vector[1] = 0.0;
	proj_normal->vector[2] = 0.0;
	proj_normal->size = 3;
	
	view_up->vector[0] = 0.0;
	view_up->vector[1] = 1.0;
	view_up->vector[2] = 0.0;
	proj_normal->size = 3;
	
	camera->proj_distance = 1;
	camera->view_width = 2;
	camera->view_height = 2;
    camera->w_vec       = mult_sv(-1, proj_normal);
    camera->u_vec       = normalize(cross_product(camera->w_vec, view_up));
    camera->v_vec       = normalize(cross_product(camera->u_vec, camera->w_vec));


    	Light* light = (Light *)malloc(sizeof(Light));
	light->position = init_vector(3);
	light->position->vector[0] = 5.0;
	light->position->vector[1] = 4.0;
	light->position->vector[2] = 3.0;
	light->intensity = 200.0;
	// Initialize scene
	Scene* scene = (Scene *)malloc(sizeof(Scene));
	scene->camera = camera;
	scene->surface = NULL;
	scene->point_light = light;

	scene->size[0] = 200;
	scene->size[1] = 200;

	return scene;
}

Surface* getDefaultPlane() {
	Material* material = (Material *)malloc(sizeof(Material));
    float* color        = (float *)malloc(sizeof(float)*3);
    material->color = color;
    Vector* point       = init_vector(3);
    Vector* normal      = init_vector(3);

	color[0] = 0.008;
	color[1] = 0.271;
	color[2] = 0.678;
	
	// Initialize plane
	Surface* surface = (Surface *)malloc(sizeof(Surface));
	surface->material = material;
    surface->point  = point;
    surface->normal = normal;

	point->vector[0] = 1.0;
	point->vector[1] = 0.0;
	point->vector[2] = 0.0;
	point->size = 3;
	
	normal->vector[0] = -1.0;
	normal->vector[1] = 0.0;
	normal->vector[2] = 0.0;
	normal->size = 3;

	surface->type = "Plane";
    surface->radius = 0;
    return surface;
}

Surface* getDefaultSphere() {
    Surface* surface = (Surface *)malloc(sizeof(Surface));
    
	Material* material  = (Material *)malloc(sizeof(Material));
    float* color        = (float *)malloc(sizeof(float)*3);
    material->color     = color;
    Vector* point       = init_vector(3);

	color[0] = 0.008;
	color[1] = 0.271;
	color[2] = 0.678;

	point->vector[0] = 2.0;
	point->vector[1] = 0.0;
	point->vector[2] = 0.0;
	point->size = 3;
    
    surface->radius = 1;
    surface->normal = NULL;
    surface->material = material;
    surface->point = point;
    surface->type  = "Sphere";
    return surface;
}
