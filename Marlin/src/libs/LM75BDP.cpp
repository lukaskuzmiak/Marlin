#include "../inc/MarlinConfigPre.h"

#include "LM75BDP.h"
LM75BDP lm75bdp;

#include <Wire.h>

void LM75BDP::init() {
  Wire.begin();
}

bool LM75BDP::readRaw(const uint8_t addr, int16_t *value) {
  Wire.beginTransmission(I2C_ADDRESS(addr));
  Wire.write(0x00);
  Wire.endTransmission(false);
  uint8_t read = Wire.requestFrom(addr, (uint8_t) 2);
  if (read != 2)
    return false;

  *value = (Wire.read() << 8 | Wire.read()) >> 5;

  // sign extend negative numbers
  if (*value & 0x400)
    *value |= 0xFC00; // negative number
  
  return true;
}

float LM75BDP::temperature(const int16_t raw_val) {
  return raw_val * 0.125f;
}
