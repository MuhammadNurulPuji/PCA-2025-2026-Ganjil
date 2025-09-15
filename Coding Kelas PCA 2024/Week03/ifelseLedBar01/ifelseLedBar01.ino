const int potensioPin = A0;
int nilaiPotensio;
float tegangan;
int jumlah;


void setup() {
  //Serial.begin(9600);
  // put your setup code here, to run once:
  for(int i=0;i<8;i++){
    pinMode(i,OUTPUT);
  }
  //Serial.println("Hello..");
}

void loop() {
  // put your main code here, to run repeatedly:
  nilaiPotensio = analogRead(potensioPin);
  tegangan = float(nilaiPotensio)/1023*5;

  //Serial.println(tegangan);

  if (nilaiPotensio <= 0){
    jumlah=0;
  }else if(nilaiPotensio <=128){
    jumlah=1;
  }else if(nilaiPotensio <=256){
    jumlah=2;
  }else if(nilaiPotensio <=384){
    jumlah=3;
  }else if(nilaiPotensio <=512){
    jumlah=4;
  }else if(nilaiPotensio <=640){
    jumlah=5;
  }else if(nilaiPotensio <=768){
    jumlah=6;
  }else if(nilaiPotensio <=896){
    jumlah=7;
  }else jumlah=8;

  LedBar(jumlah);
  delay(400);
  LedBarOff();

}


void LedBar(int jumlahLed){
  for (int i=0;i<jumlahLed;i++){
    digitalWrite(i,HIGH);
  }
}

void LedBarOff(){
  for(int i=0;i<8;i++){
    digitalWrite(i,LOW);
  }
}