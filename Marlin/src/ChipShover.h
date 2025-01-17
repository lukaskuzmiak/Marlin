#ifndef CHIPSHOVER_H
#define CHIPSHOVER_H

/*
 * Fan check, to show RPM of the FAN
 * This can be checked with M123 (https://marlinfw.org/docs/gcode/M123.html)
 * We need to pretend the fan is an extruder fan as chamber fan is not supported for fancheck
 */
#ifdef E0_FAN_TACHO_PIN
  #define HAS_FANCHECK 1
  #define HAS_E0_FAN_TACHO 1
#endif

#define TEMP_SENSOR_ADDR_X 0b1001011
#define TEMP_SENSOR_ADDR_Y 0b1001010
#define TEMP_SENSOR_ADDR_Z 0b1001001

void chipshover_tick();
void chipshover_loop();
void chipshover_setup();
#endif