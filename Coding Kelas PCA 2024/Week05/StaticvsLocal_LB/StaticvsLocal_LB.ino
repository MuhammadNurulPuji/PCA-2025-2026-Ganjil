void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("nilai Static: ");
  Serial.println(tesStatic());

  Serial.println();

  Serial.print("nilai Local: ");
  Serial.println(tesLocal());

  Serial.println();

  delay(500);
}


int tesStatic(){
  static int x = 0;
  x++;
  return x;
}

int tesLocal(){
  int y = 0;
  y++;
  return y;
}