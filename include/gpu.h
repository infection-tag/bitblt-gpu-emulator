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
void gpu();
void render_frame();
#endif
