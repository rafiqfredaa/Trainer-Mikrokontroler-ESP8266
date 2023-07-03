#include <Stepper.h>

const int stepsPerRevolution = 200;  // Jumlah langkah per putaran
// ULN2003 Motor Driver Pins
//#define IN1 5
//#define IN2 4
//#define IN3 14
//#define IN4 12

Stepper stepper(stepsPerRevolution, D1, D2, D3, D4); // initialize the stepper library

void setup() {
  Serial.begin(115200); // initialize the serial port
  stepper.setSpeed(100);
}

void loop() {
  // Putaran searah jarum jam
  stepper.step(stepsPerRevolution);  // Melakukan satu putaran penuh searah jarum jam
  delay(2000);  // Jeda 1 detik

  // Putaran berlawanan arah jarum jam
  stepper.step(-stepsPerRevolution);  // Melakukan satu putaran penuh berlawanan arah jarum jam
  delay(2000);  // Jeda 1 detik
}
