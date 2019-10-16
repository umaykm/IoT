#include<SPI.h>
char buff[15]="Hello Slave";
const int ssPin = 5;

void setup() {
  Serial.begin(115200);     /* begin serial with 9600 baud */ 
  SPI.begin();      /* begin SPI */
  Serial.println(SS);
  Serial.println(SCL);
  Serial.println(MOSI);
  Serial.println(MISO);
  pinMode(ssPin, OUTPUT);  // set SS pin as OUTPUT
}

void loop() {
  digitalWrite(ssPin, LOW);  // set SS pin as active low
  for(int i=0; i<sizeof buff; i++){    /* transfer buff data per second */
   SPI.transfer(buff[i]);
   Serial.printf("Sending: ");
   Serial.println(buff[i]);
   delay(2000);
  }
}