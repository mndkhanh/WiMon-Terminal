/**
  COPYRIGHT - 2025 - THE WIMON TEAM
  Contains references to code written by Rui Santos & Sara Santos - Random Nerd Tutorials
*/

#include "blynk_header.h"

String wifi_ssid = "Hồng Phong";
String wifi_password = "0905895779";

char auth[] = BLYNK_AUTH_TOKEN;


// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED() {
  Serial.println("Connected to Blynk Cloud!");
}

void bl_connect_server() {
  WiFi.begin(wifi_ssid.c_str(), wifi_password.c_str());

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected to WiFi!");
  Blynk.config(auth);
  Blynk.connect();
}
bool bl_is_connected() {
  return Blynk.connected();
}
void bl_set_ssid(String new_ssid) {
  wifi_ssid = new_ssid;
}
void bl_set_password(String new_password) {
  wifi_password = new_password;
}
String bl_get_ssid() {
  return wifi_ssid;
}
String bl_get_password() {
  return wifi_password;
}

// Below codes are used to read data from certain pins and send it to end point google sheet
// SAMPLE DATA WHEN POSTING
// const postData = {
//   action: "append",
//   requestTime: Date.now(), // Lấy timestamp dạng số (milliseconds)
//   patientID: "P0002",
//   spO2: 98,
//   HR: 72,
//   bodyTemp: 37,
//   wimonMAC: "00:1A:2B:3C:4D:5E"
// };
void gs_post_patient_data(uint8_t spo2, uint16_t hr, float bodyTemp, const char* patientID, uint64_t wimonMAC) {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi not connected!");
    return;
  }

  HTTPClient http;
  http.begin(GG_SHEET_API);
  http.addHeader("Content-Type", "application/json");

  // Tạo JSON object
  StaticJsonDocument<256> jsonDoc;
  jsonDoc["action"] = "append";
  jsonDoc["requestTime"] = millis();  // Sử dụng millis() làm timestamp
  jsonDoc["patientID"] = patientID;
  jsonDoc["spO2"] = spo2;
  jsonDoc["HR"] = hr;
  jsonDoc["bodyTemp"] = bodyTemp;
  jsonDoc["wimonMAC"] = String(wimonMAC, HEX);  // Chuyển MAC thành chuỗi HEX

  String jsonPayload;
  serializeJson(jsonDoc, jsonPayload);

  // Gửi POST request
  int httpResponseCode = http.POST(jsonPayload);
  String response = http.getString();

  Serial.print("HTTP Response Code: ");
  Serial.println(httpResponseCode);
  Serial.print("Response: ");
  Serial.println(response);

  http.end();
}

// SAMPLE URL WHEN GET PATIENT INFO BY ID
// Response: {
//   data: {
//     patientID: 'P0003',
//     name: 'Đắc Bình',
//     gender: 'Male',
//     age: 20,
//     checkInDate: 1740330000000,
//     checkOutDate: 1741280400000
//   },
//   error: false
// }
PatientInfo gs_get_patient_info_by_id(const char* patientID) {
  PatientInfo patient;
  patient.error = true;  // Mặc định lỗi trừ khi có dữ liệu hợp lệ

  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi not connected!");
    return patient;
  }

  HTTPClient http;
  String requestURL = String(GG_SHEET_API) + "?action=getPatientInfoByID&patientID=" + patientID;
  http.begin(requestURL);

  int httpResponseCode = http.GET();
  if (httpResponseCode > 0) {
    String response = http.getString();
    Serial.println("Response: " + response);

    // Phân tích JSON
    StaticJsonDocument<256> jsonDoc;
    DeserializationError error = deserializeJson(jsonDoc, response);
    if (!error) {
      patient.patientID = jsonDoc["data"]["patientID"].as<String>();
      patient.name = jsonDoc["data"]["name"].as<String>();
      patient.gender = jsonDoc["data"]["gender"].as<String>();
      patient.age = jsonDoc["data"]["age"].as<int>();
      patient.checkInDate = jsonDoc["data"]["checkInDate"].as<unsigned long>();
      patient.checkOutDate = jsonDoc["data"]["checkOutDate"].as<unsigned long>();
      patient.error = false;  // Thành công
    } else {
      Serial.println("JSON parsing failed!");
    }
  } else {
    Serial.print("HTTP Request failed, error: ");
    Serial.println(httpResponseCode);
  }

  http.end();
  return patient;
}


