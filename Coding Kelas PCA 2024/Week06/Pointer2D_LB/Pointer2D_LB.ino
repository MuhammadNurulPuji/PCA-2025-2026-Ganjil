void printArray(const int [][3]);
const int rows = 2;
const int columns =3;
int array1[rows][columns] = {{1,25,3}, {7,8,9}};
int array2[rows][columns] = {2,3,4,5,6};
int array3[rows][columns] = {{1,3},{5}};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("nilai array1: ");
  Serial.print("\r");
  printArray(array1);

  Serial.print("nilai array2: ");
  Serial.print("\r");
  printArray(array2);

  Serial.print("nilai array3: ");
  Serial.print("\r");
  printArray(array3);
}

void printArray(const int a[][columns]){
  int (*p)[columns];
  p=a; 

  for(int i=0; i<rows; i++){
    for (int j=0; j<columns; j++){
      Serial.print(*(*(p+i)+j));
      Serial.print(" ");
    }
    Serial.print("\r");
  }
}
