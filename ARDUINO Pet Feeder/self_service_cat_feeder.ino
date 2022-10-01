#include <Servo.h>
int CatButton;  //  
Servo servo1;   //  servo  Servo

void setup() {

  pinMode(3, OUTPUT);     //  3 
  pinMode(11, OUTPUT);    // 
  servo1.attach(9);       //     

// 
  analogWrite(11, 20); //   
  servo1.write(10);    //       
  delay(250);          //       
  analogWrite(11, 0);  //   

}

void loop() {

  CatButton = analogRead(A0); //      

  if (CatButton > 700) {      //       
    analogWrite(11, 20);      //     ()     
    digitalWrite(3, HIGH);    //    
    servo1.write((map(analogRead(A1), 0, 1024, 0, 180))); //    
    delay(250);               //     
    servo1.write(10);         //  
    delay(250);               //     
    digitalWrite(3, LOW);     //    
    analogWrite(11, 0);       //    
    delay(500);               //       
  }

}
 70  
digital_weight_scale.ino
Viewed
@@ -0,0 +1,70 @@
#include "HX711.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int IN1 = A0;
int IN2 = A1;  

int over_val;
int data;
int g_weight;
int Weight;

const int buzzer = 13;


void setup()
{       
  pinMode(buzzer, OUTPUT);

  pinMode(IN1, INPUT);
  pinMode(IN2, INPUT);
  Init_Hx711();     
  Serial.begin(9600);
  Serial.print("Ready!\n");
  Get_Maopi();
  lcd.begin(16, 2); 
  lcd.clear();
  lcd.setCursor(0,0);       
  lcd.print(" MUHAMMAD ANSAR ");  
  lcd.setCursor(0,1);       
  lcd.print("  0337-8655465  "); 
  delay(1000);
  lcd.clear();
}

void loop()
{       

Weight = Get_Weight();
g_weight = Weight-data;  

 lcd.setCursor(0,0);       
 lcd.print("Weight:");
 lcd.print(g_weight);
 lcd.print("g    ");

if (digitalRead(IN2) == LOW){data=Weight;}
if (digitalRead(IN1) == LOW){over_val=g_weight;}

if (g_weight<=over_val)
{
lcd.setCursor ( 0, 1 );
lcd.print("Max Weight:");
lcd.print(over_val);
lcd.print("g    ");
digitalWrite(buzzer,LOW);
}

else if (g_weight>over_val)  
{
Serial.println("overload");
lcd.setCursor ( 0, 1 );
lcd.print("...OverLoad!!...");
digitalWrite(buzzer,HIGH);
}

delay(50);     
}
