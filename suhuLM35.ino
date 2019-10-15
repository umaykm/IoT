float suhu;

void setup() { 
  Serial.begin(9600);
  pinMode(34, INPUT); // pinoutputLM-35 }
}

void loop() { 
  suhu = analogRead(34) * 3.3/ 2048 / 0.01; 
  Serial.println(suhu); 
  delay(1000); 
}
