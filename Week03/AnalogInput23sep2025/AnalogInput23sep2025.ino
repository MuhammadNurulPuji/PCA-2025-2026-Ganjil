/*
  Analog Input

  Demonstrates analog input by reading an analog sensor on analog pin 0 and
  turning on and off a light emitting diode(LED) connected to digital pin 13.
  The amount of time the LED will be on and off depends on the value obtained
  by analogRead().

  The circuit:
  - potentiometer
    center pin of the potentiometer to the analog input 0
    one side pin (either one) to ground
    the other side pin to +5V
  - LED
    anode (long leg) attached to digital output 13 through 220 ohm resistor
    cathode (short leg) attached to ground

  - Note: because most Arduinos have a built-in LED attached to pin 13 on the
    board, the LED is optional.

  created by David Cuartielles
  modified 30 Aug 2011
  By Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogInput
*/

int sensorPin = A0;   // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor

int ledPin [] = {2,3,4,5,6,7,8,9};
int jumlah_led;

void nyalakanLed(int jumlah){
  for(int i=0; i<=jumlah;i++){
    digitalWrite(ledPin[i], HIGH);
  }
  for(int j=jumlah+1; j<8;j++){
    digitalWrite(ledPin[j], LOW);
  }
}

void setup() {
  // declare the ledPin as an OUTPUT:
  for(int i=0;i<8;i++){
    pinMode(ledPin[i],OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);

  if (sensorValue >1021){
    jumlah_led=8;
  }else if(sensorValue >896){
    jumlah_led=7;
  }else if(sensorValue > 768){
    jumlah_led=6;
  }else if(sensorValue >640){
    jumlah_led=5;
  }else if(sensorValue > 512){
    jumlah_led=4;
  }else if(sensorValue > 384){
    jumlah_led=3;
  }else if(sensorValue >256){
    jumlah_led=2;
  }else if(sensorValue > 128){
    jumlah_led=1;
  }else{
    jumlah_led=0;
  }

nyalakanLed(jumlah_led);
delay(100);


}
