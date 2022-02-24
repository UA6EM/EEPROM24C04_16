// READ DUMP AT24C1024 (C)UA6EM 22.02.2022 Страница 256 байт
// надо исправить библиотеку

#include <Wire.h>
#include <Eeprom24C1024.h>
#define EEPROM_ADDRESS 0x50

static Eeprom24C1024 eeprom(EEPROM_ADDRESS);

// Declare byte arrays.
byte inputBytes[1024] = { 0 };

// смещение адреса для выводы на печать
uint32_t j = 0;

void setup()
{
  // Initialize serial communication.
  Serial.begin(115200);

  // Initiliaze EEPROM library.
  eeprom.initialize();

  // Read array with bytes read from EEPROM memory.
  Serial.println(F("               Read bytes from EEPROM memory..."));
  uint32_t adr = 0;
  for (int str = 0; str < 128; str++)
  {
    eeprom.readBytes(adr, 1024, inputBytes);
    printDump();
    adr+=1024;
  }
}


void printDump(void) {
  // Print read bytes.
  for (int i = 0; i < 1024; i++)
  {
    if (i % 8 == 0)   Serial.print("  ");
    if (i % 16 == 0)  {
      Serial.println();
      if ((i + j) / 1048576 == 0)Serial.print("0");
      if ((i + j) / 65536 == 0)  Serial.print("0");
      if ((i + j) / 4096 == 0)   Serial.print("0");
      if ((i + j) / 256 == 0)    Serial.print("0");
      if ((i + j) / 16 == 0)     Serial.print("0");
      Serial.print((i + j), HEX);
      Serial.print("   ");
    }
    if (inputBytes[i] < 16)Serial.print("0");
    Serial.print(inputBytes[i], HEX);
    Serial.print(" ");
  }
  j = j + 1024;
}

void loop()
{
  // Здесь может быть ваш код
}
