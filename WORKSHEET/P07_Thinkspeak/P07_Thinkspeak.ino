#include <WiFi.h>          // Wi-Fi library for ESP32
#include <HTTPClient.h>    // To send HTTP requests
#include "DHT.h"           // DHT sensor library

#define DHTPIN 15          // DHT sensor connected to GPIO 15
#define DHTTYPE DHT22      // Using DHT22 sensor

// Wi-Fi credentials
const char* ssid = "WIFI_NETWORK";       //  Wi-Fi SSID
const char* password = "1234567890";     //  Wi-Fi password

// ThingSpeak Write API Key 
String apiKey = "R5VANS83S3TKA8R";

DHT dht(DHTPIN, DHTTYPE);  // Create DHT object

void setup() {
  Serial.begin(9600);      // Start Serial Monitor
  dht.begin();             // Initialize DHT sensor

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");     // Print dots while connecting
  }
  Serial.println("\nConnected to WiFi");
}

void loop() {
  float temperature = dht.readTemperature();  // Read temperature in Celsius

  // Check if reading failed
  if (isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;  // Skip the rest of the loop
  }

  // Print temperature to Serial Monitor
  Serial.print("Temperature: ");
  Serial.println(temperature);

  // If Wi-Fi is still connected, send data to ThingSpeak
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;  // Create HTTP client

    // Create URL with API key and temperature value
    String url = "http://api.thingspeak.com/update?api_key=" + apiKey + "&field1=" + String(temperature);
    
    http.begin(url);               // Start HTTP request
    int httpCode = http.GET();    // Send GET request

    // Check if request was successful
    if (httpCode > 0) {
      Serial.print("ThingSpeak Response Code: ");
      Serial.println(httpCode);
    } else {
      Serial.println("Error sending data.");
    }

    http.end();  // Close HTTP connection
  }

  delay(15000);  // Wait 15 seconds before next update (ThingSpeak limit)
}
