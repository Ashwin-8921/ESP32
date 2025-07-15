int pushButton = 0;
int LED = 19;

void setup() {
   // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT_PULLUP); //configure pin as input with pullup enabled   
  pinMode(LED, OUTPUT);              //configure pin as output
}

void loop() {
  // read the input pin:
  int buttonState = digitalRead(pushButton);
  digitalWrite(LED, (!(buttonState)));  //turn led on when switch pressed
  delay(1);                   // delay in between reads for stability
}
