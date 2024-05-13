#include <NewPing.h> // import library

// Pin GPIO untuk sensor ultrasonik
const int trigPin = D3;
const int echoPin = D4;

NewPing sonar(trigPin, echoPin, 400); // Trigger pin, echo pin, dan jarak maksimum (dalam cm)

void setup() {
  Serial.begin(9600);
}

void loop() {
  int distance = sonar.ping_cm();  // Baca jarak dalam cm
  Serial.print("Jarak: "); // Menampilkan hasil jarak 
  Serial.print(distance);  // pada serial monitor
  Serial.println(" cm");
  delay(1000); // Tunggu sejenak sebelum mengulangi pembacaan
}
