const int ledBar[]={2,3,4,5,6,7,8,9};
const int buttonPin = 13;
const int potensioPin = A0;

bool dipencet = false;
int delayPotensio=0;
int iterasiNaik=0, iterasiTurun=0;

void setup() {
  // put your setup code here, to run once:

  int i=0;
  while(i<8){
    pinMode(ledBar[i], OUTPUT);
    i++;
  }

  pinMode(buttonPin, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  delayPotensio = map(analogRead(potensioPin),0,1023, 25, 300);
  dipencet = digitalRead(buttonPin);
  if(dipencet){
    turun();
    iterasiTurun++;
    Serial.print("jumlah iterasi turun: ");
    Serial.println(iterasiTurun);
  }else{
    naik();
    iterasiNaik++;
    Serial.print("jumlah iterasi naik: ");
    Serial.println(iterasiNaik);
  }

}

void turun(){
  int i=7;
  while(i>=0){
    digitalWrite(ledBar[i],HIGH);
    delay(delayPotensio);
    digitalWrite(ledBar[i],LOW);
    i--;
  }
}

void naik(){
  int i=0;
  while(i<8){
    digitalWrite(ledBar[i],HIGH);
    delay(delayPotensio);
    digitalWrite(ledBar[i],LOW);
    i++;
  }
}