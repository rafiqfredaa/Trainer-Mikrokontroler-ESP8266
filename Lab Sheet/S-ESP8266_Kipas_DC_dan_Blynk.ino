#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL6eF5kvKV1"
#define BLYNK_DEVICE_NAME "ESP8266 IOT"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "-cNC1o4v2D17wcpO3ntIcR-t6BqOuKDg";
char ssid[] = "piqstar";
char pass[] = "bismillah";

#define RELAY_PIN D4  // menentukan pin digital

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);  // Matikan relay saat booting
}

void loop() {
  Blynk.run();
}

// Fungsi untuk mengontrol relay saat tombol ditekan di aplikasi Blynk
BLYNK_WRITE(V8) {
  int value = param.asInt();
  digitalWrite(RELAY_PIN, value);
}
