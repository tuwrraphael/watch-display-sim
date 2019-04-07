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

#define TIME(HOUR, MINUTE)  \
  {                         \
    .tm_sec = 15,           \
    .tm_min = MINUTE,       \
    .tm_hour = HOUR,        \
    .tm_mday = 24,          \
    .tm_mon = 2,            \
    .tm_year = 2019 - 1900, \
    .tm_isdst = -1          \
  }

#define MINUTES(x) (x * 60)

void time_only()
{
  display_png_t png;
  read_png_file("img/empty.png", &png);
  clear_display_buffer();
  digit_ui_state_t state = DIGIT_UI_STATE_DEFAULT;
  static struct tm current_time = TIME(15, 18);
  state.current_time = mktime(&current_time);
  digit_ui_render(&state);
  write_buffer_display(&png);
  write_png_file("time_only.png", &png);
}

void on_journey_no_legs()
{
  display_png_t png;
  read_png_file("img/empty.png", &png);
  clear_display_buffer();
  digit_ui_state_t state = DIGIT_UI_STATE_DEFAULT;
  static struct tm current_time = TIME(15, 58);
  state.current_time = mktime(&current_time);
  state.event_start_time = state.current_time + (60 * (41));
  state.display_options.directions_active = 1;
  state.directions.arrival_time = state.current_time + (60 * 45);
  state.directions.departure_time = state.current_time - (60 * 5);
  digit_ui_render(&state);
  write_buffer_display(&png);
  write_png_file("on_journey_no_legs.png", &png);
}

void leave_in()
{
  display_png_t png;
  read_png_file("img/empty.png", &png);
  clear_display_buffer();
  digit_ui_state_t state = DIGIT_UI_STATE_DEFAULT;
  static struct tm current_time = TIME(15, 14);
  state.current_time = mktime(&current_time);
  state.event_start_time = state.current_time + (60 * (35));
  state.display_options.directions_active = 1;
  state.display_options.event_active = 1;
  strcpy(&state.event_subject, "Pubquiz");
  state.directions.arrival_time = state.current_time + (60 * 34);
  state.directions.departure_time = state.current_time + (60 * 12);
  digit_ui_render(&state);
  write_buffer_display(&png);
  write_png_file("leave_in.png", &png);
}

void route()
{
  display_png_t png;
  digit_ui_state_t state = DIGIT_UI_STATE_DEFAULT;
  static struct tm ref_time = TIME(19, 1);
  time_t reference_time = mktime(&ref_time);
  state.event_start_time = reference_time + MINUTES(50);
  state.display_options.directions_active = 1;
  state.display_options.event_active = 1;
  strcpy(&state.event_subject, "Pubquiz");
  state.directions.arrival_time = state.event_start_time - MINUTES(3);
  state.directions.departure_time = reference_time - MINUTES(1);
  state.directions.valid_legs = 0b111;
  directions_leg_t legs[] = {
      {.departure_stop = "Wien  Polgreltzstrasse",
       .arrival_stop = "Wien Kagraner Platz",
       .direction = "Wien Kagraner Platz",
       .line = "N25",
       .departure_time = state.directions.departure_time + MINUTES(5)},
      {.departure_stop = "Kagran",
       .arrival_stop = "Karlsplatz",
       .direction = "Oberlaa",
       .line = "U1",
       .departure_time = state.directions.departure_time + MINUTES(16)},
      {.departure_stop = "Karlsplatz",
       .arrival_stop = "Pilgramgasse",
       .direction = "Huetteldorf",
       .line = "U4",
       .departure_time = state.directions.departure_time + MINUTES(36)}};
  state.directions.legs = legs;
  state.directions.legs_count = sizeof(legs) / sizeof(legs[0]);

  state.current_time = state.directions.departure_time - MINUTES(20);
  read_png_file("img/empty.png", &png);
  clear_display_buffer();
  digit_ui_render(&state);
  write_buffer_display(&png);
  write_png_file("route_s0_before_leave.png", &png);

  state.current_time = state.directions.departure_time + MINUTES(1);
  read_png_file("img/empty.png", &png);
  clear_display_buffer();
  digit_ui_render(&state);
  write_buffer_display(&png);
  write_png_file("route_s1_on_way.png", &png);

  for (int i = 0; i < state.directions.legs_count; i++)
  {
    char fileName[30];
    state.current_time = state.directions.legs[i].departure_time + MINUTES(2);
    read_png_file("img/empty.png", &png);
    clear_display_buffer();
    digit_ui_render(&state);
    write_buffer_display(&png);
    sprintf(&fileName, "route_s%d_leg%d.png", i + 2, i);
    write_png_file(&fileName, &png);
  }
}

int main(int argc, char *argv[])
{
  nrf_gfx_init(&nrf_lcd_buffer_display);
  time_only();
  on_journey_no_legs();
  leave_in();
  route();
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