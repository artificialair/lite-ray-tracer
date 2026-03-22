#include "mem.h"

void* __attribute__((optimize("O0"))) malloc(size_t size) {
    if ((PAGE->page_end + size) > (PAGE->page_start + PAGE->page_size)) return MAP_FAILED;
    int size_of_block = size*sizeof(uint8_t);
    if (PAGE->page_start == NULL); /*tbi functionality*/
    void* malloc_world = PAGE->page_end;
    PAGE->page_end = (void *)((char *) PAGE->page_end + size);
    return malloc_world;
}

void free(void* mem) {
    ; /* who needs to free? */
    return;
}

_Page page_init() {
    void* page_mem;
    size_t page_size = DEFAULT_PAGE_SIZE;
    page_mem = mmap(0, page_size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    _Page page = {
        .page_start  = page_mem, 
        .page_size = page_size,
        .page_end  = page_mem,
    };
    return page;
}

