#define RELAY_PIN 5  // Define GPIO5 as the pin connected to the relay's control input

void setup() {
  pinMode(RELAY_PIN, OUTPUT);  // Set the relay pin as an output to control the relay
}

void loop() {
  digitalWrite(RELAY_PIN, HIGH);  // Turn ON the relay (activates the connected circuit)
  delay(1000);                    // Wait for 1 second

  digitalWrite(RELAY_PIN, LOW);   // Turn OFF the relay (deactivates the circuit)
  delay(1000);                    // Wait for 1 second before repeating
}
