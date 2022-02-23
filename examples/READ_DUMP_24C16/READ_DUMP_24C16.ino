// READ DUMP AT24C16 (C)UA6EM 22.02.2022

#include <Wire.h>
#include <Eeprom24C04_16.h>
#define EEPROM_ADDRESS 0x50

static Eeprom24C04_16 eeprom(EEPROM_ADDRESS);

// Declare byte arrays.
byte inputBytes[1024] = { 0 };

// смещение адреса для выводы на печать
int j = 0;

void setup()
{
  // Initialize serial communication.
  Serial.begin(115200);

  // Initiliaze EEPROM library.
  eeprom.initialize();

  // Read array with bytes read from EEPROM memory.
  Serial.println(F("               Read bytes from EEPROM memory..."));
  eeprom.readBytes(0, 1024, inputBytes);
  printDump();
  eeprom.readBytes(1024, 1024, inputBytes);
  printDump();
}


void printDump(void) {
  // Print read bytes.
  for (int i = 0; i < 1024; i++)
  {
    if (i % 8 == 0)   Serial.print("  ");
    if (i % 16 == 0)  {
      Serial.println();
      if ((i + j) / 4096 == 0)Serial.print("0");
      if ((i + j) / 256 == 0) Serial.print("0");
      if ((i + j) / 16 == 0)  Serial.print("0");
      Serial.print((i + j), HEX);
      Serial.print("   ");
    }
    if (inputBytes[i] < 10)Serial.print("0");
    Serial.print(inputBytes[i], HEX);
    Serial.print(" ");
  }
  j = j + 1024;
}

void loop()
{
  // Здесь может быть ваш код
}
