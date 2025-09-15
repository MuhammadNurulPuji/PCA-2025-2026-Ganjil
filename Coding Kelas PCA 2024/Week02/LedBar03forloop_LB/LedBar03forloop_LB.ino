void setup() {
  // put your setup code here, to run once:
  for(int i=0;i<8;i++){
    pinMode(i,OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  ledBawahkeAtas();
}

void ledBawahkeAtas(){
  for(int i=0; i<8; i++){
    digitalWrite(i,HIGH);
    delay(400);
    digitalWrite(i,LOW);
  }
}
