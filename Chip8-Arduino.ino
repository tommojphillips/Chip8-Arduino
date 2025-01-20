/* chip8.ino:
 *
 * Chip8 Interpreter for Arduino Mega 2560
 * Requires at least 21.5kb Flash + space for programs, 5.1kb dynamic ram.
 *
 * GitHub: https:\\github.com\tommojphillips 
 * Author: tommojphillips 2025
 */

#include "Arduino.h"
#include "chip8.h"      // chip8 cpu core
#include "programs.h"   // programs for chip8 in byte code
#include "input.h"      // input handlers
#include "display.h"

CHIP8 chip8;

/* The LCD is not fast enough to update every pixel every frame,
 so i added a second video ram array to check which pixels need updating. Inproves performance by 100% */
uint8_t shadow_video_ram[CHIP8_DISPLAY_BYTES] = { 0 };

uint8_t cpu_state = 0; // cached cpu state

#define CFG_INSTRS_PER_FRAME 12

//#define DEBUG_PRINT

//#define CFG_FRAME_LIMIT
#define CFG_FRAME_TARGET 16.667f // 60 hz - 16.667 ms/frame

#ifdef CFG_FRAME_LIMIT
float elapsed_time = 0;
unsigned long start_frame_time = 0;
float delta_time = 0;
#endif

void chip8_init() {
  chip8_init_cpu(&chip8);
  load_program();

  /* Set Chip8 CPU quirks */
  chip8.quirks |= CHIP8_QUIRK_CLS_ON_RESET; 
  chip8.quirks |= CHIP8_QUIRK_DISPLAY_CLIPPING; 
  chip8.quirks |= CHIP8_QUIRK_ZERO_VF_REGISTER; 
  chip8.quirks |=  CHIP8_QUIRK_SHIFT_X_REGISTER; 
  //chip8.quirks |= CHIP8_QUIRK_INCREMENT_I_REGISTER;
  //chip8.quirks |= CHIP8_QUIRK_JUMP_VX;
}

void chip8_update() {

  chip8_halt_check();

  if (chip8.cpu_state == CHIP8_STATE_EXE) {
    uint16_t instr_count = 0;
     while (++instr_count < CFG_INSTRS_PER_FRAME) {
        chip8_execute(&chip8);
      }

    chip8_step_timers(&chip8);
  }
}

void chip8_render(CHIP8* chip8) {
  uint8_t px;
  uint16_t col;
  for (uint16_t i = 0; i < CHIP8_NUM_PIXELS; ++i) {
    px = CHIP8_DISPLAY_GET_PX(chip8->display, i);
    if (px != CHIP8_DISPLAY_GET_PX(shadow_video_ram, i)) {
      if (px) {
        tft.fillRect(DISPLAY_X(i), DISPLAY_Y(i), DISPLAY_W, DISPLAY_H, CFG_PX_ON_COL);
        CHIP8_DISPLAY_SET_PX(shadow_video_ram, i);
      }
      else {
        tft.fillRect(DISPLAY_X(i), DISPLAY_Y(i), DISPLAY_W, DISPLAY_H, CFG_PX_OFF_COL);
        CHIP8_DISPLAY_CLR_PX(shadow_video_ram, i);
      }
    }
  }
}

void chip8_beep(CHIP8* chip8) {
  tone( AUDIO_PIN, AUDIO_FREQ, AUDIO_DURATION );
}

uint8_t chip8_random() {
  return (random() % 256);
}

void setup(void) {
  //Serial.begin(9600);
  tft_init();
  audio_init();
  keypad_init();
  chip8_init();
}

void loop(void) {

#ifdef CFG_FRAME_LIMIT
  delta_time = (micros() - start_frame_time) / 1000.0f;
	start_frame_time = micros();
  elapsed_time += delta_time;
  if (elapsed_time < CFG_FRAME_TARGET) return;
  elapsed_time = 0;
#endif

  chip8_update();
  chip8_render(&chip8);
}

void chip8_halt_check() {
  if (cpu_state != chip8.cpu_state) {
    cpu_state = chip8.cpu_state;
    if (cpu_state == CHIP8_STATE_EXE) {
      digitalWrite(LED_CPU_HALT_PIN, LOW);
    }
    else {
      digitalWrite(LED_CPU_HALT_PIN, HIGH);
      if (cpu_state == CHIP8_STATE_ERROR_OPCODE) {
        tone( AUDIO_PIN, 200, 550 );
      }
    }
  }
}
