int LedPin = 13;
int switchButton = 2;


void setup() {
  // put your setup code here, to run once:
  pinMode(switchButton, INPUT);
  pinMode(LedPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  // blinking LED

  digitalWrite(LedPin, digitalRead(switchButton));
  delay(300);
  digitalWrite(LedPin, LOW);
  delay(300);

}
