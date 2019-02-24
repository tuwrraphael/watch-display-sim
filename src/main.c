#include <stdlib.h>
#include <stdio.h>
#include <png.h>

#include "png_utils.h"

void process_png_file(display_png_t *displayPng)
{
  for (int y = 0; y < 128; y++)
  {
    png_bytep row = displayPng->row_pointers[y];
    for (int x = 0; x < 128; x++)
    {
      png_bytep px = &(row[x * 4]);
      px[0] = 15;
      // Do something awesome for each pixel here...
      //printf("%4d, %4d = RGBA(%3d, %3d, %3d, %3d)\n", x, y, px[0], px[1], px[2], px[3]);
    }
  }
}

int main(int argc, char *argv[])
{
  display_png_t png;
  read_png_file("img/empty.png", &png);
  process_png_file(&png);
  write_png_file("out.png", &png);
  return 0;
}