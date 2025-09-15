void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Static: ");
  Serial.print(tesStatic());

  Serial.println();

  Serial.print("Local: ");
  Serial.print(tesLocal());

  Serial.println();
}

int tesStatic(){
  static int tes = 0;
  tes++;
  return tes;
}

int tesLocal(){
  int tes = 0;
  tes++;
  return tes;
}

