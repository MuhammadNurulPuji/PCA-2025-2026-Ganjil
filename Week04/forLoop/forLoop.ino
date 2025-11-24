const int pinLed[]={4,5,6,7,8,9,10,11};
const int buttonPin = 12;

void setup() {
  // put your setup code here, to run once:
  for (int i=0;i<8;i++){
    pinMode(pinLed[i],OUTPUT);
  }
  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(buttonPin)){
    // bawahKeAtas();
    bawahKeAtas2();
    // ledOFF();
  }
}

void bawahKeAtas(){
  for(int i=0;i<8;i++){
    digitalWrite(pinLed[i], HIGH);
    delay(500);
  }
}

void ledOFF(){
  for(int i=0;i<8;i++){
    digitalWrite(pinLed[i], LOW);
  }
}

void bawahKeAtas2(){
  for(int i=0;i<8;i++){
    digitalWrite(pinLed[i], HIGH);
    delay(500);
    digitalWrite(pinLed[i], LOW);
  }
}