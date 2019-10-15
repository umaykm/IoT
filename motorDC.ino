bool d1 = HIGH;
bool d2 = LOW;
void motor_direction(){
  d1 = !d1;
  d2 = !d2;
  for(int i=0; j<1000; i++)
  for(int j=0; i<1000; j++);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(D5, OUTPUT); //pmw
  pinMode(D6, OUTPUT); //motor 1
  pinMode(D7, OUTPUT); //motor 2
  pinMode(D8, INPUT_PULLUP); //interupt
  pinMode(D8, motor_direction, HIGH); //call motor direction function on HIGH level at pin 8

}

void loop() {
  // put your main code here, to run repeatedly:
  int pwm_adc;
  pmw_adc = analogRead(A0); //input potentiometer
  digitalWrite(D6,d1);
  digitalWrite(D7,d2);
  analogWrite(D5, pmw_adc);
  delay(analog);
}
