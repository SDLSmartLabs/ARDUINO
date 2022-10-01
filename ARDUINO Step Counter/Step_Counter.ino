#include "TinyWireM.h"

#include "TinyOzOLED.h"

int accelX, accelY, accelZ;

char mpu = 0x68;  

float vectorprevious;

float vector;

float totalvector;

int Steps = 0;

void setup() {

  TinyWireM.begin();

  OzOled.init();

  OzOled.clearDisplay();  

  OzOled.setNormalDisplay();

  OzOled.sendCommand(0xA1);        // set Orientation

  OzOled.sendCommand(0xC8);

  TinyWireM.beginTransmission(mpu); 

  TinyWireM.write(0x6B); //  Power setting address

  TinyWireM.write(0b00000000); // Disable sleep mode (just in case)

  TinyWireM.endTransmission();

  TinyWireM.beginTransmission(mpu); 

  TinyWireM.write(0x1B); // Config register for Gyro

  TinyWireM.write(0x00000000); // 250° per second range (default)

  TinyWireM.endTransmission();

  TinyWireM.beginTransmission(mpu); //I2C address of the MPU

  TinyWireM.write(0x1C); // Accelerometer config register

  TinyWireM.write(0b00000000); // 2g range +/- (default)

  TinyWireM.endTransmission();

}

void loop() {

 getAccel();

 vector = sqrt( (accelX * accelX) + (accelY * accelY) + (accelZ * accelZ) );

 //OzOled.printString("Vec:", 0, 2);

 //OzOled.printNumber(vector, 0, 5, 2);

 totalvector = vector - vectorprevious;

 //OzOled.printString("Pre:", 0, 4);

 //OzOled.printNumber(vectorprevious, 0, 5, 4);

 //OzOled.printString("Diff:", 0, 6);

 //OzOled.printNumber(totalvector, 0, 5, 6); 

if (totalvector > 6){

  Steps++;

}

//String Step_count = String(Steps);

//char data[2];

//Step_count.toCharArray(data, 2);

//OzOled.printBigNumber(data, 6, 2, 3);

OzOled.printString("Steps", 0, 4);

OzOled.printNumber(Steps, 0, 8, 4);

vectorprevious = vector;

delay(600);

//OzOled.clearDisplay(); 

}

void getAccel() {

  TinyWireM.beginTransmission(mpu); //I2C address of the MPU

  TinyWireM.write(0x3B); //  Acceleration data register

  TinyWireM.endTransmission();

  TinyWireM.requestFrom(mpu, 6); // Get 6 bytes, 2 for each DoF

  accelX = TinyWireM.read() << 8|TinyWireM.read(); 

  accelY = TinyWireM.read() << 8|TinyWireM.read();

  accelZ = TinyWireM.read() << 8|TinyWireM.read();

 // OzOled.printNumber(accelX, 0, 0, 0); 

 // OzOled.printNumber(accelY, 0, 0, 2); 

  //OzOled.printNumber(accelZ, 0, 0, 4); 

}