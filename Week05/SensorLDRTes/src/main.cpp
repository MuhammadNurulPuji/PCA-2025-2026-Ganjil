#include <Arduino.h>

// koding untuk bikin led menyala flip flop

int ledPin = 13; // Pin LED pada board Arduino

void setup() {
  pinMode(ledPin, OUTPUT); // Set pin LED sebagai output
}

void loop() {
  digitalWrite(ledPin, HIGH); // Nyalakan LED
  delay(1000);                // Tunggu selama 1 detik
  digitalWrite(ledPin, LOW);  // Matikan LED
  delay(1000);                // Tunggu selama 1 detik
}