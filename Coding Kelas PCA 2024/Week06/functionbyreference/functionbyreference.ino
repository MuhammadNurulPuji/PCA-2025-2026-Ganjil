void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  short a=10;
  short b=13;

  Serial.println("==Sebelum Swap==");
  Serial.print("nilai a: ");
  Serial.println(a);
  Serial.print("nilai b: ");
  Serial.println(b);

  swap(&a,&b);

  Serial.println("==Setelah Swap==");
  Serial.print("nilai a: ");
  Serial.println(a);
  Serial.print("nilai b: ");
  Serial.println(b);

  int i=7, j=8, hasil;
  penjumlahan(i,j,&hasil);
  Serial.println("==contoh lain==");
  Serial.print("hasil penjumlahan: ");
  Serial.print(hasil);

}

void loop() {
  // put your main code here, to run repeatedly:

}

void swap(short *x, short *y){
  short temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

void penjumlahan (int a, int b, int *z){
  *z=a+b;
}
