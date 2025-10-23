#include <Servo.h>
#define TRIG_PIN 9
#define ECHO_PIN 10

Servo servo;

void setup() {
  servo.attach(6);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  servo.write(0);
}

void loop() {
  long duration, distance;
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;

  if (distance < 15) {
    servo.write(90);  // Open lid
    delay(2000);
  } else {
    servo.write(0);   // Close lid
  }
  delay(300);
}