#include <WiFi.h>
#include <HTTPClient.h>
#include "DHT.h"

#define DHTPIN 15       // Connect DHT22 to GPIO15
#define DHTTYPE DHT22   // Define sensor type

const char* ssid = "WIFI_NETWORK";           // Replace with your WiFi SSID
const char* password = "1234567890";   // Replace with your WiFi password

String apiKey = "R5VANS83S3TKA8R";           // Replace with your ThingSpeak Write API Key

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi");
}

void loop() {
  float temperature = dht.readTemperature();

  if (isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.println(temperature);

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = "http://api.thingspeak.com/update?api_key=" + apiKey + "&field1=" + String(temperature);
    
    http.begin(url);
    int httpCode = http.GET();
    
    if (httpCode > 0) {
      Serial.print("ThingSpeak Response Code: ");
      Serial.println(httpCode);
    } else {
      Serial.println("Error sending data.");
    }
    http.end();
  }

  delay(15000);  // ThingSpeak accepts updates every 15 seconds
}
