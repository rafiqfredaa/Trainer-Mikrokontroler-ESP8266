#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL6kKsP-ekJ"
#define BLYNK_DEVICE_NAME "ESP8266 IOT"

#include <Stepper.h> 
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "-cNC1o4v2D17wcpO3ntIcR-t6BqOuKDg";
char ssid[] = "piqstar";
char pass[] = "bismillah";

// Konfigurasi Motor Stepper
const int stepsPerRevolution = 200;  // kecepatan motor
Stepper myStepper(stepsPerRevolution, D1, D2, D3, D4); 

bool putaran = false;

void setup() {
  Serial.begin(9600);
  myStepper.setSpeed(100); // Atur kecepatan motor
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();

  if(putaran) {
    PutaranStepper(1,1);
  }
}

BLYNK_WRITE(V9) { // Widget Tombol Blynk
  putaran = param.asInt();
}

void PutaranStepper(int Arah,int Berputar) {
  for(int i = 0; i < Berputar; i++){
    myStepper.step(Arah * 200);
    Blynk.run();
  }
}
