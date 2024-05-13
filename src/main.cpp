#include <Arduino.h>

#define INPUT_B0 6
#define INPUT_B1 7
#define INPUT_B2 8

#define INPUT_B4 5
#define INPUT_B5 4
#define INPUT_B6 3
#define INPUT_B7 2

int input_b4 = INPUT_B4;
int input_b5 = INPUT_B5;
int input_b6 = INPUT_B6;
int input_b7 = INPUT_B7;

int input_b0 = INPUT_B0;
int input_b1 = INPUT_B1;
int input_b2 = INPUT_B2;

char *keys_layout[6][8] = {
    {"0", "1", "2", "3", "4", "5", "6", "7"},
    {"8", "9", "N/A", "N/A", "_", "?", "L", "P"},
    {"+", "W", "E", "R", "T", "U", "I", "O"},
    {"Q", "S", "D", "F", "G", "H", "J", "K"},
    {"A", "Z", "X", "C", "V", "B", "M", "."},
    {"-", "*", "/", "=", "Y", "N", "Clr", "Ent"}};

void setup()
{
  Serial.begin(9600);
  delay(10);

  pinMode(input_b4, INPUT);
  pinMode(input_b5, INPUT);
  pinMode(input_b6, INPUT);
  pinMode(input_b7, INPUT);

  pinMode(input_b0, INPUT);
  pinMode(input_b1, INPUT);
  pinMode(input_b2, INPUT);
}

void loop()
{
  uint8_t scan_out;
  // Serial.print("Console *** Envoi 0x");
  // Serial.println(scan_in, HEX);

  delayMicroseconds(1000);

  scan_out =
      digitalRead(input_b7) * 0x80 +
      digitalRead(input_b6) * 0x40 +
      digitalRead(input_b5) * 0x20 +
      digitalRead(input_b4) * 0x10 +
      digitalRead(input_b2) * 0x04 +
      digitalRead(input_b1) * 0x02 +
      digitalRead(input_b0) * 0x01 ;

  // Serial.print("  - Reception 0x");
  // Serial.println(scan_out, HEX);
  // Serial.print("  --> ");
  if (!(scan_out & 0x10))
    Serial.println(keys_layout[scan_out & 7][(scan_out & 0xE0) >> 5]);

delay(10);
}
