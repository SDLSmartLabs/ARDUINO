int redPin = 9;
int greenPin = 10;
int bluePin = 11;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  analogWrite(redPin, 255);   // Red
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);
  delay(1000);

  analogWrite(redPin, 0);     // Green
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 0);
  delay(1000);

  analogWrite(redPin, 0);     // Blue
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 255);
  delay(1000);
}
