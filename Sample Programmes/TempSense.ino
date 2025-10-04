int sensorPin = A0;
float temperatureC;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  temperatureC = (sensorValue * 5.0 * 100.0) / 1024.0; // for LM35
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");
  delay(1000);
}
