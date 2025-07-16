#define LED 22  // Define GPIO22 as the pin connected to the LED

void setup() {
  pinMode(LED, OUTPUT);  // Set the LED pin as an output
}

void loop() {
  digitalWrite(LED, HIGH);  // Turn the LED ON
  delay(1000);              // Wait for 1 second

  digitalWrite(LED, LOW);   // Turn the LED OFF
  delay(1000);              // Wait for 1 second
}
