const int pinLed[]={4,5,6,7,8,9,10,11};
const int buttonPin = 12;

void setup() {
  // put your setup code here, to run once:
  int i=0;
  do{
    pinMode(pinLed[i],OUTPUT);
    i++;
  }while(i<8);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(buttonPin)){
    bawahKeAtas2();
  }
}

void bawahKeAtas2(){
  int i=0;
  do{
    digitalWrite(pinLed[i], HIGH);
    delay(500);
    digitalWrite(pinLed[i], LOW);
    i++;
  }while(i<8);
}