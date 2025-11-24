void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Serial.print("nilai local: ");
  // Serial.println(tesLocal());
  // Serial.print("nilai static: ");
  // Serial.println(tesStatic());

  // Serial.println();
  int a = 5;
  float b = 0;
  b = (float)a/3;
  Serial.println(b);


  delay(1000);
}


int tesLocal(){
  int tes = 0;
  tes++;
  return tes;
}

int tesStatic(){
  static int x=0;
  return x++;
}