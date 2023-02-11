#pragma once

#include "../../inc/MarlinConfig.h"

class CSTemperature {

  public:
    static int16_t x_raw_temp, y_raw_temp, z_raw_temp;
    static bool x_temp_valid, y_temp_valid, z_temp_valid;
    void init();
    int16_t readRaw();
    float temperature(const int16_t raw_val);
};

extern CSTemperature cs_temperature;
