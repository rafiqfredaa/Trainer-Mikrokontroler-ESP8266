#include <ESP8266WiFi.h>
#include <DHT.h>
#define DHT_PIN D2

DHT dht(DHT_PIN, DHT11);

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  delay(2000);
  
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  
  Serial.print("Suhu: ");
  Serial.print(temperature);
  Serial.print("°C, Kelembaban: ");
  Serial.print(humidity);
  Serial.println("%");
}
