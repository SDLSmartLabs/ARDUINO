 int green=13;
 int yellow=12;
 int red=11;
 int green2=13;
 int yellow2=12;
 int red2=11;
 void setup() {
  pinMode(green, OUTPUT);
  pinMode(yellow , OUTPUT);
  pinMode(red , OUTPUT);
  pinMode(green2, OUTPUT);
  pinMode(yellow2 , OUTPUT);
  pinMode(red2 , OUTPUT);
  digitalWrite(green ,HIGH);
  digitalWrite(yellow ,HIGH);
  digitalWrite(red ,HIGH);
  digitalWrite(green2 ,HIGH);
  digitalWrite(yellow2 ,HIGH);
  digitalWrite(red2 ,HIGH);
  delay(2000);
  digitalWrite(green ,LOW);
  digitalWrite(yellow ,LOW);
  digitalWrite(red ,LOW);
  digitalWrite(green2 ,LOW);
  digitalWrite(yellow2 ,LOW);
  digitalWrite(red2 ,LOW);
 }
 /* dual line triffic light
  * http://www.eccircuit.com
  * WRITER IS ANKIT JAT
  * route 1 red led time = route 1 red led time [1] + route 1 red led time [2]
  * route 2 red led time = route 2 red led time [2] + route 2 red led time [2]
  * route 1 total red led time = 1 second or 60000 ms
  * route 2 total red led time = 1 second or 60000 ms
  */
 void loop() {
  digitalWrite(green ,HIGH);
  digitalWrite(red2 ,HIGH);
  delay(45000); /* route 1 green led time and route 2 red led time [1] */
  digitalWrite(green ,LOW);
  digitalWrite(yellow ,HIGH);
  delay(15000); /* route 1 yellow led time and route 2 red led time [2] */
  digitalWrite(yellow ,LOW);
  digitalWrite(red ,HIGH);
  digitalWrite(red2 ,LOW);
  digitalWrite(green2 ,HIGH);
  delay(45000); /* route 1 red led time [1] and route 2 green led time */
  digitalWrite(green2 ,LOW);
  digitalWrite(yellow2 ,HIGH);
  delay(15000); /* route 1 red led time [2] and route 2 yellow led time */
  digitalWrite(red ,LOW);
  digitalWrite(yellow2 ,LOW);
 
