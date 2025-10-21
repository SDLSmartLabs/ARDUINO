#include <Adafruit_NeoPixel.h>
#define LED_PIN 6
#define LED_COUNT 8
#define LDR_PIN A0

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.setBrightness(100);
  strip.show();
}

void loop() {
  int lightLevel = analogRead(LDR_PIN);
  int brightness = map(lightLevel, 0, 1023, 255, 20); // darker room -> brighter LEDs
  for (int i = 0; i < LED_COUNT; i++) {
    strip.setPixelColor(i, strip.Color(brightness, brightness, brightness));
  }
  strip.show();
  delay(200);
}