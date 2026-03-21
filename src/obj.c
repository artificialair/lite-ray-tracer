#include "std.h"
#include "obj.h"

Scene * getDefaultPlane() {
	// Initialize camera
	Camera * camera = (Camera *) malloc(sizeof(Camera));

	camera->view_point[0] = 0.0;
	camera->view_point[1] = 0.0;
	camera->view_point[2] = 0.0;

	camera->view_dir[0] = 1.0;
	camera->view_dir[1] = 0.0;
	camera->view_dir[2] = 0.0;

	camera->proj_normal[0] = -1.0;
	camera->proj_normal[1] = 0.0;
	camera->proj_normal[2] = 0.0;
	
	camera->view_up[0] = 0.0;
	camera->view_up[1] = 1.0;
	camera->view_up[2] = 0.0;
	
	camera->proj_distance = 1;
	camera->view_width = 2;
	camera->view_height = 2;
	
	float * w = matr_mul(-1, camera->proj_normal);
	camera->w = matr_div(w, normalize(w));
	float * u = cross_product(camera->w, camera->view_up);
	camera->u = matr_div(u, normalize(u));
	float * v = cross_product(camera->u, camera->w);
	camera->v = matr_div(v, normalize(v));
		

	// Initialize material
	Material * material = (Material *) malloc(sizeof(Material));

	material->color[0] = 0.008;
	material->color[1] = 0.271;
	material->color[2] = 0.678;
	
	// Initialize surface
	Surface * surface = (Surface *) malloc(sizeof(Surface));
	surface->material = material;

	surface->point[0] = 1.0;
	surface->point[1] = 0.0;
	surface->point[2] = 0.0;
	
	surface->normal[0] = -1.0;
	surface->normal[1] = 0.0;
	surface->normal[2] = 0.0;

	surface->type = "Plane";

	// Initialize scene
	Scene * scene = (Scene *) malloc(sizeof(Scene));
	scene->camera = camera;
	scene->materials = &material;
	scene->surfaces = &surface;

	scene->size[0] = 200;
	scene->size[1] = 200;

	return scene;
}
