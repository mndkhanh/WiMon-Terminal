// /**
//   COPYRIGHT - 2025 - THE WIMON TEAM
//   Contains references to code written by Rui Santos & Sara Santos - Random Nerd Tutorials
// */
// #pragma once

// #include <lvgl.h>
// #include <TFT_eSPI.h>
// #include <XPT2046_Touchscreen.h>

// // Remember to set logging level to 0 for prod.
// //TODO: get actual pin out for TFT and Touch Controller
// // Touch panel specific pin
// #define TOUCH_IRQ 17
// #define TOUCH_CS 21  // Chip select pin (T_CS) of touch screen

// // Common pins redeclared from TFT_eSPI lib.
// #define TFT_MISO 19
// #define TFT_MOSI 23
// #define TFT_SCLK 18
// #define TFT_CS 15
// #define TFT_DC 2    // Data Command control pin
// #define TFT_RST -1  // RST is connected to ESP32 EN (RST pin)


// #define SCREEN_WIDTH 320
// #define SCREEN_HEIGHT 480
// #define FONT_SIZE 2

// void wm_init_screen(void);

// void lv_create_main_gui(void);
// void lv_touch_read(lv_indev_t* touchscreen, lv_indev_data_t* data);
// void lv_log_cb(lv_log_level_t level, const char* buf);

