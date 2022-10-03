#include "thingProperties.h"
#include <FTDebouncer.h>

#define LED_PIN 2
#define POT_PIN A1
#define BUTTON_PIN 5

FTDebouncer buttons;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  buttons.addPin(BUTTON_PIN, LOW);
  buttons.init();

  /*
      The following function allows you to obtain more information
      related to the state of network and IoT Cloud connection and errors
      the higher number the more granular information you’ll get.
      The default is 0 (only errors).
      Maximum is 3
  */
  setDebugMessageLevel(2);

  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
}

void loop() {
  buttons.update();
  ArduinoCloud.update();
  // Your code here
  int angleSensor = analogRead(A1);
  angle = map(angleSensor, 0, 1023, 0, 270);
}

void onLightChange() {
  digitalWrite(LED_PIN, light);
  Serial.print("The light is ");
  if (light) {
    Serial.println("ON");
  } else {
    Serial.println("OFF");
  }
}

void onPinActivated(uint8_t pinNr) {
  // do something according to the _pinNR that is triggered. For instance:
  Serial.println(pinNr);
  toggle = !toggle;
}

void onPinDeactivated(uint8_t pinNr) {
  // do something according to the _pinNR that is triggered. For instance:
  Serial.println(pinNr);
}
