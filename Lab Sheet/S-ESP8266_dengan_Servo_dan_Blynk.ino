#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL6eF5kvKV1"
#define BLYNK_DEVICE_NAME "ESP8266 IOT"

#include <Servo.h>  // library untuk motor servo
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "-cNC1o4v2D17wcpO3ntIcR-t6BqOuKDg";
char ssid[] = "piqstar";
char pass[] = "bismillah";

Servo servo;

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  servo.attach(D3);  // Hubungkan servo ke pin D3
}

void loop() {
  Blynk.run();
}

BLYNK_WRITE(V2) {
  int angle = param.asInt(); // Baca nilai slider dari Blynk
  servo.write(angle);       // Putar servo sesuai dengan nilai slider
}
