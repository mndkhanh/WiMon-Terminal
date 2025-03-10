// #include <stdint.h>
// /**
//   COPYRIGHT - 2025 - THE WIMON TEAM
//   Contains references to code written by Rui Santos & Sara Santos - Random Nerd Tutorials
// */

// #include "screen.h"

// lv_obj_t* chann_next_btn;
// lv_obj_t* chann_prev_btn;
// lv_obj_t* spo2_label_btn;

// XPT2046_Touchscreen touch(TOUCH_CS, TOUCH_IRQ);
// SPIClass spi(VSPI);

// uint16_t t_x, t_y, t_pres;
// lv_display_t* lv_screen;

// uint16_t lv_draw_buf_sz = 

// // Info
// String LV_VERSION_STRING = String("LVGL Library Version: ") + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();

// void touch_read(lv_indev_t* touchscreen, lv_indev_data_t* data) {
//   if (touch.tirqTouched() && touch.touched()) {
//     TS_Point p = touch.getPoint();
//     t_x = map(p.x, 200, 3700, 1, SCREEN_WIDTH);
//     // the Y coordinate is reversed due to quirk with RPi disp
//     t_y = map(3800 - p.y, 240, 3800, 1, SCREEN_HEIGHT);
//     t_pres = p.z;

//     data->point.x = t_x;
//     data->point.y = t_y;
//     data->state = LV_INDEV_STATE_PRESSED;

//   }
//   else {
//     data->state = LV_INDEV_STATE_RELEASED;
//   }
// }

// void lv_log_cb(lv_log_level_t level, const char* buf) {
//   LV_UNUSED(level);
//   Serial.println(buf);
//   Serial.flush();
// }

// void lv_create_main_gui(void) {
//   // Create a text label aligned center on top ("Hello, world!")
//   lv_obj_t* text_label = lv_label_create(lv_screen_active());
//   lv_label_set_long_mode(text_label, LV_LABEL_LONG_WRAP);  // Breaks the long lines
//   lv_label_set_text(text_label, "Hello, world!");
//   lv_obj_set_width(text_label, 150);  // Set smaller width to make the lines wrap
//   lv_obj_set_style_text_align(text_label, LV_TEXT_ALIGN_CENTER, 0);
//   lv_obj_align(text_label, LV_ALIGN_CENTER, 0, -90);
// }


// void wm_init_screen(void){
//   lv_init();
//   Serial.println(LVGL_VERSION_INFO);

//   spi.begin(TFT_SCLK, TFT_MISO, TFT_MOSI, TOUCH_CS);
//   touch.begin(spi);
//   touch.setRotation(1);

//   // Initialize lvgl
//   lv_init();
//   lv_log_register_print_cb(lv_log_cb);
//   lv_screen = lv_tft_espi_create(SCREEN_WIDTH, SCREEN_HEIGHT, draw_buf);

// }





















