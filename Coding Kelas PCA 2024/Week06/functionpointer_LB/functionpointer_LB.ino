void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  int (*fpointer[5])(int, char) = {NULL};

  fpointer[0]=fpointer[1]=&tes1;
  fpointer[2]=fpointer[3]=&tes2;

  Serial.println(fpointer[0](5,'x'));
  Serial.println(fpointer[2](8,'y'));

}

void loop() {
  // put your main code here, to run repeatedly:

}

int tes1(int a, char x){
  Serial.println("Tes 1");
  return a;
}

int tes2(int a, char x){
  Serial.println("Tes 2");
  return a;
}
