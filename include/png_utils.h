#include "png.h"

typedef struct {
    int width;
    int
}

void write_png_file(char *filename, png_bytep *row_pointers);
png_bytep *read_png_file(char *filename);