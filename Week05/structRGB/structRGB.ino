int pinR = 9;
int pinG = 10;
int pinB = 11;

typedef struct{
  byte red;
  byte green;
  byte blue;
} RGB;

RGB varRGB = {255,0,0};

void setup() {
  // put your setup code here, to run once:
  pinMode(pinR, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinB, OUTPUT);
  randomSeed(analogRead(0));
}

void loop() {
  // put your main code here, to run repeatedly:
  varRGB.red = random(256);
  varRGB.green = random(256);
  varRGB.blue = random(256);

  setRandomRGB (varRGB);
  delay(500);

}

void setRandomRGB(RGB color){
  analogWrite(pinR, color.red);
  analogWrite(pinG, color.green);
  analogWrite(pinB, color.blue);
}
