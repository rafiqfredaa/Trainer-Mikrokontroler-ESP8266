#define RELAY_PIN D4  // menentukan pin digital

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
}

void loop() {
  // Relay akan hidup dan mati dalam durasi 1 detik
  digitalWrite(RELAY_PIN, HIGH); // Nyalakan relay
  Serial.println("HIDUP");
  delay(5000);
  digitalWrite(RELAY_PIN, LOW); // Matikan relay
  Serial.println("MATI");
  delay(5000);
}
