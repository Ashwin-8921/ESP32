void setup() {
 Serial.begin(9600); /* Set the baudrate to 9600 */
 delay(500);        /* wait for 0.5 Second */
}

void loop() {
 Serial.println(touchRead(4));  /* get value of Touch 0 pin = GPIO 4 and print on serial monitor */
 delay(1000);                   /* wait for 1 Second */
}