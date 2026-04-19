#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

// RIGHT motors
int IN1 = 25;
int IN2 = 26;

// LEFT motors
int IN3 = 27;
int IN4 = 14;

// Enable pins
int ENA = 33;
int ENB = 32;

void setup() {
  SerialBT.begin("RC_CAR");

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  analogWrite(ENA, 255);
  analogWrite(ENB, 255);

  stopCar();
}

void loop() {
  if (SerialBT.available()) {
    char cmd = SerialBT.read();

    switch(cmd) {
      case 'F': left(); break;      // fixed
      case 'B': right(); break;     // fixed
      case 'L': backward(); break;  // fixed
      case 'R': forward(); break;   // fixed
      case 'S': stopCar(); break;
    }
  }
}

// 🚗 MOVEMENTS

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void right() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void stopCar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
