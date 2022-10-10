#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for SSD1306 display connected using software SPI (default case):
#define OLED_MOSI  12
#define OLED_CLK   13
#define OLED_DC    9
#define OLED_CS    10
#define OLED_RESET  8
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
  OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);


#define outputA 2
#define outputB 6
#define SetZero 3

#define Diameter 70 //in mm
#define CPR 800 //Counts per revolution of each phase.
float factor= (3.1415*Diameter)/(CPR);

bool aState;
bool aLastState;  
unsigned long int lastdata=0;
unsigned long int lastDisplay=0;
bool led=0;
long units=0;
bool i=0;

void setup() {
  pinMode (outputA,INPUT_PULLUP);
  pinMode (outputB,INPUT_PULLUP);
  pinMode (SetZero,INPUT_PULLUP);
  
  attachInterrupt(digitalPinToInterrupt(2),ISR1,CHANGE);
  attachInterrupt(digitalPinToInterrupt(3),ISR2,FALLING);
  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Clear the buffer
  display.clearDisplay();
  display.display();
  display.setTextColor(WHITE);
  aLastState = PIND&(1<<2)?1:0;

        display.clearDisplay();
        display.setTextSize(2);
        displayCenter("Length(mm)",15); 
        display.setTextSize(3);      
        displayCenter(String(units),42);
        lastDisplay=millis();

}

void loop()
{
    if(i==1)
    {
      updateDisplay();
    }
      
   if(millis()-lastdata>10000)
   {
     units=0;
     updateDisplay();
     lastdata=millis();
   }     
}


void ISR1()
{
  
  if ( bool(PIND&(1<<6)) != bool(PIND&(1<<2)) ) 
     { 
       units --;
     }
     else
     {
       units ++;
     }
     i=1;
  
}

void ISR2()
{
  units=0;
  i=1;
  }
  
void updateDisplay()
{
        if(millis() - lastDisplay>500)
        {
        display.clearDisplay();
        display.setTextSize(2);
        displayCenter("Length(mm)",15); 
        display.setTextSize(3);      
        displayCenter(String(float(units*factor)),42);
        lastDisplay=millis();
        lastdata = lastDisplay;
         i=0;
        }
  
  }


void displayCenter(String text, int line) 
{
  int16_t x1;
  int16_t y1;
  uint16_t width;
  uint16_t height;

  display.getTextBounds(text, 0, 0, &x1, &y1, &width, &height);
  // display on horizontal center
  display.setCursor((SCREEN_WIDTH - width) / 2, line);
  display.println(text); // text to display
  display.display();
}