#ifndef obj
#define obj

typedef struct {
	double view_point[3];
	double view_dir[3];
	double proj_normal[3];
	double view_up[3];
	int proj_distance;
	int view_width;
	int view_height;
} Camera;

typedef struct {
	double color[3];
} Material;

typedef struct {
	Material * material;
	double point[3];
	double normal[3];
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
