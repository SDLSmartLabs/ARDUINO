#include "SPI.h"
#include "Phpoc.h"

PhpocServer server(80);

void setup() {
  Serial.begin(9600);
  while(!Serial)
    ;

  Phpoc.begin(PF_LOG_SPI | PF_LOG_NET);
  //Phpoc.begin();

  server.beginWebSocket("rotary_canvas");

  Serial.print("WebSocket server address : ");
  Serial.println(Phpoc.localIP());  
}

void loop() {
      
  int x = 0, y = 0;
  
  for (int i = 0; i < 10; i++) 
  {
    x = x + analogRead(A0);
    y = y + analogRead(A1);
  }
  
  String rotary = String(x/10) + "/" + String(y/10);
  
  char rotaryBuf[10];
  rotary.toCharArray(rotaryBuf, 10);
  
  server.write(rotaryBuf);
  Serial.println(rotaryBuf);
  
  delay(50);
}
