/**
  COPYRIGHT - 2025 - THE WIMON TEAM
  Contains references to code written by Rui Santos & Sara Santos - Random Nerd Tutorials
*/

#include "rf_module.h"
#include "data.h"

RF24 radio(RF_CE, RF_CSN);
const byte address[6] = "00001";

WiMonPacket receivedData;

void rf_init_for_receiving()
{
    if (!radio.begin())
    {
        Serial.println("NRF24L01 initialization failed!");
        return;
    }
    radio.openReadingPipe(0, address);
    radio.setPALevel(RF24_PA_LOW);
    radio.startListening(); // Only receiving data
    Serial.println("NRF24L01 initialized successfully.");
    delay(10);
}

void rf_init_for_sending()
{
}

WiMonPacket rf_get_data()
{
    receivedData.channel = 0;
    receivedData.temp_C = 0;
    receivedData.spo2 = 0;
    receivedData.is_spo2_max = false;
    receivedData.hr = 0;
    receivedData.device_MAC = 0;

    if (radio.available())
    {
        radio.read(&receivedData, sizeof(WiMonPacket));
        print_wimon_packet(receivedData);
    }
    else
    {
        Serial.println("No data available from RF.");
    }
    return receivedData;
}

void set_channel(uint8_t channel)
{
    radio.setChannel(channel);
    Serial.print("RF Channel set to: ");
    Serial.println(channel);
}

// Binh 's Part

char temp[18];
WiFi.macAddress().toCharArray(temp, sizeof(temp)); // convert ESP "lite" String into char array
// this version transmit and recieve without ackpayload
radio.begin();
radio.setPALevel(RF24_PA_HIGH);
radio.openReadingPipe(1, address[channel]);
radio.openWritingPipe(address[channel]);
// radio for sensor
radio.startListening();
delay(500);
uint8_t pipe_num;
if (radio.available(&pipe_num))
{
    bool handshake;
    radio.read(&handshake, sizeof(handshake));
    if (handshake)
    {
        radio.stopListening();
        WiMonPacket send;
        send.device_MAC = convert_mac(temp);
        send.channel = channel;
        send.temp_C = cast_temp(particleSensor.readTemperature());
        send.spo2 = cast_spo(spo2);
        send.is_spo2_valid = (bool)validSPO2;
        send.hr = heartRate;
        send.is_hr_valid = (bool)validHeartRate;

        radio.write(&send, sizeof(send));
    }
    else
        break;
}