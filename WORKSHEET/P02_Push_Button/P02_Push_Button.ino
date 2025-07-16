#define P 5  // Define constant P to represent GPIO pin 5

void setup() {
  // Configure pin 5 as input with internal pull-up resistor
  pinMode(5, INPUT_PULLUP);

  // Initialize serial communication at 9600 baud rate
  Serial.begin(9600);
}

void loop() {
  // Read the digital state of the button connected to pin 5
  int OP = digitalRead(P);

  // Display the button state on the Serial Monitor
  Serial.print("Button Output: ");
  Serial.println(OP);

  // Wait for 1 second before next reading
  delay(1000);
}
