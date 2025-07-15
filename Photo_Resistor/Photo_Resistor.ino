void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);// initialize serial terminal
  Serial.println("LDR DATA:\n");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(15)); // print value from photo resistor
  delay(1000);
}
