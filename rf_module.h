/**
  COPYRIGHT - 2025 - THE WIMON TEAM
  Contains references to code written by Rui Santos & Sara Santos - Random Nerd Tutorials
*/

// include lib
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "wimon_structs.h"

/** 
 * FOR ARDUINO UNO
 * pins on rf24
 * VCC - 3.3V
 * GND - GND
 * CSN - 8
 * CE - 7
 * SCK - 13 SPI default
 * MOSI - 11 SPI
 * MISO - 12 SPI
 */ 
// define pins
#define RF_CSN 8
#define RF_CE 7
#define RF_SCK 13
#define RF_MOSI 11 
#define RF_MISO 12

void rf_init_for_receiving();
void rf_init_for_sending();
WiMonPacket rf_get_data();

void set_channel(uint8_t channel);



