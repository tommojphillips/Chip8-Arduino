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
![IMG_0436](https://github.com/user-attachments/assets/5faf43a6-7a85-4a2d-b106-f8b56c34180f)
![IMG_0435](https://github.com/user-attachments/assets/2e6e0471-167b-448a-aeb2-b6d01ebbe8ce)
![IMG_0437](https://github.com/user-attachments/assets/ffc9a391-83be-4178-85b3-5d7700d8eec1)
