#ifdef __cplusplus
extern "C" {
#endif
// Declaration of the internal ESP32 temperature sensor function
// This tells the compiler it's a C function, even though the rest of the code is C++
uint8_t temprature_sens_read();
#ifdef __cplusplus
}
#endif

void setup() {
  Serial.begin(115200);  // Initialize serial communication at 115200 baud rate
}

void loop() {
  float raw = temprature_sens_read();       // Read raw temperature value from ESP32’s internal sensor
  float tempC = (raw - 32) / 1.8;           // Convert the raw value (F-like scale) to Celsius using formula

  Serial.print("Internal Temperature: ");   // Print label
  Serial.print(tempC, 1);                   // Print temperature with 1 decimal precision
  Serial.println(" °C");                    // Print degree Celsius unit

  delay(5000);  // Wait 5 seconds before reading again
}
