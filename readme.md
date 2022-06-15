# Maltron - S Edition

** THIS IS A WORK IN PROGRESS, EXPECT BUGS AND DEBUGGING OPTIONS TO BE SET**

This repository contains historical documentation and instructions for creating a STM32 Black Pill based Keyboard
controller for Maltron Right Handed Keyboards running the open source QMK Firmware.

I'm hoping to get the new firmware into QMK mainstream at some stage in the future.

If anyone has any feedback please feel free to open an issue on the GitHub tracker, and I'll respond to you when I can.

All files can be found in their respective subdirectories as follows:
- EasyEDA Outfiles: This contains; Easy EDA, Altium, Gerber and SVG outputs of the Schematic and PCB design for the 
Maltron compatible STM32 Based controller.
- QMK Firmware: The QMK Firmware for the Maltron S Edition keyboard. This is a work in progress and not final yet.
- FreeCAD - PCB Stand Offs: This contains some simple PCB Stand-Offs that can be glued to the existing Maltron case's
baseplate. These are designed to use M2 self taping wood screws.
- Pictures: Pictures of the build for the historical document.

## Circuit notes
- All diodes are 1n4148
- Resistors for LEDS (R3-R10) are 100 Ohm
- Resistors for I2C Pull up (R1, R2) are 10K Ohm

## FreeCAD Notes
- Screws for PCB mounting are M2 Self Tapping Wood screws - Pan Head type.

## QMK Firmware Notes
- Large portions of this code were adapted from
[https://github.com/zvecr/qmk_firmware/blob/feature/ergodone_ctpc/keyboards/ktec/ergodone/matrix.c](https://github.com/zvecr/qmk_firmware/blob/feature/ergodone_ctpc/keyboards/ktec/ergodone/matrix.c)
so all credit to this user for their work. This helped me massively with the MCP23018 I/O Expander.
- Setup QMK as per [https://docs.qmk.fm/#/newbs_getting_started](https://docs.qmk.fm/#/newbs_getting_started)
- copy *mindrustuk* from the QMK Firmware directory to *keyboards/* in the QMK installation path
- NOTE: On first flash the STM32 Black Pill will need to be put into bootloader mode, do this by:
  - pushing and holding the `reset` button
  - then hold the `boot0` button
  - release the `reset` button
  - then release the `boot0` button. 
  - The device should now be in the bootloader mode ready to be flashed.
- compile using the following command ```qmk compile -kb mindrustuk/maltron_s_edition -km default```
- flash with the following command ```qmk flash -kb mindrustuk/maltron_s_edition -km default```
- Note: The firmware has `bootmagic` enabled. Any subsequent need to flash can be done by holding the `esc` key while
plugging in the keyboard, doing this will force the keyboard into bootloader mode on boot.
- Note: Debugging is currently enabled on this keyboard and output can be seen with ```qmk console -l```

## Miscellaneous Keyboard details
- The keyboard has four layers, these have not been fully implemented yet:
  - Layer 1: English
  - Layer 2: Numeric Pad
  - Layer 3: German
  - Layer 4: Media Keys

- Attempts have been made to preserve / replicate "one shot" behaviour and sticky keys on the Maltron keyboard. Please
see the source code for details on these.

- Bootmagic is set to use the escape key to flash firmware on boot, this could be re-mapped if desired:
  ```
  // Hold ESC on start up to boot into bootloader mode
  #define BOOTMAGIC_LITE_ROW 0
  #define BOOTMAGIC_LITE_COLUMN 14
  ```

## History
For a history of how this project started and evolved please see [history.md](history.md)
