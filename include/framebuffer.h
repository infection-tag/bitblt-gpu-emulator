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


#endif
