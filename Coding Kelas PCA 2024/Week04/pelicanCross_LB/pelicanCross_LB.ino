#include <Servo.h>

Servo myservo;
int nilaiVolt, posisi;
const int potensioPin = A0;
const int servoPin = 11;
const int ledMerah = 7, ledKuning = 6, ledHijau = 5;
const int pushButton = 4;

const int delayMerah = 2000, delayKuning = 1000;

int state = 0;  //0 untuk hijau, 1 untuk Merah, 2 untuk Kuning
bool buttonState = false;

long startTime, elapsedTime;


void setup() {
  myservo.attach(servoPin);

  // put your setup code here, to run once:
  pinMode(ledMerah, OUTPUT);
  pinMode(ledKuning, OUTPUT);
  pinMode(ledHijau, OUTPUT);
  pinMode(pushButton, INPUT);

}

void loop() {
  nilaiVolt = analogRead(potensioPin);
  posisi = map(nilaiVolt,0,1023, 0, 180);
  myservo.write(posisi);

  // put your main code here, to run repeatedly:
  buttonState = digitalRead(pushButton);
  if(buttonState){
    state = 1; //merah
    startTime = millis();
  }

  switch (state){
    case 0:{  //hijau
      digitalWrite(ledMerah, LOW);
      digitalWrite(ledKuning, LOW);
      digitalWrite(ledHijau, HIGH);
      break;
    }case 1:{ //merah
      digitalWrite(ledMerah, HIGH);
      digitalWrite(ledKuning, LOW);
      digitalWrite(ledHijau, LOW);

      elapsedTime = millis() - startTime;
      if(elapsedTime >= delayMerah){
        state = 2; //kuning
        startTime = millis();
      }

      break;
    }case 2:{ //kuning
      digitalWrite(ledMerah, LOW);
      digitalWrite(ledKuning, HIGH);
      digitalWrite(ledHijau, LOW);

      elapsedTime = millis() - startTime;
      if(elapsedTime >= delayKuning){
        state = 0; //hijau
      }

      break;
    }
  }

}
