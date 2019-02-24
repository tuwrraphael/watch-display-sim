#include <stdlib.h>
#include <stdio.h>
#include <png.h>

#include "png_utils.h"
#include "nrf_gfx.h"
#include "nrf_font.h"
#include "buffer_display.h"
#include "digit_ui_gfx.h"
#include "digit_assets.h"

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

static const char *test_text = "5 U1 Karlsplatz";

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
  nrf_gfx_point_t text_start = NRF_GFX_POINT(15 + 12 + 1, 30);
  nrf_gfx_rect_t rect = NRF_GFX_RECT(14, 29, 20, 20);
  // nrf_gfx_rect_draw(&nrf_lcd_buffer_display, &rect, 1, 1, false);
  nrf_gfx_print(&nrf_lcd_buffer_display, &text_start, 1, test_text, p_font, true);
  render_packed_image(&icon_public_transport, 15, 29);
  write_buffer_display(&png);

  write_png_file("out.png", &png);

  return 0;
}