const int ledBar[]={2,3,4,5,6,7,8,9};
const int ButtonPin = 11;
const int PotensioPin = A0;

int delayLed=100;

int iterasi1=0, iterasi2=0;
bool ditekan;

void setup() {
  // put your setup code here, to run once:
  for (int i=0; i<8; i++){
    pinMode(ledBar[i],OUTPUT);
  }

  pinMode(ButtonPin, INPUT);

  Serial.begin(9600);
  Serial.println("Hello BINUS ASO");

}

void loop() {
  // put your main code here, to run repeatedly:
  delayLed=map(analogRead(PotensioPin),0,1023,10,400);

  ditekan = digitalRead(ButtonPin);
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
  for(int i=7;i>=0;i--){
    digitalWrite(ledBar[i],HIGH);
    delay(delayLed);
    digitalWrite(ledBar[i],LOW);
  }
}

void bawahkeatas(){
  for(int i=0;i<=7;i++){
    digitalWrite(ledBar[i],HIGH);
    delay(delayLed);
    digitalWrite(ledBar[i],LOW);
  }
}
