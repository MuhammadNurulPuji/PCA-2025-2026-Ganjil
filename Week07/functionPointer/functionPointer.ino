void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  int (*fpointer[4])(int, char)={NULL};

  fpointer[0]=fpointer[1]=&tes1;
  fpointer[2]=fpointer[3]=&tes2;

  fpointer[0](25, 'h');
  fpointer[2](4, 'j');

  Serial.println(fpointer[0](25, 'h'));
  Serial.println(fpointer[2](4, 'j'));

}

void loop() {
  // put your main code here, to run repeatedly:

}

int tes1( int x, char y){
  Serial.println("Tes1");
  return x;
}

int tes2( int x, char y){
  Serial.println("Tes2");
  return x;
}