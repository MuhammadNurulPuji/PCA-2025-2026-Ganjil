const int pinR=6, pinG=5, pinB=3;

typedef struct{
  byte red;
  byte green;
  byte blue;
}RGBStruct;

RGBStruct rgbVariable={255,0,20};

void setup() {
  // put your setup code here, to run once:
  pinMode(pinR,OUTPUT);
  pinMode(pinG,OUTPUT);
  pinMode(pinB,OUTPUT);
  randomSeed(analogRead(0));
}

void loop() {
  // put your main code here, to run repeatedly:
  rgbVariable.red = random(256);
  rgbVariable.green = random(256);
  rgbVariable.blue = random(256);
  setColor(rgbVariable);
  delay(500);
}

void setColor(RGBStruct color){
  analogWrite(pinR,color.red);
  analogWrite(pinG,color.green);
  analogWrite(pinB,color.blue);
}
