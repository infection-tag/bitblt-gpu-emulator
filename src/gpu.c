#include "../include/gpu.h"

void initialize_gpu() {
    /* initialize framebuffer */
    static Framebuffer framebuffer;
    framebuffer.width = 320;
    framebuffer.height = 240;
    framebuffer.data = malloc(framebuffer.width * framebuffer.height * sizeof(uint8_t));
    
    memset(framebuffer.data, 0, framebuffer.width * framebuffer.height * sizeof(uint8_t));
}

void gpu(Framebuffer* framebuuffer) {
    while(true) { render_frame(); }
}

void render_frame() {
    /* Draw a rectangle */
    draw_rectangle(10, 10, 50, 80, 0xFF0000); /* Red */
  
    /* Draw a line */
    draw_line(20, 50, 80, 20, 0x00FF00);  /* Green */
}
