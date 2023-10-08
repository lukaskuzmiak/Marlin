# ChipShover Marlin

This is a fork of the [original ChipSHOVER-Marlin repo](https://github.com/newaetech/ChipSHOVER-Marlin).

## Description of changes

The ChipShover changes has been merged into latest MarlinFirmware `2.1.x` (**not** `bugfix-2.1.x` as that is not meant for production). It is kept up to date with the upstream Marlin `2.1.x` branch from time to time.

### Rough list of (more major) changes
 - Inverted Z Axis - 0 is on the top and plunging down is in positive numbers
   - Utilizes `HOME_Z_FIRST`; Was able to get rid of swapping min/max endstop hack
 - Fix the MAX (far) endstops
 - [Implement LM75BDP library; refactor temp reading using the library](https://github.com/lukaskuzmiak/Marlin/commit/d91c4bf274f243162a59102935fb6047b2c83985)
 - [Automatic fan/temperature control](https://github.com/lukaskuzmiak/Marlin/commit/d11b93ae43e9752dd205e43d8e9df529a4f82c32)
   - Higher PWM for fan (less noisy)
   - Automatically read temps of all 3 drivers and uses highest to adjust fan speed based on temp (MUCH quieter)
 - Bunch of refactoring to fit into Marlin 2.1 - makes it kind of difficult to compare it back original NewAE patches :/

### Known issues
 - Both buzzer and fan control are on the same `TC2` timer - changing one affects the other - **requires HW change**
   - Fan PWM is on `PIO_PC25B_TIOA6` (`TC2_CHA6`)
   - Beeper/Buzzer is on `PIO_PC26B_TIOB6` (`TC2_CHB6`)
   - **It would be best to put these on native PWM lines if possible** (to not have to use timer to make PWM signals)

### Planned improvements (not yet implemented)
 - Diagonal jogging - If several moves (up+right, or down+left, etc.) are detected enqueue it as a single move command, that way we can go diagonally, not just one axis at the time
 - Refactor the joystick (`CJ25-82010`) to have its own driver class
 - Refactor the ChipShover TFT display
   - It needs to remember the current text size and implement clearLine on top of it
   - Ideally it can be a child class of the actual display class?
   - Put it in e.g., Marlin/src/feature/chipshover/cs_tft.[cpp,h]
 - The X/Y/Z positioners feature an optical endstop as well for more precise homing - let's see if it can be utilized

## Building, Uploading, Development

## Locally

 - Build with `pio run`
 - Upload with `pio run -t upload`
 - Clean with `pio run -t clean`
 - Verbose build with `pio run -v`
 
## Dev Container

 - Install `ms-vscode-remote.remote-containers` in your VSCode and follow the official [Installing Marlin (VSCode devcontainer)](https://marlinfw.org/docs/basics/install_devcontainer_vscode.html) documentation.

 - Use "Dev Containers: Open Folder in Container..." command in VSCode.

 - Use the nice PIO buttons on the bottom of VSCode to build, upload, etc.


# Original Marlin README below

<p align="center"><img src="buildroot/share/pixmaps/logo/marlin-outrun-nf-500.png" height="250" alt="MarlinFirmware's logo" /></p>

<h1 align="center">Marlin 3D Printer Firmware</h1>

<p align="center">
    <a href="/LICENSE"><img alt="GPL-V3.0 License" src="https://img.shields.io/github/license/marlinfirmware/marlin.svg"></a>
    <a href="https://github.com/MarlinFirmware/Marlin/graphs/contributors"><img alt="Contributors" src="https://img.shields.io/github/contributors/marlinfirmware/marlin.svg"></a>
    <a href="https://github.com/MarlinFirmware/Marlin/releases"><img alt="Last Release Date" src="https://img.shields.io/github/release-date/MarlinFirmware/Marlin"></a>
    <a href="https://github.com/MarlinFirmware/Marlin/actions"><img alt="CI Status" src="https://github.com/MarlinFirmware/Marlin/actions/workflows/test-builds.yml/badge.svg"></a>
    <a href="https://github.com/sponsors/thinkyhead"><img alt="GitHub Sponsors" src="https://img.shields.io/github/sponsors/thinkyhead?color=db61a2"></a>
    <br />
    <a href="https://fosstodon.org/@marlinfirmware"><img alt="Follow MarlinFirmware on Mastodon" src="https://img.shields.io/mastodon/follow/109450200866020466?domain=https%3A%2F%2Ffosstodon.org&logoColor=%2300B&style=social"></a>
</p>

Additional documentation can be found at the [Marlin Home Page](https://marlinfw.org/).
Please test this firmware and let us know if it misbehaves in any way. Volunteers are standing by!

## Marlin 2.1

Marlin 2.1 continues to support both 32-bit ARM and 8-bit AVR boards while adding support for up to 9 coordinated axes and to up to 8 extruders.

Download earlier versions of Marlin on the [Releases page](https://github.com/MarlinFirmware/Marlin/releases).

## Example Configurations

Before you can build Marlin for your machine you'll need a configuration for your specific hardware. Upon request, your vendor will be happy to provide you with the complete source code and configurations for your machine, but you'll need to get updated configuration files if you want to install a newer version of Marlin. Fortunately, Marlin users have contributed dozens of tested configurations to get you started. Visit the [MarlinFirmware/Configurations](https://github.com/MarlinFirmware/Configurations) repository to find the right configuration for your hardware.

## Building Marlin 2.1

To build and upload Marlin you will use one of these tools:

- The free [Visual Studio Code](https://code.visualstudio.com/download) using the [Auto Build Marlin](https://marlinfw.org/docs/basics/auto_build_marlin.html) extension.
- The free [Arduino IDE](https://www.arduino.cc/en/main/software) : See [Building Marlin with Arduino](https://marlinfw.org/docs/basics/install_arduino.html)
- You can also use VSCode with devcontainer : See [Installing Marlin (VSCode devcontainer)](http://marlinfw.org/docs/basics/install_devcontainer_vscode.html).

Marlin is optimized to build with the **PlatformIO IDE** extension for **Visual Studio Code**. You can still build Marlin with **Arduino IDE**, and we hope to improve the Arduino build experience, but at this time PlatformIO is the better choice.

## Hardware Abstraction Layer (HAL)

Marlin includes an abstraction layer to provide a common API for all the platforms it targets. This allows Marlin code to address the details of motion and user interface tasks at the lowest and highest levels with no system overhead, tying all events directly to the hardware clock.

Every new HAL opens up a world of hardware. At this time we need HALs for RP2040 and the Duet3D family of boards. A HAL that wraps an RTOS is an interesting concept that could be explored. Did you know that Marlin includes a Simulator that can run on Windows, macOS, and Linux? Join the Discord to help move these sub-projects forward!

## 8-Bit AVR Boards

A core tenet of this project is to keep supporting 8-bit AVR boards while also maintaining a single codebase that applies equally to all machines. We want casual hobbyists to benefit from the community's innovations as much as possible just as much as those with fancier machines. Plus, those old AVR-based machines are often the best for your testing and feedback!

### Supported Platforms

  Platform|MCU|Example Boards
  --------|---|-------
  [Arduino AVR](https://www.arduino.cc/)|ATmega|RAMPS, Melzi, RAMBo
  [Teensy++ 2.0](https://www.microchip.com/en-us/product/AT90USB1286)|AT90USB1286|Printrboard
  [Arduino Due](https://www.arduino.cc/en/Guide/ArduinoDue)|SAM3X8E|RAMPS-FD, RADDS, RAMPS4DUE
  [ESP32](https://github.com/espressif/arduino-esp32)|ESP32|FYSETC E4, E4d@BOX, MRR
  [LPC1768](https://www.nxp.com/products/processors-and-microcontrollers/arm-microcontrollers/general-purpose-mcus/lpc1700-cortex-m3/512-kb-flash-64-kb-sram-ethernet-usb-lqfp100-package:LPC1768FBD100)|ARM® Cortex-M3|MKS SBASE, Re-ARM, Selena Compact
  [LPC1769](https://www.nxp.com/products/processors-and-microcontrollers/arm-microcontrollers/general-purpose-mcus/lpc1700-cortex-m3/512-kb-flash-64-kb-sram-ethernet-usb-lqfp100-package:LPC1769FBD100)|ARM® Cortex-M3|Smoothieboard, Azteeg X5 mini, TH3D EZBoard
  [STM32F103](https://www.st.com/en/microcontrollers-microprocessors/stm32f103.html)|ARM® Cortex-M3|Malyan M200, GTM32 Pro, MKS Robin, BTT SKR Mini
  [STM32F401](https://www.st.com/en/microcontrollers-microprocessors/stm32f401.html)|ARM® Cortex-M4|ARMED, Rumba32, SKR Pro, Lerdge, FYSETC S6, Artillery Ruby
  [STM32F7x6](https://www.st.com/en/microcontrollers-microprocessors/stm32f7x6.html)|ARM® Cortex-M7|The Borg, RemRam V1
  [STM32G0B1RET6](https://www.st.com/en/microcontrollers-microprocessors/stm32g0x1.html)|ARM® Cortex-M0+|BigTreeTech SKR mini E3 V3.0
  [STM32H743xIT6](https://www.st.com/en/microcontrollers-microprocessors/stm32h743-753.html)|ARM® Cortex-M7|BigTreeTech SKR V3.0, SKR EZ V3.0, SKR SE BX V2.0/V3.0
  [SAMD51P20A](https://www.adafruit.com/product/4064)|ARM® Cortex-M4|Adafruit Grand Central M4
  [Teensy 3.5](https://www.pjrc.com/store/teensy35.html)|ARM® Cortex-M4|
  [Teensy 3.6](https://www.pjrc.com/store/teensy36.html)|ARM® Cortex-M4|
  [Teensy 4.0](https://www.pjrc.com/store/teensy40.html)|ARM® Cortex-M7|
  [Teensy 4.1](https://www.pjrc.com/store/teensy41.html)|ARM® Cortex-M7|
  Linux Native|x86/ARM/etc.|Raspberry Pi

## Submitting Patches

Proposed patches should be submitted as a Pull Request against the ([bugfix-2.1.x](https://github.com/MarlinFirmware/Marlin/tree/bugfix-2.1.x)) branch.

- Follow the [Coding Standards](https://marlinfw.org/docs/development/coding_standards.html) to gain points with the maintainers.
- Please submit Feature Requests and Bug Reports to the [Issue Queue](https://github.com/MarlinFirmware/Marlin/issues/new/choose). Support resources are also listed there.
- Whenever you add new features, be sure to add tests to `buildroot/tests` and then run your tests locally, if possible.
  - It's optional: Running all the tests on Windows might take a long time, and they will run anyway on GitHub.
  - If you're running the tests on Linux (or on WSL with the code on a Linux volume) the speed is much faster.
  - You can use `make tests-all-local` or `make tests-single-local TEST_TARGET=...`.
  - If you prefer Docker you can use `make tests-all-local-docker` or `make tests-all-local-docker TEST_TARGET=...`.

## Marlin Support

The Issue Queue is reserved for Bug Reports and Feature Requests. To get help with configuration and troubleshooting, please use the following resources:

- [Marlin Documentation](https://marlinfw.org) - Official Marlin documentation
- [Marlin Discord](https://discord.gg/n5NJ59y) - Discuss issues with Marlin users and developers
- Facebook Group ["Marlin Firmware"](https://www.facebook.com/groups/1049718498464482/)
- RepRap.org [Marlin Forum](https://forums.reprap.org/list.php?415)
- Facebook Group ["Marlin Firmware for 3D Printers"](https://www.facebook.com/groups/3Dtechtalk/)
- [Marlin Configuration](https://www.youtube.com/results?search_query=marlin+configuration) on YouTube

## Contributors

Marlin is constantly improving thanks to a huge number of contributors from all over the world bringing their specialties and talents. Huge thanks are due to [all the contributors](https://github.com/MarlinFirmware/Marlin/graphs/contributors) who regularly patch up bugs, help direct traffic, and basically keep Marlin from falling apart. Marlin's continued existence would not be possible without them.

## Administration

Regular users can open and close their own issues, but only the administrators can do project-related things like add labels, merge changes, set milestones, and kick trolls. The current Marlin admin team consists of:

<table align="center">
<tr><td>Project Maintainer</td></tr>
<tr><td>

 🇺🇸  **Scott Lahteine**
       [@thinkyhead](https://github.com/thinkyhead)
       [<kbd>  Donate 💸  </kbd>](https://www.thinkyhead.com/donate-to-marlin)

</td><td>

 🇺🇸  **Roxanne Neufeld**
       [@Roxy-3D](https://github.com/Roxy-3D)

 🇺🇸  **Keith Bennett**
       [@thisiskeithb](https://github.com/thisiskeithb)
       [<kbd>  Donate 💸  </kbd>](https://github.com/sponsors/thisiskeithb)

 🇺🇸  **Jason Smith**
       [@sjasonsmith](https://github.com/sjasonsmith)

</td><td>

 🇧🇷  **Victor Oliveira**
       [@rhapsodyv](https://github.com/rhapsodyv)

 🇬🇧  **Chris Pepper**
       [@p3p](https://github.com/p3p)

🇳🇿  **Peter Ellens**
       [@ellensp](https://github.com/ellensp)
       [<kbd>  Donate 💸  </kbd>](https://ko-fi.com/ellensp)

</td><td>

 🇺🇸  **Bob Kuhn**
       [@Bob-the-Kuhn](https://github.com/Bob-the-Kuhn)

 🇳🇱  **Erik van der Zalm**
       [@ErikZalm](https://github.com/ErikZalm)
       [<kbd>  Donate 💸  </kbd>](https://flattr.com/submit/auto?user_id=ErikZalm&url=https://github.com/MarlinFirmware/Marlin&title=Marlin&language=&tags=github&category=software)

</td></tr>
</table>

## License

Marlin is published under the [GPL license](/LICENSE) because we believe in open development. The GPL comes with both rights and obligations. Whether you use Marlin firmware as the driver for your open or closed-source product, you must keep Marlin open, and you must provide your compatible Marlin source code to end users upon request. The most straightforward way to comply with the Marlin license is to make a fork of Marlin on Github, perform your modifications, and direct users to your modified fork.

While we can't prevent the use of this code in products (3D printers, CNC, etc.) that are closed source or crippled by a patent, we would prefer that you choose another firmware or, better yet, make your own.
