/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * ChipShover pin assignment
 *
 * The ChipShover builds only in PlatformIO currently, not in Arudino.
 *
 */

#ifndef __SAM3X8E__
  #error "Ensure building for ChipShover board"
#elif DISABLED(TMC_USE_SW_SPI)
  #error "ChipShover requires Software SPI. Enable TMC_USE_SW_SPI in Configuration_adv.h."
#endif

#define BOARD_INFO_NAME "ChipShover One"

//
// Limit Switches
//

#define X_ES0 6    /* PC24 */
#define X_ES1 3    /* PC28 */
#define X_ES2 106  /* PC27 */

#define Y_ES0 18   /* PA11 */
#define Y_ES1 23   /* PA14 */
#define Y_ES2 24   /* PA15 */

#define Z_ES0 29   /* PD6 */
#define Z_ES1 12   /* PD8 */
#define Z_ES2 30   /* PD9 */

#define X_MIN_PIN  X_ES1
#define X_MAX_PIN  X_ES2
#define Y_MIN_PIN  Y_ES1
#define Y_MAX_PIN  Y_ES2
#define Z_MIN_PIN  Z_ES1
#define Z_MAX_PIN  Z_ES2


//
// Steppers
//
#define X_STEP_PIN                           78   /* PB23 */
#define X_DIR_PIN                            2    /* PB25 */
#define X_ENABLE_PIN                         105  /* PB22 */
#ifndef X_CS_PIN
  #define X_CS_PIN                           53   /* PB14 */
#endif

#define Y_STEP_PIN                           27  /* PD2 */
#define Y_DIR_PIN                            26  /* PD1 */
#define Y_ENABLE_PIN                         25  /* PD0 */
#ifndef Y_CS_PIN
  #define Y_CS_PIN                           69  /* PA0 */
#endif

#define Z_STEP_PIN                           31  /* PA7 */
#define Z_DIR_PIN                            33  /* PC1  */
#define Z_ENABLE_PIN                         68  /* PA1 */
#ifndef Z_CS_PIN
  #define Z_CS_PIN                           11  /* PD7 */
#endif


//
// Software SPI pins for TMC2660 stepper drivers.
// Required for the Archim2 board.
//
#if ENABLED(TMC_USE_SW_SPI)
  #ifndef TMC_SW_MOSI
    #define TMC_SW_MOSI                      104 /* PC20 */
  #endif
  #ifndef TMC_SW_MISO
    #define TMC_SW_MISO                      9   /* PC21 */
  #endif
  #ifndef TMC_SW_SCK
    #define TMC_SW_SCK                       8   /* PC22 */
  #endif
#endif


//
// Misc. Functions
//

/* Fan */
#define CONTROLLER_FAN_PIN                   5 /* PC25 */
#define FAN_ON                               4 /* PC26 */
#define E0_FAN_TACHO_PIN                     61 /* PA2 */

/* LCD SCK */
#define SCK_PIN         76   /* PA27 */
#define MISO_PIN        74   /* PA25 */
#define MOSI_PIN        75   /* PA26 */
#define SDSS            77   /* PA28 */

#define LCD_SCK_PIN    SCK_PIN
#define LCD_MISO_PIN   MISO_PIN
#define LCD_MOSI_PIN   MOSI_PIN
#define LCD_SDSS       SDSS

/* LEDs on the board */
#define LED_ESTOP_PIN   62 /* PB17 */
#define LED_HBEAT_PIN   63 /* PB18 */
#define LED_BUSY_PIN    64 /* PB19 */
#define LED_STOP_PIN    20 /* PB12 */
#define LED_FAULT_PIN   21 /* PB13 */
#define LED_CLKOK_PIN   69 /* PA4  */
#define LED_I2COK_PIN   60 /* PA3  */
#define LED_BOOTOK_PIN  58 /* PA6  */

#define LED_PIN LED_HBEAT_PIN /* Default Heartbeat */

/* LEDs on the front panel */
#define LED_PANEL_JSEN   10  /* PC29 */
#define LED_PANEL_MODE   72  /* PC30 */
#define LED_PANEL_CLEAR  85  /* PB11 */
#define LED_PANEL_HOME   22  /* PB26 */

// I2C EEPROM with 4K of space
//#define I2C_EEPROM
//#define MARLIN_EEPROM_SIZE                0x1000

//#define PIN_WIRE_SDA 70 /* PA17 */
//#define PIN_WIRE_SCL 71 /* PA18 */
