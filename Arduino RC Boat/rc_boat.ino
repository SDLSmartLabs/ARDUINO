int f_button = 9;
int b_button = 8;
int l_button = 7;
int r_button = 6;
int m1 = 2;
int m2 = 3;
int m3 = 4;
int m4 = 5;
void setup () {
  pinMode(f_button, INPUT_PULLUP);
  pinMode(b_button, INPUT_PULLUP);
  pinMode(l_button, INPUT_PULLUP);
  pinMode(r_button, INPUT_PULLUP);
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
}
void loop() {
  if ( digitalRead(f_button) == LOW)
  {
    digitalWrite(m1, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m2, HIGH );
    digitalWrite(m4, HIGH);
  }
  if ( digitalRead(b_button) == LOW)
  {
    digitalWrite(m2, LOW);
    digitalWrite(m4, LOW);
    digitalWrite(m1, HIGH);
    digitalWrite(m3, HIGH);
  }
  if ( digitalRead(l_button) == LOW)
  {
    digitalWrite(m1, LOW);
    digitalWrite(m2, HIGH);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, HIGH);
  }
  if ( digitalRead(r_button) == LOW)
  {
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, HIGH);
  }
}