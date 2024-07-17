#include "types.h"

#ifndef FRAMEBUFFER_H
  #define FRAMEBUFFER_H

/* function declarations */
void clear_framebuffer(Framebuffer* framebuffer);

/* function implementations - move to framebuffer.c */
void clear_framebuffer(Framebuffer* framebuffer) {
  /* Calculate the total number of bytes in the framebuffer */
  int num_pixels = framebuffer->width * framebuffer->height;
  int bytes_per_pixel = sizeof(uint8_t); /* Assuming 1 byte per color channel (e.g., grayscale) */
  int total_bytes = num_pixels * bytes_per_pixel;

  /* Set all bytes in the framebuffer data to zero (black) */
  memset(framebuffer->data, 0, total_bytes);
}

void draw_rectangle(Framebuffer* framebuffer, int x1, int y1, int x2, int y2, uint8_t color) {
  /* Clip coordinates to framebuffer boundaries */
  int left = x1 < 0 ? 0 : x1;
  int right = x2 > framebuffer->width - 1 ? framebuffer->width - 1 : x2;
  int top = y1 < 0 ? 0 : y1;
  int bottom = y2 > framebuffer->height - 1 ? framebuffer->height - 1 : y2;

  /* Iterate through each pixel within the rectangle boundaries */
  for (int y = top; y <= bottom; y++) {
    for (int x = left; x <= right; x++) {
      /* Calculate the pixel offset in the framebuffer data array */
      int offset = (y * framebuffer->width + x) * sizeof(uint8_t);

      /* Set the pixel color value in the framebuffer data */
      framebuffer->data[offset] = color;
    }
  }
}

void draw_line(Framebuffer* framebuffer, int x1, int y1, int x2, int y2, uint8_t color) {
  /* Bresenham's line algorithm implementation (basic version) */
  int dx = x2 - x1;
  int dy = y2 - y1;

  /* Step values for x and y based on direction */
  int step_x = (dx > 0) ? 1 : -1;
  int step_y = (dy > 0) ? 1 : -1;

  /* Absolute values of dx and dy for calculations */
  int sx = abs(dx);
  int sy = abs(dy);

  /* Initial error term for Bresenham's algorithm */
  int err = sx / 2;

  /* Loop until reaching the end point */
  for (; x1 != x2 || y1 != y2; x1 += step_x, y1 += step_y) {
    /* Calculate the pixel offset and set the color in the framebuffer data */
    int offset = (y1 * framebuffer->width + x1) * sizeof(uint8_t);
    framebuffer->data[offset] = color;

    /* Update error term based on y movement (if necessary) */
    if (err >= 0) {
      if (dy != 0) {
        y1 += step_y;
        err -= sy;
      }
    }

    /* Update error term based on x movement (if necessary) */
    if (err < sx) {
      if (dx != 0) {
        x1 += step_x;
        err += sx;
      }
    }
  }
}


#endif
