#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "types.h"
#include "framebuffer.h"
#include "memory.h"

#ifndef GPU_H
  #define GPU_H

/* function declarations */

void initialize_gpu();
void render_frame();

/* function implementations - move to gpu.c */

void initialize_gpu() {
    /* initialize framebuffer */
    static Framebuffer framebuffer;
    framebuffer.width = 320;
    framebuffer.height = 240;
    framebuffer.data = malloc(framebuffer.width * framebuffer.height * sizeof(uint8_t));

    memset(framebuffer.data, 0, framebuffer.width * framebuffer.height * sizeof(uint8_t));
}

#endif
