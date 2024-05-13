#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN D4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27,16,2); // Alamat I2C 0x27, 16 kolom, 2 baris

void setup() {
      dht.begin();
      Wire.begin();
      lcd.init();
      lcd.backlight();
    }
    
void loop() {
      lcd.clear();
      float humidity = dht.readHumidity();
      float temperature = dht.readTemperature();
    
      lcd.setCursor(0, 0);
      lcd.print("Humidity: ");
      lcd.print(humidity);
      lcd.print("%");

      lcd.setCursor(0, 1);
      lcd.print("Suhu: ");
      lcd.print(temperature);
      lcd.print("C");
      delay(1000);
    }
