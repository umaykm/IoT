
struct Button {
  const uint8_t PIN;
  uint32_t numberKeyPresses;
  bool pressed;
};

Button button1 = {18,0,false};

void IRAM_ATTR isr(){
  button1.numberKeyPresses += 1;
  button1.pressed = true;
}

const int LED = 23;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(button1.PIN, INPUT_PULLUP);
  attachInterrupt(button1.PIN, isr, FALLING);
  pinMode(LED,OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
  if(button1.pressed){
    Serial.printf("Button 1 has been pressed %u"
    "times\n",button1.numberKeyPresses);
    digitalWrite(LED,HIGH);
    button1.pressed = false;
    delay(300);
    digitalWrite(LED,LOW); 
  }
  
  //detach interupt after 1 minute
  static uint32_t lastMillis = 0;
  if(millis()-lastMillis>60000){
    lastMillis = millis();
    detachInterrupt(button1.PIN);
    Serial.println("Interupt Detached!");
    //digitalWrite(LED,HIGH);
  }
}
