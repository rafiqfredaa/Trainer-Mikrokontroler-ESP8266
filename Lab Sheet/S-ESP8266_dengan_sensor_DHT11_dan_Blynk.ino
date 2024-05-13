#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL6kKsP-ekJ"
#define BLYNK_DEVICE_NAME "ESP8266test"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

#define DHTPIN 2 //Pin DHT11 terhubung ke GPIO2/D4 pada NodeMCU
#define DHTTYPE DHT11   // Jenis sensor DHT11
DHT dht(DHTPIN, DHTTYPE);

char auth[] = "qCOsjzH-2iZcgg6iTzs_nsDlmL4C3IAK";
char ssid[] = "piqstar";
char pass[] = "bismillah";

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  dht.begin();
}

void loop() {
  Blynk.run();
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  if (isnan(humidity) || isnan(temperature)) {
  Serial.println("Gagal membaca dari sensor DHT11");
  } else {
  Blynk.virtualWrite(V1, temperature); // Kirim suhu ke Widget V1 pada Blynk
  Blynk.virtualWrite(V2, humidity); // Kirim kelembaban ke Widget V2 pada Blynk
  }
  delay(2000); // Tunggu 2 detik sebelum membaca kembali
}
