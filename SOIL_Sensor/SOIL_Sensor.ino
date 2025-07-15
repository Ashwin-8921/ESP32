#define SOIL_SENSOR 27

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Soil Sensor =");
  Serial.println(analogRead(SOIL_SENSOR));
  delay(3000);
}
