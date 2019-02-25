#include <stdlib.h>
#include <stdio.h>
#include <png.h>
#include <time.h>

#include "png_utils.h"
#include "nrf_gfx.h"
#include "nrf_font.h"
#include "buffer_display.h"
#include "digit_ui_gfx.h"
#include "digit_assets.h"

#include "digit_ui_model.h"
#include "digit_ui.h"

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

static const char *test_text = "7 U2 Aspernstraße";

extern const FONT_INFO roboto_8ptFontInfo;

static const FONT_INFO *p_font = &roboto_8ptFontInfo;

static struct tm current_time = {
    .tm_sec = 15,
    .tm_min = 42,
    .tm_hour = 21,
    .tm_mday = 24,
    .tm_mon = 2,
    .tm_year = 2019 - 1900,
    .tm_isdst = -1};

void time_only()
{
  display_png_t png;
  read_png_file("img/empty.png", &png);
  clear_display_buffer();
  digit_ui_state_t state = DIGIT_UI_STATE_DEFAULT;
  state.current_time = mktime(&current_time);
  digit_ui_render(&state);
  write_buffer_display(&png);
  write_png_file("time_only.png", &png);
}

void no_legs()
{
  display_png_t png;
  read_png_file("img/empty.png", &png);
  clear_display_buffer();
  digit_ui_state_t state = DIGIT_UI_STATE_DEFAULT;
  state.current_time = mktime(&current_time);
  state.event_start_time = state.current_time + (60 * (48));
  state.display_options.directions_active = 1;
  state.directions.arrival_time = state.current_time + (60 * 50);
  state.directions.departure_time = state.current_time + (60 * 28);
  digit_ui_render(&state);
  write_buffer_display(&png);
  write_png_file("no_legs.png", &png);
}

void leave_in()
{
  display_png_t png;
  read_png_file("img/empty.png", &png);
  clear_display_buffer();
  // digit_ui_state_t state = DIGIT_UI_STATE_DEFAULT;
  // state.current_time = mktime(&current_time);
  // state.event_start_time = state.current_time + (60 * 48);
  // state.display_options.directions_active = 1;
  // state.directions.arrival_time = state.current_time + (60 * 45);
  // state.directions.departure_time = state.current_time + (60 * 5);
  // digit_ui_render(&state);
  draw_time_indicator(34,35,2);
  nrf_gfx_point_t text_start = NRF_GFX_POINT(15 + 12 + 1, 70);
  // nrf_gfx_rect_t rect = NRF_GFX_RECT(14, 29, 20, 20);
  // nrf_gfx_rect_draw(&nrf_lcd_buffer_display, &rect, 1, 1, false);
  nrf_gfx_print(&nrf_lcd_buffer_display, &text_start, 1, test_text, p_font, true);
  // render_packed_image(&icon_public_transport, 15, 69);
  

  write_buffer_display(&png);
  write_png_file("test.png", &png);
}

int main(int argc, char *argv[])
{
  nrf_gfx_init(&nrf_lcd_buffer_display);
  time_only();
  no_legs();
  leave_in();
  // draw_time_indicator(7, 25, 1);
  // draw_time_indicator(27, 40, 1);
  // draw_time_indicator(46, 40, 1);
  // nrf_gfx_point_t text_start = NRF_GFX_POINT(15 + 12 + 1, 30);
  // nrf_gfx_rect_t rect = NRF_GFX_RECT(14, 29, 20, 20);
  // // nrf_gfx_rect_draw(&nrf_lcd_buffer_display, &rect, 1, 1, false);
  // nrf_gfx_print(&nrf_lcd_buffer_display, &text_start, 1, test_text, p_font, true);
  // render_packed_image(&icon_public_transport, 15, 29);

  return 0;
}