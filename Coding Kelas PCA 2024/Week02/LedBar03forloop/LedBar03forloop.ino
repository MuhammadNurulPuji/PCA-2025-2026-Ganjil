int pinLED[]={0,1,2,3,4,5,6,7};

void setup() {
  // put your setup code here, to run once:
  for(int i=0;i<8;i++){
    pinMode(pinLED[i],OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  ledBawahkeAtas();
}

void ledBawahkeAtas(){
  for(int x=0;x<8;x++){
    digitalWrite(pinLED[x], HIGH);
    delay(100);
    digitalWrite(pinLED[x], LOW);
  }
}
