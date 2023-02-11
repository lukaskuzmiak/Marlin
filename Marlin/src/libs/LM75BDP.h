#pragma once

#include "../inc/MarlinConfig.h"

class LM75BDP {

  public:
    void init();
    bool readRaw(const uint8_t addr, int16_t *value);
    float temperature(const int16_t raw_val);
};

extern LM75BDP lm75bdp;
