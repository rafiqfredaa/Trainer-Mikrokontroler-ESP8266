// Pin GPIO untuk sensor MQ-135
const int sensorPin = A0;

void setup() {
  // Inisialisasi komunikasi serial
  Serial.begin(9600);
  // Konfigurasi pin sensor MQ-135
  pinMode(sensorPin, INPUT);
}

void loop() {
  // Membaca nilai analog dari sensor MQ-135
  int sensorValue = analogRead(sensorPin);
  // Menghitung kualitas udara berdasarkan nilai analog
  // Silakan merujuk pada datasheet sensor untuk kalibrasi yang akurat
  float airQuality = sensorValue / 1024.0 * 100;
  // Menampilkan hasil kualitas udara pada serial monitor
  Serial.print("Kualitas Udara: ");
  Serial.print(airQuality);
  Serial.println("%");
  // Tunggu sejenak sebelum mengulangi pembacaan
  delay(1000);
}
//
//#include <MQ135.h>
//
//const int analogPin = A0; // Pin analog untuk membaca sensor
//MQ135 gasSensor = MQ135(analogPin);
//
//void setup() {
//  Serial.begin(9600);
//}
//
//void loop() {
//  float ppm = gasSensor.getPPM();
//  Serial.print("Gas Concentration (PPM): ");
//  Serial.println(ppm);
//  delay(1000); // Beri jeda sebentar sebelum membaca nilai lagi
//
//  float rzero = gasSensor.getRZero();
//  Serial.print("RZero: ");
//  Serial.println(rzero);
//  delay(1000);
//}
