const int baris = 2;
const int kolom = 3;

int jumlah[baris][kolom];

int array1[baris][kolom]={{1,2,3}, {4,5,6}};
int array2[baris][kolom]={1,2,3,4,5};
int array3[baris][kolom]={{1,2}, {7}};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("nilai dari Array 1:");
  arrayPrint(array1);

  Serial.println("nilai dari Array 2:");
  arrayPrint(array2);

  Serial.println("nilai dari Array 3:");
  arrayPrint(array3);

  Serial.println("hasil Array 1 + Array 2 adalah");
  jumlahMatrix(array1, array2);
  arrayPrint(jumlah);

}

void arrayPrint(int data[baris][kolom]){
  for (int i=0;i<baris;i++){
    for (int j=0;j<kolom;j++)//{
      Serial.print(data[i][j]);
    // }
    Serial.println();
  }
}

void jumlahMatrix(int data1[baris][kolom], int data2[baris][kolom]){
  for (int i=0; i<baris; i++){
    for (int j=0; j<kolom; j++){
      jumlah[i][j]=data1[i][j] + data2[i][j];
    }
  }
}
