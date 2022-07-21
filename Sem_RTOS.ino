void setup() {
  Serial.begin(9600);
  pinMode(8,INPUT_PULLUP);
  pinMode(13,OUTPUT);
}

void loop() {
  if(digitalRead(8) == 0){
    while(digitalRead(8) == 0);
    digitalWrite(13,LOW); // Desliga LED
  }
  else digitalWrite(13,HIGH);

  Serial.println("PRINTLN");

  delay(1000);
}