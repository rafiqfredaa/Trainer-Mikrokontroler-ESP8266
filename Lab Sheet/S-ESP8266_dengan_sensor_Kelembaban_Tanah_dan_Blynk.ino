#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL6kKsP-ekJ"
#define BLYNK_DEVICE_NAME "ESP8266test"

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "-cNC1o4v2D17wcpO3ntIcR-t6BqOuKDg";
char ssid[] = "piqstar";
char pass[] = "bismillah";

#define MOISTURE_PIN A0  // Pin ADC untuk sensor kelembapan tanah terhubung ke A0
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Alamat I2C 0x27, 16 kolom, 2 baris

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

  Wire.begin();
  lcd.init();
  lcd.backlight();
}

void loop() {
  Blynk.run();
  int moistureValue = analogRead(MOISTURE_PIN);
  moistureValue = map(moistureValue, 0, 1023, 0, 100);
  moistureValue = (moistureValue - 100) * -1;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Kelembaban Tanah");
  lcd.setCursor(0, 1);
  lcd.print("= ");
  lcd.print(moistureValue);

  Blynk.virtualWrite(V7, moistureValue); // Kirim kelembapan tanah ke Widget V1 pada Blynk
  delay(1000); // Tunggu 1 detik sebelum membaca kembali
}
