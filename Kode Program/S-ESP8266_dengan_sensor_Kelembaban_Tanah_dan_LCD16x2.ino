#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define MOISTURE_PIN A0
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Alamat I2C 0x27, 16 kolom, 2 baris

void setup() {
  Wire.begin();
  lcd.init();
  lcd.backlight();
}
   
void loop() {
  int moistureValue = analogRead(MOISTURE_PIN);
  moistureValue = map(moistureValue, 0, 1023, 0, 100);
  moistureValue = (moistureValue - 100) * -1;
    
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Kelembaban Tanah");
  lcd.setCursor(0, 1);
  lcd.print("= ");
  lcd.print(moistureValue);
  delay(1000);
}
