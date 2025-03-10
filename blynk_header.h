/**
  COPYRIGHT - 2025 - THE WIMON TEAM
  Contains references to code written by Rui Santos & Sara Santos - Random Nerd Tutorials
*/
#include "config.h"
#include <BlynkSimpleEsp32.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "wimon_structs.h"
#include <WiFi.h>
#include <Arduino.h>

// Connnect to Blynk
void bl_connect_server();
bool bl_is_connected();
void bl_set_ssid(String new_ssid);
void bl_set_password(String new_password);
String bl_get_ssid();
String bl_get_password();


// Connect to google sheet
void gs_post_patient_data(uint8_t spo2, uint16_t hr, float bodyTemp, const char* patientID, uint64_t wimonMAC);
PatientInfo gs_get_patient_info_by_id(const char* patientID);






