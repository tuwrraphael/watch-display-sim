#include "png.h"

typedef struct
{
    int width;
    png_bytep *row_pointers;
    int height;
} display_png_t;

void write_png_file(char *filename, display_png_t *displayPng);
void read_png_file(char *filename, display_png_t *displayPng);