## Chip8 Interpreter

A Chip-8 Interpreter for Arduino Mega 2560

---

## Software

### Arduino Library Dependencies
  - PinChangeInterrupt v1.2.9 - https://github.com/NicoHood/PinChangeInterrupt

### Custom Library Dependencies
  - Chip8 Core - https://github.com/tommojphillips/Chip8-Core

  ### Building
 The project is built in the Arduino IDE

 - Git clone the repo `https://github.com/tommojphillips/Chip8-Arduino.git`
 - Git clone chip8 core `https://github.com/tommojphillips/Chip8-Core.git` into  sub folder, 'Chip8-Core' in your arduino library directory.

 - In the Arduino IDE, goto your library manager and search for `PinChangeInterrupt` and install it.

Your arduino directory structure should look like this:

```
 Arduino\
         |
         | -- Chip8\
         |
         | -- libraries\
                        | -- Chip8-Core\
                        |               | -- chip8_defines.h
                        |               | -- chip8.h
                        |               | -- chip8.c
                        |                
                        | -- PinChangeInterrupt\

```

## Hardware
 [To Do]

## Screenshots
![IMG_0435](https://github.com/user-attachments/assets/29143707-4e09-4c73-a924-41ef2aa24f95)
![IMG_0436](https://github.com/user-attachments/assets/a47b8223-9503-4932-98e4-ec71e8dddab0)
![IMG_0437](https://github.com/user-attachments/assets/31bc5c5e-9751-4ec2-af9e-bc3c4da11dc5)
