// READ DUMP AT24C08 (C)UA6EM 21.02.2022

#include <Wire.h>
#include <Eeprom24C04_16.h>
#define EEPROM_ADDRESS 0x50

static Eeprom24C04_16 eeprom(EEPROM_ADDRESS);

  // Declare byte arrays.
  byte inputBytes[1024] = { 0 };


void setup()
{
  // Initialize serial communication.
  Serial.begin(115200);

  // Initiliaze EEPROM library.
  eeprom.initialize();

  // Read array with bytes read from EEPROM memory.
  Serial.println("Read bytes from EEPROM memory...");
  eeprom.readBytes(0, 1024, inputBytes);

  // Print read bytes.
  for (int i = 0; i < 1024; i++)
  {
    if (i % 8 == 0)   Serial.print("  ");
    if (i % 16 == 0)  {
      Serial.println();    
      if (i / 4096 == 0)Serial.print("0");
      if (i / 256 == 0) Serial.print("0");
      if (i / 16 == 0)  Serial.print("0");
      Serial.print(i,HEX);
      Serial.print("   ");
    }
    if (inputBytes[i] < 10)Serial.print("0");
    Serial.print(inputBytes[i], HEX);
    Serial.print(" ");
  }
}


void loop()
    {    
      }
