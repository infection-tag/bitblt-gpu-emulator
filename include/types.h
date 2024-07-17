#ifndef TYPES_H
  #define TYPES_H

typedef struct {
    uint8_t* data; /* pointer to actual data */
    int width;
    int height;
} Framebuffer;

#endif
