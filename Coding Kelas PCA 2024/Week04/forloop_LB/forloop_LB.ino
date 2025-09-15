const int ledBar[]={2,3,4,5,6,7,8,9};
const int buttonPin = 13;
const int potensioPin = A0;

bool dipencet = false;
int delayPotensio=0;
int iterasiNaik=0, iterasiTurun=0;

void setup() {
  // put your setup code here, to run once:
  for (int i=0; i<8; i++){
    pinMode(ledBar[i],OUTPUT);
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
  for(int i=7;i>=0;i--){
    digitalWrite(ledBar[i],HIGH);
    digitalWrite(ledBar[i+1],HIGH);
    digitalWrite(ledBar[i+2],HIGH);
    delay(delayPotensio);
    digitalWrite(ledBar[i],LOW);
    digitalWrite(ledBar[i+1],LOW);
    digitalWrite(ledBar[i+2],LOW);
  }
}

void naik(){
  for(int i=0;i<8;i++){
    for(int j=i;j<=i+2;j++){
      digitalWrite(ledBar[j],HIGH);
    }
    delay(delayPotensio);
    for(int j=i;j<=i+2;j++){
      digitalWrite(ledBar[j],LOW);
    }
  }
}