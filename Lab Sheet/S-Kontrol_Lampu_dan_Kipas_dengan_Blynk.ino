#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL6eF5kvKV1"
#define BLYNK_DEVICE_NAME "ESP8266 IOT"

#include <DHT.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "-cNC1o4v2D17wcpO3ntIcR-t6BqOuKDg";
char ssid[] = "piqstar";
char pass[] = "bismillah";

// Pin kontrol relay
const int relayPin1 = D3;
const int relayPin2 = D4;

#define DHTPIN D5 //Pin DHT11 terhubung ke GPIO2/D5 pada NodeMCU
#define DHTTYPE DHT11   // Jenis sensor DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  pinMode(relayPin1, OUTPUT);
  digitalWrite(relayPin1, HIGH);  // Matikan relay saat booting
  pinMode(relayPin2, OUTPUT);
  digitalWrite(relayPin2, HIGH);  // Matikan relay saat booting
  dht.begin();
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Gagal membaca dari sensor DHT11");
  } else {
    Blynk.virtualWrite(V7, temperature);
    Blynk.virtualWrite(V9, humidity);
  }
  delay(1000); // Tunggu 1 detik sebelum membaca kembali
}

// Fungsi untuk mengontrol relay saat tombol ditekan di aplikasi Blynk
BLYNK_WRITE(V1) {
  int value = param.asInt();
  digitalWrite(relayPin1, value);
}

BLYNK_WRITE(V2) {
  int value = param.asInt();
  digitalWrite(relayPin2, value);
}
