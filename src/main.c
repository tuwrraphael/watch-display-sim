#include <stdlib.h>
#include <stdio.h>
#include <png.h>

#include "png_utils.h"
#include "nrf_gfx.h"
#include "nrf_font.h"
#include "buffer_display.h"
#include "math.h"
#define M_PI (3.14159265358979323846)

void write_buffer_display(display_png_t *displayPng)
{
  for (int m_y = 0; m_y < 128; m_y++)
  {
    png_bytep row = displayPng->row_pointers[m_y];
    for (int m_x = 0; m_x < 128; m_x++)
    {
      png_bytep px = &(row[m_x * 4]);
      if (px[0] != 0 && px[1] != 0 && px[2] != 0)
      {
        uint16_t x = 128 - m_y;
        uint16_t y = m_x;
        uint16_t index = 4 * y + (x / 32);
        uint32_t mask = (1 << x % 32);
        if (0 == (display_buffer[index] & mask))
        {
          px[0] = 0;
          px[1] = 0;
          px[2] = 0;
        }
      }
    }
  }
}

void draw_time_indicator(float s, float indicator_length, uint8_t thickness)
{

  float arg = ((float)(15 - s) * M_PI) / ((float)30);
  uint8_t x = 64.0f + (cos(arg) * indicator_length);
  uint8_t y = 64.0f - (sin(arg) * indicator_length);
  if (x < 64 || y < 64)
  {
    nrf_gfx_line_t line = NRF_GFX_LINE(
        x,
        y,
        64,
        64, thickness);
    (nrf_gfx_line_draw(&nrf_lcd_buffer_display, &line, 1));
  }
  else
  {
    nrf_gfx_line_t line = NRF_GFX_LINE(
        64,
        64,
        x,
        y, thickness);
    (nrf_gfx_line_draw(&nrf_lcd_buffer_display, &line, 1));
  }
}

static const char *test_text = "Hello watch sim!";

extern const FONT_INFO roboto_8ptFontInfo;

static const FONT_INFO *p_font = &roboto_8ptFontInfo;

int main(int argc, char *argv[])
{
  display_png_t png;
  read_png_file("img/empty.png", &png);
  nrf_gfx_init(&nrf_lcd_buffer_display);
  draw_time_indicator(7, 25, 1);
  draw_time_indicator(27, 40, 1);
  draw_time_indicator(46, 40, 1);
  nrf_gfx_point_t text_start = NRF_GFX_POINT(15, 30);
  nrf_gfx_print(&nrf_lcd_buffer_display, &text_start, 1, test_text, p_font, true);
  write_buffer_display(&png);

  write_png_file("out.png", &png);

  return 0;
}