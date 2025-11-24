int array1[2][3]= {{1,2,3},{4,5,6}};
int array2[3][4]={{7,8,9,10},{11,12,13,14},{15,16,17,18}};

int hasil[2][4];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  perkalianArray(array1, array2);

  Serial.print("Hasil: ");
  Serial.print("\r");
  printArray(hasil);

}

void loop() {


}

void perkalianArray(int a[2][3], int b[3][4]){
  int baris = 2;
  int kolom = 4;
  int common = 3;
  int c;

  for (int i=0;i<baris;i++){
    for (int j=0;j<kolom; j++){
      c=0;
      for (int k=0;k<common;k++){
        c += a[i][k]*b[k][j];
      }
      hasil[i][j] = c;
    }
  }
}

void printArray(int y[2][4]){
  for (int i=0;i<2;i++){
    for (int j=0;j<4; j++){
      Serial.print(y[i][j]);
      Serial.print(" ");
    }
    Serial.print("\r");
  }
}