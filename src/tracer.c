#include "tracer.h"

_Page* PAGE;

int main(uint32_t argc, char** argv) {
    _Page page = page_init();
    PAGE = &page;
    if (argc > 1) {
        print("ran\n");
        run_tests();
    }
    print("did not run\n");
}
