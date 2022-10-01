#include <SPI.h>
#include <DMD.h>
#include <TimerOne.h>
#include "SystemFont5x7.h"
#include "Arial_black_16.h"
#define ROW 1
#define COLUMN 1
#define FONT Arial_Black_16
char input;
int a = 0, b = 0;
int flag = 0;
char cstr1[50];
DMD led_module(ROW, COLUMN);
void scan_module()
{
  led_module.scanDisplayBySPI();
}
void setup()
{
  Serial.begin(9600);
  Timer1.initialize(2000);
  Timer1.attachInterrupt(scan_module);
  led_module.clearScreen( true );
}
void loop()
{
  if(Serial.available() > 0)
  {
    flag = 0;
    input = Serial.read();
    if (input == 'a' && flag == 0)
  {
    flag = 1;
    a++;
  }
  else if (input == 'b' && flag == 0)
  {
    flag = 1;
    b++;
  }
  else;
  }
 (String("HOME:")+String(a) + String(" - ") + String("AWAY:")+String(b)).toCharArray(cstr1, 50);
    led_module.selectFont(FONT);
    led_module.drawMarquee(cstr1,50, (32 * ROW), 0);
    long start = millis();
    long timming = start;
    boolean flag = false;
    while (!flag)
    {
      if ((timming + 30) < millis()) 
      {
        flag = led_module.stepMarquee(-1, 0);
        timming = millis();
      }
   }
}