/* 
  Smart Plant Care System
  Monitors soil moisture, light, and temperature,
  with NeoPixel color indicators and IoT Cloud updates.
*/

#include "thingProperties.h"
#include <Adafruit_NeoPixel.h>
#include "DHT.h"

// Pin definitions
#define DHTPIN 2
#define DHTTYPE DHT11
#define SOIL_PIN A0
#define LIGHT_PIN A1
#define LED_PIN 6
#define LED_COUNT 1

DHT dht(DHTPIN, DHTTYPE);
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

// IoT Cloud variables
float temperature;
int soilMoisture;
int lightLevel;
bool waterPlant; // Remote trigger

void setup() {
  Serial.begin(9600);
  delay(1500);
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
  
  dht.begin();
  strip.begin();
  strip.setBrightness(80);
  strip.show();
}

void loop() {
  ArduinoCloud.update();
  readSensors();
  showStatus();
  delay(2000);
}

void readSensors() {
  // Read temperature
  temperature = dht.readTemperature();
  // Read soil moisture (0-1023)
  soilMoisture = analogRead(SOIL_PIN);
  // Read light level (0-1023)
  lightLevel = analogRead(LIGHT_PIN);
  
  Serial.print("Temp: "); Serial.print(temperature);
  Serial.print("C | Soil: "); Serial.print(soilMoisture);
  Serial.print(" | Light: "); Serial.println(lightLevel);
}

void showStatus() {
  uint32_t color;

  if (soilMoisture > 800) {
    color = strip.Color(255, 0, 0); // Red: Dry soil
  } 
  else if (temperature < 15) {
    color = strip.Color(0, 0, 255); // Blue: Too cold
  } 
  else if (lightLevel < 300) {
    color = strip.Color(255, 255, 0); // Yellow: Too dark
  } 
  else {
    color = strip.Color(0, 255, 0); // Green: Perfect
  }

  strip.fill(color, 0, LED_COUNT);
  strip.show();
}

void onWaterPlantChange() {
  if (waterPlant) {
    Serial.println("Watering plant triggered!");
    // Simulate watering
    strip.fill(strip.Color(0, 0, 255), 0, LED_COUNT);
    strip.show();
    delay(3000);
    waterPlant = false; // Reset trigger
  }
}