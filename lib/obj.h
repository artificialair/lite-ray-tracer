#ifndef OBJ_H_
#define OBJ_H_

#include "std.h"
#include "linalg.h"

typedef struct {
	float  view_point[3];
	float  view_dir[3];
	float  proj_normal[3];
	float  view_up[3];
	int32_t    proj_distance;
	int32_t    view_width;
	int32_t    view_height;
    Vector u_vec;
    Vector v_vec;
    Vector w_vec;
} Camera;

typedef struct {
	float color[3];
} Material;

typedef struct {
	Material*  material;
	float      point[3];
	float      normal[3];
	char*      type;
} Surface;

typedef struct {
	Camera*    camera;
	Material** materials;
	Surface**  surfaces;
	int32_t    size[2];
} Scene;


Scene* getDefaultPlane();

#endif /*OBJ_H_*/
