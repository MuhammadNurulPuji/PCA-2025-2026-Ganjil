const int ledBar[]={2,3,4,5,6,7,8,9};
const int ButtonPin = 11;
const int PotensioPin = A0;

int delayLed=100;
int startTime=0;
int elapsedTime;

bool cek;

int j=0;

int iterasi1=0, iterasi2=0;
bool ditekan;

void setup() {
  // put your setup code here, to run once:

  int i=0;
  do{
    pinMode(ledBar[i],OUTPUT);
    i++;
  }while(i<8);

  pinMode(ButtonPin, INPUT);

  Serial.begin(9600);
  Serial.println("Hello BINUS ASO");

}

void loop() {
  // put your main code here, to run repeatedly:
  delayLed=map(analogRead(PotensioPin),0,1023,50,400);

  //ini untuk inisialisasi start awal ketika ada perubahan posisi switch button
  if (digitalRead(ButtonPin)!=ditekan){
    startTime=millis();
    digitalWrite(ledBar[j],LOW);;// supaya off Led yg sebelumnya ketika ada perubahan posisi
    ditekan = digitalRead(ButtonPin);
    if(ditekan){
      j=7;
    }else j=0;
  }
  
  if(ditekan){
    ataskebawah();
    iterasi1++;
    Serial.print("jumlah iterasi atas ke bawah: ");
    Serial.println(iterasi1);
  }else {
    bawahkeatas();
    iterasi2++;
    Serial.print("jumlah iterasi bawah ke atas: ");
    Serial.println(iterasi2);
  }

}

void ataskebawah(){
  digitalWrite(ledBar[j],HIGH);
  elapsedTime=millis()-startTime;
  if (elapsedTime>delayLed){
    digitalWrite(ledBar[j],LOW);
    j--;
    startTime=millis();
    if(j<0){
        j=7;
      }
  }
}

void bawahkeatas(){
  digitalWrite(ledBar[j],HIGH);
  elapsedTime=millis()-startTime;
  if (elapsedTime>delayLed){
  digitalWrite(ledBar[j],LOW);
  j++;
  startTime=millis();
  if(j>7){
      j=0;
    }
  }
}