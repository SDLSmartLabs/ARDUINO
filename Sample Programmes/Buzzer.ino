int buzzerPin = 8;

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  tone(buzzerPin, 1000); // 1kHz tone
  delay(1000);
  noTone(buzzerPin);
  delay(1000);
}
