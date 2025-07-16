#define POT_PIN 32  // Define GPIO32 as the pin connected to the potentiometer's wiper (middle pin)

void setup() {
  pinMode(POT_PIN, INPUT);    // Configure the potentiometer pin as input
  Serial.begin(9600);         // Start serial communication at 9600 baud rate
}

void loop() {
  int POT_OP = analogRead(POT_PIN);  // Read analog value from the potentiometer (range: 0 to 4095)

  Serial.print("Potentiometer Output: ");  // Print label to Serial Monitor
  Serial.println(POT_OP);                  // Print the actual analog value

  delay(1000);  // Wait for 1 second before the next reading
}
