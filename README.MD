
## Chip8 Interpreter

A Chip-8 Interpreter for Arduino Mega 2560

---

### Arduino Library Dependencies
  - MCUFRIEND_kbv v3.0.0 - https://github.com/prenticedavid/MCUFRIEND_kbv ( used for the display )
  - PinChangeInterrupt v1.2.9 - https://github.com/NicoHood/PinChangeInterrupt ( used for pcINT ) 

### Custom Library Dependencies
  - Chip8 Core - https://github.com/tommojphillips/Chip8-Core

### Building
 The project is built in the Arduino IDE

 1. Clone the repo 

```
git clone https://github.com/tommojphillips/Chip8-Arduino.git
```

2. Clone `Chip8-Core` into your arduino library directory.

```
git clone https://github.com/tommojphillips/Chip8-Core.git
```
 - You need to make an edit in a header file. Go to `Chip8-Core/src/chip8_defines.h` and ensure `CHIP8_SHRINK_VIDEO_RAM` is not commented out! otherwise you will run out of ram when building.

3.) Add libraries to arduino library manager
  - Arduino IDE Library Manager: ( Tools -> Manage Libraries... )
   - Install `PinChangeInterrupt` library.
   - Install `Adafruit_BusIO` library and it's dependencies
   - Install `Adafruit_GFX_Library` library and it's dependencies
   - Install `MCUFRIEND_kbv` library and it's dependencies

Your arduino directory structure should look like this:

```
 Arduino\
         |
         | -- Chip8\
         |
         | -- libraries\             
                        | -- Adafruit_BusIO\
                        |
                        | -- Adafruit_GFX_Library\
                        |
                        | -- Chip8-Core\
                        |
                        | -- MCUFRIEND_kbv\
                        |
                        | -- PinChangeInterrupt\

```

## Hardware

## Screenshots
![IMG_0435](https://github.com/user-attachments/assets/29143707-4e09-4c73-a924-41ef2aa24f95)
![IMG_0436](https://github.com/user-attachments/assets/a47b8223-9503-4932-98e4-ec71e8dddab0)
![IMG_0437](https://github.com/user-attachments/assets/31bc5c5e-9751-4ec2-af9e-bc3c4da11dc5)
