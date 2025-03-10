/**
  COPYRIGHT - 2025 - THE WIMON TEAM
  Contains references to code written by Rui Santos & Sara Santos - Random Nerd Tutorials
*/

#include <data.h>

// Print patient information
void print_patient_info(const PatientInfo& patient) {
  Serial.println("=== Patient Information ===");
  Serial.print("Patient ID: ");
  Serial.println(patient.patientID);

  Serial.print("Name: ");
  Serial.println(patient.name);

  Serial.print("Gender: ");
  Serial.println(patient.gender);

  Serial.print("Age: ");
  Serial.println(patient.age);

  Serial.print("Check-in Date: ");
  Serial.println(patient.checkInDate);

  Serial.print("Check-out Date: ");
  Serial.println(patient.checkOutDate);

  Serial.print("Error: ");
  Serial.println(patient.error ? "Yes" : "No");

  Serial.println("==========================");
}

void print_wimon_packet(const WiMonPacket& wimon_packet) {
  Serial.println("=== WiMon Packet Data ===");

  Serial.print("Channel: ");
  Serial.println(wimon_packet.channel);

  Serial.print("Body Temperature: ");
  Serial.print(wimon_packet.temp_C / 1000.0, 3);
  Serial.println(" °C");

  Serial.print("SPO2: ");
  Serial.print(wimon_packet.spo2);
  Serial.println("%");

  Serial.print("Is SPO2 max?: ");
  Serial.println(wimon_packet.is_spo2_max ? "Yes" : "No");

  Serial.print("Heart Rate: ");
  Serial.print(wimon_packet.hr / 100.0, 2);
  Serial.println(" BPM");

  Serial.print("Device MAC: ");
  Serial.printf("%02X:%02X:%02X:%02X:%02X:%02X\n",
                (uint8_t)(wimon_packet.device_MAC >> 40),
                (uint8_t)(wimon_packet.device_MAC >> 32),
                (uint8_t)(wimon_packet.device_MAC >> 24),
                (uint8_t)(wimon_packet.device_MAC >> 16),
                (uint8_t)(wimon_packet.device_MAC >> 8),
                (uint8_t)(wimon_packet.device_MAC));

  Serial.println("==========================");
}
