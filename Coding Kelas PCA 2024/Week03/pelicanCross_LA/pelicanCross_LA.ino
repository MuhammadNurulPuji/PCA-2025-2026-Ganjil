#include <Servo.h>

Servo myservo;
int potensioPin = 0;
int val;

const int ledMerah=7, ledKuning=6, ledHijau=5;
const int button=4;

const int waktuMerah = 3000, waktuKuning=1000;
long startTime, elapsedTime;
int state = 0; //0 untuk hijau, 1 untuk kuning, 2 untuk merah
bool buttonState = false;

void setup() {
  myservo.attach(11);
  // put your setup code here, to run once:
  pinMode(ledMerah, OUTPUT);
  pinMode(ledKuning, OUTPUT);
  pinMode(ledHijau, OUTPUT);
  pinMode(button, INPUT);

}

void loop() {
  val=analogRead(potensioPin);
  val=map(val, 0, 1023, 0,180);
  myservo.write(val);
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(button);
  if(buttonState){
    state=2;
    startTime = millis(); //start time untuk warna merah
  }

  switch(state){
    case 0:{  //hijau
      digitalWrite(ledMerah,LOW);
      digitalWrite(ledKuning,LOW);
      digitalWrite(ledHijau,HIGH);
      break;
    }
    case 1:{  //kuning
      digitalWrite(ledMerah,LOW);
      digitalWrite(ledKuning,HIGH);
      digitalWrite(ledHijau,LOW);
      elapsedTime = millis() - startTime;
      if(elapsedTime >= waktuKuning){
        state = 0;
      }

      break;
    }
    case 2:{  //merah
      digitalWrite(ledMerah,HIGH);
      digitalWrite(ledKuning,LOW);
      digitalWrite(ledHijau,LOW);
      elapsedTime = millis() - startTime;
      if(elapsedTime >= waktuMerah){
        state = 1;
        startTime=millis(); //start time untuk kuning
      }

      break;
    }
  }

}
