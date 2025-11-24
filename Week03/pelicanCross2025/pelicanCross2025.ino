int pinMerah = 7;
int pinKuning = 6;
int pinHijau = 5;
int pinButton = 4;

int state = 2; // defaultnya warna hijau
int durasiMerah = 3000;
int durasiKuning = 1000;
long elapsedTime; // untuk menghitung waktu saat berjalan


void setup() {
  // put your setup code here, to run once:
  pinMode(pinMerah, OUTPUT);
  pinMode(pinKuning, OUTPUT);
  pinMode(pinHijau, OUTPUT);
  pinMode(pinButton, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  if (digitalRead(pinButton) == HIGH){
    state = 0; // untuk warna merah
    elapsedTime = millis(); //untuk catat millis awal saat button dipencet
  }

  switch (state){
    case 0: // untuk merah
      digitalWrite(pinMerah, HIGH);
      digitalWrite(pinKuning, LOW);
      digitalWrite(pinHijau, LOW);

      if(millis()-elapsedTime >= durasiMerah){
        state = 1;  // lompat ke kuning
        elapsedTime = millis(); // untuk start millis kondisi kuning
      }

      break;
    case 1: // untuk kuning
      digitalWrite(pinMerah, LOW);
      digitalWrite(pinKuning, HIGH);
      digitalWrite(pinHijau, LOW);

      if(millis()-elapsedTime >= durasiKuning){
        state = 2;  // lompat ke hijau
      }

      break;
    case 2: // untuk hijau
      digitalWrite(pinMerah, LOW);
      digitalWrite(pinKuning, LOW);
      digitalWrite(pinHijau, HIGH);

      break;
  }


}
