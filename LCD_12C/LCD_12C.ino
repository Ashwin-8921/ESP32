#include <Wire.h> 
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup(){
  lcd.init();        // initialize the lcd 
  lcd.backlight();  //turn on backlight

}

void loop(){
  lcd.setCursor(0,0);  //set cursor to line 1
  lcd.print("First line"); //print first line
  delay(3000);
  lcd.setCursor(0,1);  //set cursor to line 1
  lcd.print("second line"); //print second line 
  delay(3000);
  lcd.clear();  //clear LCD

}