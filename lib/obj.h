#ifndef OBJ_H_
#define OBJ_H_

#include "std.h"
#include "linalg.h"

typedef struct {
	Vector* view_point;
	Vector* view_dir;
	Vector* proj_normal;
	Vector* view_up;
	int32_t proj_distance;
	int32_t view_width;
	int32_t view_height;
    Vector* u_vec;
    Vector* v_vec;
	Vector* w_vec;
} Camera;

typedef struct {
	float* color;
} Material;

typedef struct {
	Material*  material;
	Vector*    point;
	Vector*    normal;
    float      radius;
	char*      type;
} Surface;

typedef struct {
	Camera*    camera;
	Surface*   surface;
	int32_t    size[2];
} Scene;


Scene*   getDefaultScene();
Surface* getDefaultPlane();
Surface* getDefaultSphere();

#endif /*OBJ_H_*/
