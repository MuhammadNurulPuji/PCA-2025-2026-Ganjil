void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  int nilaix = 75;
  int nilaiy = 45;

  Serial.print("nilaix sebelum di swap = ");
  Serial.println(nilaix);
  Serial.print("nilaiy sebelum di swap = ");
  Serial.println(nilaiy);

  swapx(&nilaix, &nilaiy);

  Serial.print("nilaix setelah di swap = ");
  Serial.println(nilaix);
  Serial.print("nilaiy setelah di swap = ");
  Serial.println(nilaiy);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void swapx(int *a, int *b){
  int temp = *a;

  *a = *b;
  *b = temp;
}