const int ledBar[]={2,3,4,5,6,7,8,9};
const int potentioPin = 0;

int jumlahLed, nilaiTegangan;

void setup() {
  // put your setup code here, to run once:
  for(int i=0;i<8;i++){
    pinMode(ledBar[i], OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  nilaiTegangan = analogRead(potentioPin);

  if(nilaiTegangan<=0){
    jumlahLed=0;
  }else if(nilaiTegangan<128){
    jumlahLed=1;
  }else if(nilaiTegangan<256){
    jumlahLed=2;
  }else if(nilaiTegangan<384){
    jumlahLed=3;
  }else if(nilaiTegangan<512){
    jumlahLed=4;
  }else if(nilaiTegangan<640){
    jumlahLed=5;
  }else if(nilaiTegangan<768){
    jumlahLed=6;
  }else if(nilaiTegangan<896){
    jumlahLed=7;
  }else if(nilaiTegangan<=1023){
    jumlahLed=8;
  }else{
    //do nothing
  }

  LedBarON(jumlahLed);
  delay(500);
  LedBarOFF();

}

void LedBarON(int jumlahLed){
  for(int i=0;i<jumlahLed;i++){
    digitalWrite(ledBar[i],HIGH);
  }
}

void LedBarOFF(){
  for(int i=0;i<8;i++){
    digitalWrite(ledBar[i],LOW);
  }
}
