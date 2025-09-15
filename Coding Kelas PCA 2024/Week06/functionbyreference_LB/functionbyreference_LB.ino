void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  short a = 10;
  short b =76;

  Serial.println("--sebelum Swap--");
  Serial.print("nilai a: ");
  Serial.println(a);
  Serial.print("nilai b: ");
  Serial.println(b);

  swap(&a,&b);

  Serial.println("--setelah Swap--");
  Serial.print("nilai a: ");
  Serial.println(a);
  Serial.print("nilai b: ");
  Serial.println(b);

  int i=10, j=4, hasil;
  pengurangan(i, j, &hasil);
  Serial.println("---tes pengurangan---");
  Serial.print("hasil adalah: ");
  Serial.println(hasil);

}

void loop() {
  // put your main code here, to run repeatedly:

}

void swap(short *x, short*y){
  short temp;
  temp = *x;
  *x=*y;
  *y=temp;
}

void pengurangan(int x, int y, int *z){
  *z=x-y;
}
