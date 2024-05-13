#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL6eF5kvKV1"
#define BLYNK_DEVICE_NAME "ESP8266 IOT"

#include <Wire.h>
#include <NewPing.h>
#include <Ultrasonic.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "-cNC1o4v2D17wcpO3ntIcR-t6BqOuKDg";
char ssid[] = "piqstar";
char pass[] = "bismillah";

#define TRIG_PIN D3
#define ECHO_PIN D4

Ultrasonic ultrasonic(TRIG_PIN, ECHO_PIN);

NewPing sonar(TRIG_PIN, ECHO_PIN, 400); // Trigger pin, echo pin, dan jarak maksimum (dalam cm)

BlynkTimer timer;

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, readUltrasonic); // interval pengiriman data ke blynk
}

void loop() {
  Blynk.run();
  timer.run();
}

void readUltrasonic() {
//  int distance = sonar.ping_cm();  // Baca jarak dalam cm
  long distance = ultrasonic.read();
  Blynk.virtualWrite(V4, distance); // Mengirim data ke pin virtual di Blynk
}
