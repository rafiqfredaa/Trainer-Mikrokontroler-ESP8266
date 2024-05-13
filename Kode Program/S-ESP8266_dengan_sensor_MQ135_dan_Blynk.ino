#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL6eF5kvKV1"
#define BLYNK_DEVICE_NAME "ESP8266 IOT"
#define GAS_PIN A0

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "-cNC1o4v2D17wcpO3ntIcR-t6BqOuKDg";
char ssid[] = "piqstar";
char pass[] = "bismillah";

BlynkTimer timer;

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, readGas);
}

void loop() {
  Blynk.run();
  timer.run();
}

void readGas() {
  int gasValue = analogRead(GAS_PIN);
  Serial.print(gasValue);
  Blynk.virtualWrite(V3, gasValue); // Mengirim data ke pin virtual di Blynk
}
