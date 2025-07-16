#include "BluetoothSerial.h"  // Bluetooth communication header for ESP32

BluetoothSerial SerialBT;     // Instantiate BluetoothSerial object

void setup() {
  Serial.begin(115200);               // Initialize UART communication with PC
  SerialBT.begin("ESP32_bluetooth");  // Initialize Bluetooth with custom device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  if (Serial.available()) {    //check if data is available in the serial terminal
    SerialBT.write(Serial.read());    // Send data over Bluetooth
  }

  if (SerialBT.available()) {  // //check if data is available from Bluetooth
    Serial.write(SerialBT.read());    // print the data in serial terminal
  }

  delay(50);  //delay
}
