#include "tracer.h"

_Page* PAGE;

int main(uint32_t argc, char** argv) {
    _Page page = page_init();
    PAGE = &page;
    if (argc > 1) run_tests();
    float*** dummy = render();
    uint32_t fd = open("arr_contents.txt", O_CREAT, S_IRUSR | S_IWUSR | S_IROTH);
    for (int i = 0; i < 200; i++) {
    }
    return 0;
}
