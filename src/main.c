#include "include/gpu.h"

int main() {
    /* prototype of an input stream */
    int filedes = 9;
    FILE* bbout = fdopen(filedes, "w+");
    clear_framebuffer(bbout); /* note to self: change color to black on this */
    
    initialize_gpu();
    render_frame();
    return 0;
}
