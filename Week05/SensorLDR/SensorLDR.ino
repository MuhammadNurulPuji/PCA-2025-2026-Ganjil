#define pinBuzzer 9
#define pinLDR A0

int sensorLDR = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinBuzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorLDR = analogRead(pinLDR);
  Serial.print("Nilai Sensor: ");
  Serial.println(sensorLDR);

  tone(pinBuzzer, 440*8, 100);
  delay(1000/map(sensorLDR,0, 1023, 1,8));

}
