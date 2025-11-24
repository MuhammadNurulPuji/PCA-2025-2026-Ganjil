const int pinLed[]={4,5,6,7,8,9,10,11};
const int buttonPin = 12;

int iterasiLed = 0;

void setup() {

  Serial.begin(9600);
  // put your setup code here, to run once:
  int i=0;
  while(i<8){
    pinMode(pinLed[i],OUTPUT);
    i++;
  }
  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(buttonPin)){
    bawahKeAtas2();
    Serial.print("Jumlah Iterasi: ");
    Serial.println(iterasiLed);
  }
}

void bawahKeAtas2(){
  int i=0;
  while(i<8){
    digitalWrite(pinLed[i], HIGH);
    delay(500);
    digitalWrite(pinLed[i], LOW);
    i++;
  }
  iterasiLed++;
}