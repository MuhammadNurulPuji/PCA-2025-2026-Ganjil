int nilaiSensor=0;


void setup() {
  // put your setup code here, to run once:
  pinMode(9,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  nilaiSensor=analogRead(A0);
  Serial.println(nilaiSensor);
  tone(9,440*8,100);
  delay(1000/map(nilaiSensor,0,1023,1,8));
}
