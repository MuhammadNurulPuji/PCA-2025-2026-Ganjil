void printArray(const int[][3]);  //prototype function
const int rows = 2;
const int columns = 3;

int array1[rows][columns]= {{11,22,3},{44,5,65}};
int array2[rows][columns]= {1,2,3,4,5};
int array3[rows][columns]= {{1,2},{4}};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Values in array1 by row are: ");
  Serial.print("\r");
  printArray(array1);

  Serial.print("Values in array2 by row are: ");
  Serial.print("\r");
  printArray(array2);

  Serial.print("Values in array3 by row are: ");
  Serial.print("\r");
  printArray(array3);

}

void printArray(const int a[][columns]){
  for (int i=0;i<rows;i++){
    for (int j=0;j<columns; j++){
      Serial.print(a[i][j]);
      Serial.print(" ");
    }
    Serial.print("\r");
  }
}
