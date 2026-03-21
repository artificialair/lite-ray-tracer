#ifndef OBJ_H_
#define OBJ_H_

typedef struct {
	float view_point[3];
	float view_dir[3];
	float proj_normal[3];
	float view_up[3];
	int proj_distance;
	int view_width;
	int view_height;
	float u;
	float v;
	float w;
} Camera;

typedef struct {
	float color[3];
} Material;

typedef struct {
	Material * material;
	float point[3];
	float normal[3];
	char * type;
} Surface;

typedef struct {
	Camera * camera;
	Material ** materials;
	Surface ** surfaces;
	int size[2];
} Scene;


Scene * getDefaultPlane();

#endif
