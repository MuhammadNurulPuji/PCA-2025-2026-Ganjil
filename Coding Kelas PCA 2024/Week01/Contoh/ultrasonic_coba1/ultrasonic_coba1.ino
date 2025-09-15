const int trig_Pin = 9;
const int echo_Pin = 10;
double durasi;
double jarak;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Pengukuran Jarak dengan Sensor Ultrasonic");
  pinMode(trig_Pin, OUTPUT);
  pinMode(echo_Pin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // bagian trigger untuk menyuruh mengeluarkan gelombang ultrasonic
  digitalWrite(trig_Pin,LOW);
  delayMicroseconds(2);
  digitalWrite(trig_Pin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_Pin,LOW);

  durasi = pulseIn(echo_Pin, HIGH);
  jarak = durasi*0.034/2;     //menghitung jarak

  Serial.print("jarak: ");
  Serial.print(jarak);
  Serial.println(" cm");
  delay(100);

}
