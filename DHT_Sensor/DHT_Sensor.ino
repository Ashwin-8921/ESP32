#include "DHT.h" //include DHT sensor library


// Create a DHT sensor object on pin 2, using DHT11 ty
DHT dht2(2,DHT11); 


float Humidity, Temperature; // declare humidity,temperature variable to store data

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  // Start Serial Monitor at 9600 baud rate
  Serial.print("Humidity\tTemparature\n"); 
}

void loop() {
  // put your main code here, to run repeatedly:
   
   Temperature=dht2.readTemperature();  // read temperature
   Humidity=dht2.readHumidity();     //read humidity
   if (!isnan(Temperature)  &&  !isnan(Humidity))  //check if sensor readings are valid
   {
      Serial.print(Humidity, 1);  // print humidity with 1 decimal value
      Serial.print("\t\t");
      Serial.println(Temperature, 1); // print temperature with 1 decimal value 
      delay(1000); // delay of 1 sec
   }



}
