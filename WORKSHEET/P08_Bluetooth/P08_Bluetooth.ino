#include "BluetoothSerial.h"  // Include Bluetooth Serial library for ESP32

BluetoothSerial ESP_BT;  // Create a BluetoothSerial object named ESP_BT

void setup() {
  Serial.begin(9600);              // Start serial communication with PC at 9600 baud
  ESP_BT.begin("ESP32_BT");        // Start Bluetooth with the name "ESP32_BT"
  Serial.println("Bluetooth Started! Pair with 'ESP32_BT' on your phone");
}

void loop() {
  // Send message to phone every 2 seconds
  ESP_BT.println("Hello from Ashwin's ESP32!");
  delay(2000);  // Wait for 2 seconds

  // Check if data is received from the phone
  if (ESP_BT.available()) {
    char incomingChar = ESP_BT.read();  // Read one character from Bluetooth
    Serial.print("Received via Bluetooth: ");
    Serial.println(incomingChar);       // Print received character to serial monitor
  }
}
