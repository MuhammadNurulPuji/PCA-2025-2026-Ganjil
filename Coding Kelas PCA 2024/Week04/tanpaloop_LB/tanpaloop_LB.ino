const int ledBar[]={2,3,4,5,6,7,8,9};
const int buttonPin = 13;
const int potensioPin = A0;

bool dipencet = false;
int delayPotensio=0;
int iterasiNaik=0, iterasiTurun=0;

int i=0;
long startTime=0, elapsedTime;

void setup() {
  // put your setup code here, to run once:
  int i=0;
  while(i<8){
    pinMode(ledBar[i], OUTPUT);
    i++;
  }

  pinMode(buttonPin, INPUT);
  dipencet=digitalRead(buttonPin);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  delayPotensio = map(analogRead(potensioPin),0,1023, 25, 300);

  if(digitalRead(buttonPin)!=dipencet){   //mendeteksi perubahan
    startTime=millis();
    dipencet = digitalRead(buttonPin);
  }

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
    digitalWrite(ledBar[i],HIGH);
    delay(delayPotensio);
    digitalWrite(ledBar[i],LOW);
    i--;

    if(i<0){
      i=7;
    }
}

void naik(){

    digitalWrite(ledBar[i],HIGH);
    
    //delay(delayPotensio);
    elapsedTime=millis()-startTime;
    if(elapsedTime>=delayPotensio){
      digitalWrite(ledBar[i],LOW);
      i++;
      startTime=millis();

      if(i>7){
        i=0;
      }
    }

}