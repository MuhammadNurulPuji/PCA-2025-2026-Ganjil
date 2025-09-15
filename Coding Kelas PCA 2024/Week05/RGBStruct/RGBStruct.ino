const int r=6, g=5, b=3;

typedef struct{
  byte red;
  byte green;
  byte blue;
}RGB_struct;

RGB_struct rgb = {255,0,0};

void setup() {
  // put your setup code here, to run once:
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
  randomSeed(analogRead(0));

}

void loop() {
  // put your main code here, to run repeatedly:
  rgb.red = random(256);
  rgb.green = random(256);
  rgb.blue = random(256);
  setColor(rgb);
  delay(500);

}

void setColor(RGB_struct color){
  analogWrite(r,color.red);
  analogWrite(g,color.green);
  analogWrite(b,color.blue);
}