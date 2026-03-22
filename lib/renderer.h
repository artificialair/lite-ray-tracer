#ifndef RENDERER_H_
#define RENDERER_H_
#include "types.h"
#include "syscalls.h"
#include "mem.h"
#include "std.h"
#include "tracer.h"
#include "obj.h"
#include "ray.h"
#include "linalg.h"

float*** render();
void write_img(float*** img, uint32_t nx, uint32_t ny);

#endif /*RENDERER_H_*/
