// int ledBar []={9,8,2,11,4,5,6,7};

void setup() {
  // put your setup code here, to run once:
  pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);

  // for(int i=0;i<8;i++){
  //   pinMode(ledBar[i],OUTPUT);
  // }

}

void loop() {
  // put your main code here, to run repeatedly:
  ledbar_keatas();
  ledbar_keatas();
  ledbar_kebawah();
  ledbar_keatas();
  ledbar_kebawah();
}

void ledbar_keatas(){
  digitalWrite(0,HIGH);
  delay(300);
  digitalWrite(0,LOW);
  digitalWrite(1,HIGH);
  delay(300);
  digitalWrite(1,LOW);
  digitalWrite(2,HIGH);
  delay(300);
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  delay(300);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  delay(300);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  delay(300);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  delay(300);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  delay(300);
  digitalWrite(7,LOW);
}

void ledbar_kebawah(){
  digitalWrite(7,HIGH);
  delay(300);
  digitalWrite(7,LOW);
  digitalWrite(6,HIGH);
  delay(300);
  digitalWrite(6,LOW);
  digitalWrite(5,HIGH);
  delay(300);
  digitalWrite(5,LOW);
  digitalWrite(4,HIGH);
  delay(300);
  digitalWrite(4,LOW);
  digitalWrite(3,HIGH);
  delay(300);
  digitalWrite(3,LOW);
  digitalWrite(2,HIGH);
  delay(300);
  digitalWrite(2,LOW);
  digitalWrite(1,HIGH);
  delay(300);
  digitalWrite(1,LOW);
  digitalWrite(0,HIGH);
  delay(300);
  digitalWrite(0,LOW);
}