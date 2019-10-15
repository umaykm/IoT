const int ledPin = 23; //GPIO16 LED PIN
//setting PWM properties
const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;

void setup() {
//configure LED PWM functionalities
  ledcSetup(ledChannel,freq,resolution);  
//attach the channel to the GPIO to be controlled
  ledcAttachPin(ledPin,ledChannel);
}

void loop() {
//increase the LED brightness
  for(int dtCycle=0; dtCycle <= 255; dtCycle++){
  ledcWrite(ledChannel,dtCycle);
  delay(15);
  }
//decrease the LED brightness
  for(int dtCycle=255; dtCycle <= 0; dtCycle--){
  ledcWrite(ledChannel,dtCycle);
  delay(15);
  }
}
