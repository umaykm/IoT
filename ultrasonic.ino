const int pinPing = 36;

void setup(){
  Serial.begin(9600);
}

void loop(){
  long duration, inches, cm;

  pinMode(pinPing, OUTPUT);
  digitalWrite(pinPing, LOW);
  delayMicroseconds(2);
  digitalWrite(pinPing,HIGH);
  delayMicroseconds(5);
  digitalWrite(pinPing,LOW);

  pinMode(pinPing,INPUT);
  duration = pulseIn(pinPing, HIGH);

  inches = microsecondToInches(duration);
  cm = microsecondToCentimeters(duration);

  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(100);
}

long microsecondToInches(long microseconds){
  return microseconds/74/2;
}

long microsecondToCentimeters(long microseconds){
  return microseconds/29/2;
}
