float vref= 3.3;
float resolution = vref/1023; 

voidsetup() {
  Serial.begin(9600); /* Define baud rate for serial communication */ 
}

voidloop() { 
  floattemperature = analogRead(36); 
  temperature = (temperature*resolution);
  temperature = temperature*100;
  Serial.println(temperature);
  delay(1000);
}
