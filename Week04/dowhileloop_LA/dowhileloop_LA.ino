const int ledBar[]={2,3,4,5,6,7,8,9};
const int ButtonPin = 11;
const int PotensioPin = A0;

int delayLed=100;

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
  int i=7;
  do{
    digitalWrite(ledBar[i],HIGH);
    delay(delayLed);
    digitalWrite(ledBar[i],LOW);
    i--;
  }while(i>=0);
}

void bawahkeatas(){
  int i=0;
  do{
    digitalWrite(ledBar[i],HIGH);
    delay(delayLed);
    digitalWrite(ledBar[i],LOW);
    i++;
  }while(i<=7);
}
