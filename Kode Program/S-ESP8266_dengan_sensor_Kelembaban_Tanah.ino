#define MOISTURE_PIN A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  int moistureValue = analogRead(MOISTURE_PIN);
  moistureValue = map(moistureValue, 0, 1023, 0, 100);
  moistureValue = (moistureValue - 100) * -1;
  
  Serial.print("Kelembaban Tanah: ");
  Serial.println(moistureValue);
  delay(1000);
}
