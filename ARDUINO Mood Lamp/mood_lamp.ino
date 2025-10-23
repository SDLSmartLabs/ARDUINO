#include <Adafruit_NeoPixel.h>
#define LED_PIN 6
#define LED_COUNT 12
#define SOUND_PIN A0

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
}

void loop() {
  int soundLevel = analogRead(SOUND_PIN);
  int brightness = map(soundLevel, 100, 600, 0, 255);
  int red = brightness;
  int blue = 255 - brightness;
  int green = brightness / 2;

  for (int i = 0; i < LED_COUNT; i++) {
    strip.setPixelColor(i, strip.Color(red, green, blue));
  }
  strip.show();
  delay(100);
}