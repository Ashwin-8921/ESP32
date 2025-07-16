#include <WiFi.h>  // Include the Wi-Fi library for ESP32

const char* ssid = "WIFI_Network";           // Wi-Fi name
const char* password = "12345678";   // Wi-Fi password

void setup() {
  Serial.begin(9600);                  // initialize serial terminal

  WiFi.begin(ssid, password);            // Start connecting to Wi-Fi

  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {  // Keep checking until connected
    delay(500);                           // Wait half a second
    Serial.print(".");                    // Print dots to show progress
  }

  Serial.println("\nWiFi connected!");     // Print when connected
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());         // Show ESP32’s IP address
}

void loop() {
  // Nothing needed here for this task
}
