#include "../../inc/MarlinConfigPre.h"

#include "cs_temperature.h"
CSTemperature cs_temperature;

#include <limits.h>
#include "../../libs/LM75BDP.h"

int16_t CSTemperature::x_raw_temp, CSTemperature::y_raw_temp, CSTemperature::z_raw_temp;
bool CSTemperature::x_temp_valid, CSTemperature::y_temp_valid, CSTemperature::z_temp_valid;

void CSTemperature::init() {
    lm75bdp.init();
}

int16_t CSTemperature::readRaw() {
    // if all readings fail it will return SHRT_MAX which definitely triggers
    // board overtemp shutdown, if THERMAL_PROTECTION_BOARD is enabled
    int16_t raw_temp = SHRT_MAX;

    // Read raw values from the sensors, these are 8 times higher than real temp in C
    x_temp_valid = lm75bdp.readRaw(TEMP_SENSOR_ADDR_X, &x_raw_temp);
    y_temp_valid = lm75bdp.readRaw(TEMP_SENSOR_ADDR_Y, &y_raw_temp);
    z_temp_valid = lm75bdp.readRaw(TEMP_SENSOR_ADDR_Z, &z_raw_temp);

    // Choose the highest of the 3 temperatures as the Board temp
    if (x_temp_valid)
        raw_temp = x_raw_temp;
    
    if (y_temp_valid && y_raw_temp > raw_temp)
        raw_temp = y_raw_temp;

    if (z_temp_valid && z_raw_temp > raw_temp)
        raw_temp = z_raw_temp;

    return raw_temp;
}

float CSTemperature::temperature(const int16_t raw_val) {
    return lm75bdp.temperature(raw_val);
}
