#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "TOKEN_OTENTIKASI_ANDA";
char ssid[] = "NAMA_SSID_WIFI_ANDA";
char password[] = "KATA_SANDI_WIFI_ANDA";

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, password);
}

void loop() {
  Blynk.run();
}
