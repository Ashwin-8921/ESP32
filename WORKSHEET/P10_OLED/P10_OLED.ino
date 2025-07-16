#include <Wire.h>                      // Library for I2C communication
#include <Adafruit_GFX.h>             // Graphics library for OLED
#include <Adafruit_SSD1306.h>         // OLED display driver

#define SCREEN_WIDTH 128              // OLED display width in pixels
#define SCREEN_HEIGHT 64              // OLED display height in pixels
#define POT_PIN 32                    // GPIO pin connected to potentiometer

// Create OLED display object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600);                 // Start serial communication

  // Initialize OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED not found");
    while (1);                        // Stay here if OLED is not connected
  }

  display.clearDisplay();            // Clear the display
  display.setTextSize(1);            // Set text size to small
  display.setTextColor(SSD1306_WHITE); // Set text color to white
  display.setCursor(0, 0);           // Set cursor at top-left corner
  display.println("POTENTIOMETER READING:");
  display.display();                 // Show the above text on the screen

  pinMode(POT_PIN, INPUT);           // Set potentiometer pin as input
}

void loop() {
  int POT_IN = analogRead(POT_PIN);   // Read analog value from potentiometer

  // Clear previous value area
  display.fillRect(0, 10, SCREEN_WIDTH, 10, SSD1306_BLACK);

  display.setCursor(0, 10);           // Set cursor below the title
  display.setTextSize(1);             // Set text size
  display.setTextColor(SSD1306_WHITE); // Set text color
  display.print("Value: ");
  display.println(POT_IN);            // Show analog value on screen
  display.display();                  // Refresh display with new value
}
