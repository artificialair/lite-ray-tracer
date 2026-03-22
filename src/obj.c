#include "obj.h"


Scene * getDefaultPlane() {
	// Initialize camera
	Camera * camera = malloc(sizeof(Camera));

	camera->view_point->vector[0] = 0.0;
	camera->view_point->vector[1] = 0.0;
	camera->view_point->vector[2] = 0.0;
	camera->view_point->size = 3;

	camera->view_dir->vector[0] = 1.0;
	camera->view_dir->vector[1] = 0.0;
	camera->view_dir->vector[2] = 0.0;
	camera->view_dir->size = 3;

	camera->proj_normal->vector[0] = -1.0;
	camera->proj_normal->vector[1] = 0.0;
	camera->proj_normal->vector[2] = 0.0;
	camera->proj_normal->size = 3;
	
	camera->view_up->vector[0] = 0.0;
	camera->view_up->vector[1] = 1.0;
	camera->view_up->vector[2] = 0.0;
	camera->proj_normal->size = 3;
	
	camera->proj_distance = 1;
	camera->view_width = 2;
	camera->view_height = 2;

	// Initialize material
	Material * material = malloc(sizeof(Material));

	material->color->vector[0] = 0.008;
	material->color->vector[1] = 0.271;
	material->color->vector[2] = 0.678;
	material->color->size = 3;
	
	// Initialize surface
	Surface * surface = malloc(sizeof(Surface));
	surface->material = material;

	surface->point->vector[0] = 1.0;
	surface->point->vector[1] = 0.0;
	surface->point->vector[2] = 0.0;
	surface->point->size = 3;
	
	surface->normal->vector[0] = -1.0;
	surface->normal->vector[1] = 0.0;
	surface->normal->vector[2] = 0.0;
	surface->normal->size = 3;

	surface->type = "Plane";

	// Initialize scene
	Scene * scene = malloc(sizeof(Scene));
	scene->camera = camera;
	scene->material = material;
	scene->surface = surface;

	scene->size[0] = 200;
	scene->size[1] = 200;

	return scene;
}
