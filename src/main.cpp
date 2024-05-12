#include <Arduino.h>
#include <HardwareSerial.h>

// HardwareSerial keypad_serial(1);

#define MSG_SIZE 128

char msg[MSG_SIZE];

void setup() {
Serial.begin(9600);
delay(10);

// keypad_serial.begin(9600, SERIAL_8N1, 7, 6);
Serial0.begin(9600);
delay(10);

// Serial1.begin(9600);
// delay(10);
}

void loop() {
int nb;

nb = Serial0.read(msg,MSG_SIZE);
Serial0.println("Dakodak");

Serial.print("Received -> ");
Serial.println(msg);
Serial.println(nb);

delay(1000);
}

