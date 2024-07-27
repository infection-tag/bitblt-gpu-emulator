#include "types.h"

#ifndef FRAMEBUFFER_H
  #define FRAMEBUFFER_H

/* function declarations */
void clear_framebuffer(Framebuffer* framebuffer);
void draw_line(Framebuffer* framebuffer, int x1, int y1, int x2, int y2, uint8_t color);
void draw_line(Framebuffer* framebuffer, int x1, int y1, int x2, int y2, uint8_t color);

#endif
