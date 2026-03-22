#ifndef MEM_H_
#define MEM_H_
#include "types.h"
#include "syscalls.h"

#define PROT_READ 1
#define PROT_WRITE 2
#define MAP_PRIVATE 2
#define MAP_ANONYMOUS 32
#define MAP_FAILED (void *) -1

#define DEFAULT_PAGE_SIZE 1024*1024*512

void* malloc(size_t size);
void free(void* mem);

typedef struct {
    void*  page_start;
    void*  page_end;
    size_t page_size;
} _Page;

_Page page_init();

extern _Page* PAGE;

#endif /*MEM_H_*/
