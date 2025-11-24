const int baris = 2;
const int kolom = 3;

int array1[baris][kolom]={{11,12,13}, {14,15,16}};
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
}

void arrayPrint(int data[baris][kolom]){
  int (*p)[kolom];
  p = data;

  for (int i=0;i<baris;i++){
    for (int j=0;j<kolom;j++){
      //Serial.print(data[i][j]);
      Serial.print (*(*(p+i)+j));
      Serial.print(" ");
    }
    Serial.println();
  }
}
