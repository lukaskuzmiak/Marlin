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

void chipshover_tick();
void chipshover_loop();
void chipshover_setup();
#endif