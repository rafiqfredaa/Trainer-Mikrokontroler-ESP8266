#include <Wire.h>
#include <MQ135.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Alamat I2C modul LCD 16x2
const int analogPin = A0; // Pin analog untuk membaca sensor
MQ135 gasSensor = MQ135(analogPin);

void setup() {
  Wire.begin();
  lcd.init();  // Inisialisasi LCD 16x2
  lcd.backlight();   // Nyalakan backlight LCD
}

void loop() {
  float ppm = gasSensor.getPPM();  
  lcd.clear();         // Menghapus tampilan sebelumnya
  lcd.setCursor(0, 0); //Mengatur posisi kursor ke baris 1 kolom 1
  lcd.print("PPM: ");  // Menampilkan label
  lcd.print(ppm);      // Menampilkan nilai PPM
  delay(1000);         // Jeda 1 detik
}
