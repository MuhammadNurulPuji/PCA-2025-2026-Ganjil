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
    anode (long leg) attached to digital output 13
    cathode (short leg) attached to ground

  - Note: because most Arduinos have a built-in LED attached to pin 13 on the
    board, the LED is optional.

  created by David Cuartielles
  modified 30 Aug 2011
  By Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogInput

  Edited by Muhammad Nurul Puji
*/

int led[]={0,1,2,3,4,5,6,7};

int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

int jumlah_led;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  for(int i=0;i<8;i++){
    pinMode(led[i],OUTPUT);
  }
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);

  Serial.print("Nilai Digital = ");
  Serial.println(sensorValue);

  //jumlah_led=0;
  
  if(sensorValue>1021){
    jumlah_led=9;
  }else if(sensorValue>896){
    jumlah_led=8;
  }else if(sensorValue>768){
    jumlah_led=7;
  }else if(sensorValue>640){
    jumlah_led=6; 
  }else if(sensorValue>512){
    jumlah_led=5;
  }else if(sensorValue>384){
    jumlah_led=4;
  }else if(sensorValue>256){
    jumlah_led=3;
  }else if(sensorValue>128){
    jumlah_led=2;
  }else{
    jumlah_led=1;
  }

  for(int i=0;i<jumlah_led-1;i++){
    digitalWrite(led[i],HIGH);
  }

  delay(500);

  for(int i=0;i<8;i++){
    digitalWrite(led[i],LOW);
  }
  
}
