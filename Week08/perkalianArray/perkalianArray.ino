int hasil[2][4];

int array1[2][3]={{1,1,1}, {1,1,1}};
int array2[3][4]={{1,1,1,1}, {1,1,1,1}, {1,1,1,1}};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  perkalianArray(array1, array2);

  Serial.println("Hasil perkalian array1 x array2 adalah:");
  arrayPrint(hasil);
}

void arrayPrint(int data[2][4]){
  int baris = 2;
  int kolom = 4;
  for (int i=0;i<baris;i++){
    for (int j=0;j<kolom;j++){
      Serial.print(data[i][j]);
      Serial.print(" ");
   }
    Serial.println();
  }
}


void perkalianArray(int a[2][3], int b[3][4])
{
  int baris = 2;
  int kolom = 4;
  int common = 3;
  int temp = 0;

  for (int i=0;i<baris;i++){
    for (int j=0;j<kolom;j++){
      temp = 0;
      for(int k=0;k<common;k++){
        temp += a[i][k]*b[k][j];
      }
      hasil[i][j]= temp;
    }
  }  
}