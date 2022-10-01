#include <SoftwareSerial.h>


const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to


int sensorValue = 0;


unsigned long counter = 0;


int interval = 5000;


int interval2 = 5000;


unsigned long previousMillis = 0;


unsigned long previousMillis2 = 0;


SoftwareSerial BTserial(3, 4); // RX | TX


void setup() {


  Serial.begin(9600);


  BTserial.begin(9600);


}


void loop() {


  unsigned long currentMillis = millis();


  unsigned long currentMillis2 = millis();


  if ((unsigned long)(currentMillis2 - previousMillis2) >= interval2)


  {


    while ((currentMillis - previousMillis ) < interval)


    {


      sensorValue = analogRead(analogInPin);


      if (sensorValue > 130 && sensorValue < 250)


      {


        counter++;


      }


    }


    previousMillis = currentMillis;


    previousMillis2 = currentMillis2;


    Serial.println(counter);


    BTserial.write(counter);


  }


}