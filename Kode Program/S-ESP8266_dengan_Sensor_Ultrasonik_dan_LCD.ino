#include <Wire.h>
#include <LiquidCrystal_I2C.h> // pin SDA (D2) dan pin SCL (D1)
#include <NewPing.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Alamat I2C LCD dan ukuran (16x2) 

const int trigPin = D3;
const int echoPin = D4;

NewPing sonar(trigPin, echoPin, 400);  // Trigger pin, echo pin, dan jarak maksimum (dalam cm)

void setup() {
  Wire.begin();
  lcd.init();
  lcd.backlight(); // Agar background bercahaya
  lcd.setCursor(0, 1);
  lcd.print("Sensor");
}

void loop() {
    int distance = sonar.ping_cm();  // Baca jarak dalam cm
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Jarak: ");
    lcd.print(distance);
    lcd.println(" cm");
    Serial.print(distance);  // pada serial monitor
    delay(1000); // Beri jeda 1 detik sebelum membaca jarak lagi
}
