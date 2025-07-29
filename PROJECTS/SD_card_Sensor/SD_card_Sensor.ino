#include <SPI.h>
#include <SD.h>

const int TRIG_PIN 12;
const int ECHO_PIN = 14;
const int CS = 5;
long duration, distance_cm;
File myFile;

void WriteFile(const char * path, const char * message, long data) {
  myFile = SD.open(path, FILE_WRITE);
  if (myFile) {
    Serial.printf("Writing to %s ", path);
    myFile.print(message);
    myFile.println(data);
    myFile.close();
    Serial.println("completed.");
  } else {
    Serial.println("error opening file ");
    Serial.println(path);
  }
}

void ReadFile(const char * path) {
  myFile = SD.open(path);
  if (myFile) {
    Serial.printf("Reading file from %s\n", path);
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    myFile.close();
  } else {
    Serial.println("error opening test.txt");
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  delay(500);
  while (!Serial) { ; }
  Serial.println("Initializing SD card...");
  if (!SD.begin(CS)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance_cm = duration / 29 / 2;

  WriteFile("/sensor.txt", "Distance: ", distance_cm);
  ReadFile("/sensor.txt");

  Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  delay(1000);
}
