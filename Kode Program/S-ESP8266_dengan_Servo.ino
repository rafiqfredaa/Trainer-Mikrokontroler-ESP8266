#include <Servo.h>    // import library servo
#define SERVO_PIN D3  // menentukan pin digital 
Servo myservo;    // inisialisasi servo

void setup() {
     Serial.begin(9600);
     myservo.attach(SERVO_PIN);
}

void loop() {
//     myservo.write(0); // Gerakkan servo ke posisi 0 derajat
//     delay(1000);
//     myservo.write(90); // Gerakkan servo ke posisi 90 derajat
//     delay(1000);
//     myservo.write(180); // Gerakkan servo ke posisi 180 derajat
//     delay(1000);

//  int pos;
//  for (pos = 0; pos <= 180; pos += 1) {  // goes from 0 degrees to 180 degrees
//    // in steps of 1 degree
//    myservo.write(pos);  // tell servo to go to position in variable 'pos'
//    delay(15);           // waits 15ms for the servo to reach the position
//  }
//  for (pos = 180; pos >= 0; pos -= 1) {  // goes from 180 degrees to 0 degrees
//    myservo.write(pos);                  // tell servo to go to position in variable 'pos'
//    delay(15);                           // waits 15ms for the servo to reach the position
//  }
}
