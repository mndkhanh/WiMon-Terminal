/**
  COPYRIGHT - 2025 - THE WIMON TEAM
  Contains references to code written by Rui Santos & Sara Santos - Random Nerd Tutorials
*/

#ifndef WIMON_STRUCTS_H // Aims to prevent re-include
#define WIMON_STRUCTS_H


#include <stdint.h>
#include <Arduino.h>

// Định nghĩa cái dữ liệu truyền đi giữa các RF, giữa terminal với server
struct WiMonPacket {
  uint8_t channel;  // The channel can be changed from 0-255 to use with different WiMon terminals
  uint16_t temp_C;  // temperature is stored as a fixed point real number with 3 decimal places (ie: 35000 translates to 35.000*C)
  uint8_t spo2;     // SPO2 is stored as a fixed point real number with 1 decimal place when the oxygen saturation is below 100%, whether saturation is 100% is determined by the followed bit
  bool is_spo2_max;
  uint16_t hr;          // the heartrate is stored as a fixed point real number with 2 decimal place with range 0-655.36BPM  (15002 translates to 150.02BPM)
  uint64_t device_MAC;  // This value is generated on startup for handshaking purposes with the terminal and ensuring data integrity
};

// Định nghĩa Struct cho thông tin bệnh nhân
struct PatientInfo {
  String patientID;
  String name;
  String gender;
  int age;
  unsigned long checkInDate;
  unsigned long checkOutDate;
  bool error;
};

#endif

