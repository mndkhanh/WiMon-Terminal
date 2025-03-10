/**
  COPYRIGHT - 2025 - THE WIMON TEAM
  Contains references to code written by Rui Santos & Sara Santos - Random Nerd Tutorials
*/

#include "wimon_structs.h"


// Evaluate the risk of life indexes 
bool is_warning_data(uint8_t spo2, uint16_t hr, float bodyTemp);
bool is_warning_spo2(uint8_t spo2);
bool is_warning_hr(uint16_t hr);
bool is_warning_body_temp(float bodyTemp);


// Print patient information
void print_patient_info(const PatientInfo& patient);

// Print wimon packet data transfered between RFs
void print_wimon_packet(const WiMonPacket& wimon_packet);
