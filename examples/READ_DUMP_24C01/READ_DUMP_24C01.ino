// READ DUMP AT24C01 (C)UA6EM 22.02.2022

#include <Wire.h>
#include <Eeprom24C01_16.h>
#define EEPROM_ADDRESS 0x50

static Eeprom24C01_16 eeprom(EEPROM_ADDRESS);

// Declare byte arrays.
byte inputBytes[128] = { 0 };


void setup()
{
  // Initialize serial communication.
  Serial.begin(115200);

  // Initiliaze EEPROM library.
  eeprom.initialize();

  // Read array with bytes read from EEPROM memory.
  Serial.println(F("               Read bytes from EEPROM memory..."));
  eeprom.readBytes_24C01_02(0, 128, inputBytes);

  // Print read bytes.
  for (int i = 0; i < 128; i++)
  {
    if (i % 8 == 0)   Serial.print("  ");
    if (i % 16 == 0)  {
      Serial.println();
      if (i / 4096 == 0)Serial.print("0");
      if (i / 256 == 0) Serial.print("0");
      if (i / 16 == 0)  Serial.print("0");
      Serial.print(i, HEX);
      Serial.print("   ");
    }
    if (inputBytes[i] < 10)Serial.print("0");
    Serial.print(inputBytes[i], HEX);
    Serial.print(" ");
  }
}


void loop()
{
  // Здесь может быть ваш код
}
