#ifndef BITBLT_H
  #define BITBLT_H

typedef struct {
    int x, y, width, height;
} Rect;

typedef struct {
    unsigned char r, g, b, a; // Assuming RGBA format
} Pixel;

void blit(int src_x, int src_y, int dst_x, int dst_y, int width, int height, Pixel* src_buffer, Pixel* dst_buffer);
void optimized_blit(int src_x, int src_y, int dst_x, int dst_y, int width, int height, Pixel* src_buffer, Pixel* dst_buffer);

void optimized_blit(int src_x, int src_y, int dst_x, int dst_y, int width, int height, Pixel* src_buffer, Pixel* dst_buffer) {
  // Assuming pixel data is 32-bit RGBA
  int* src_ptr = (int*)(src_buffer + src_y * width + src_x);
  int* dst_ptr = (int*)(dst_buffer + dst_y * width + dst_x);
  int row_stride = width - width % 4; // Optimize for cache lines

  for (int y = 0; y < height; y++) {
    int* src_row = src_ptr + y * row_stride;
    int* dst_row = dst_ptr + y * row_stride;

    // Unroll inner loop for performance
    for (int x = 0; x < width; x += 4) {
      dst_row[x] = src_row[x];
      dst_row[x+1] = src_row[x+1];
      dst_row[x+2] = src_row[x+2];
      dst_row[x+3] = src_row[x+3];
    }
  }
}

/* ADD OTHER FUNCTIONS AS NEEDED */

#endif
