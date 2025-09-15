const int ledRed = 7, ledYellow = 6, ledGreen=5;
const int delayRed = 4000, delayYellow = 1000, delayGreen = 2000;
const int button = 4;

int state = 0;
bool buttonstate = false;
int timestart, elapsedtime;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT); 
}

void loop() {
  buttonstate = digitalRead(button);
  if (buttonstate==true){
    state=2;
    timestart = millis();
  }
  // put your main code here, to run repeatedly:
  switch (state){
    case 0:{  //hijau
      digitalWrite(ledRed, LOW);
      digitalWrite(ledYellow, LOW);
      digitalWrite(ledGreen, HIGH);
      break;
    }case 1:{ //kuning
      digitalWrite(ledRed, LOW);
      digitalWrite(ledYellow, HIGH);
      digitalWrite(ledGreen, LOW);
      elapsedtime = millis()-timestart;
      if(elapsedtime>=delayYellow){
        timestart = millis();
        state=0;
      }
      break;
    }case 2:{ //merah
      digitalWrite(ledRed, HIGH);
      digitalWrite(ledYellow, LOW);
      digitalWrite(ledGreen, LOW);
      elapsedtime = millis()-timestart;
      if(elapsedtime>=delayRed){
        timestart = millis();
        state=1;
      }
      break;
    }

  }
}
