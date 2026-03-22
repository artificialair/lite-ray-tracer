#include "renderer.h"

float*** init_nm3(uint32_t rows, uint32_t cols, uint32_t arr_size) {
    float*** mat = (float***)malloc(rows*sizeof(uintptr_t));
    for (int i = 0 ; i < rows; i++) {
        float** inner = (float**)malloc(cols*sizeof(uintptr_t));
        mat[i] = inner;
        for (int j = 0; j < cols; j++) {
            float* arr = (float*)malloc(sizeof(float)*arr_size);
            mat[i][j] = arr;
        }
    }
    return mat;
}

float*** __attribute__((optimize("O0"))) render() {
    Scene* scene     = getDefaultPlane();
    Camera* camera   = scene->camera;
    Surface* surface = scene->surface;
    int32_t* size    = scene->size;
    int32_t  nx      = size[0];
    int32_t  ny      = size[1];

    float*** img = init_nm3(nx, ny, 3);

    float* C_BLACK = (float *)malloc(3*sizeof(float));
    for (int i = 0; i < 3; i++) {
        C_BLACK[i] = 0;
    }

    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            Ray* ray = castRay(camera, i, j, nx, ny);
            HitRecord* hr = hitPlane(surface, ray);
            if (hr == NULL) img[i][j] = C_BLACK;
            img[i][j] = surface->material->color;
        }
    }
    uint32_t hits = 0;
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            if (img[i][j] != C_BLACK) hits++;
        }
    }
    print(itoa(hits));
    return img;
}
