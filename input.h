/* input.h: 
 */

#include "Arduino.h"
#include "PinChangeInterrupt.h" // PinChangeInterrupt lib by NicoHood in arduino library manager


/* Control pins */
#define KEY_PAUSE_PROGRAM_PIN 52
#define KEY_NEXT_PROGRAM_PIN 53 
#define KEY_PREV_PROGRAM_PIN 50
#define KEY_RESET_PIN 51
#define LED_CPU_HALT_PIN 25

/* Chip8 Keypad pins */
#define KEY_1_PIN 21
#define KEY_2_PIN 20
#define KEY_3_PIN 19
#define KEY_4_PIN 18

/* Audio buzzer */
#define AUDIO_PIN 24
#define AUDIO_FREQ 265
#define AUDIO_DURATION 50

extern CHIP8 chip8;
extern int current_program_index;

uint8_t reset_state = LOW;          // RESET button state
uint8_t pause_program_state = LOW;  // PAUSE PROGRAM button state
uint8_t next_program_state = LOW;   // NEXT PROGRAM button state
uint8_t prev_program_state = LOW;   // PREV PROGRAM button state

void int_k1(void);
void int_k2(void);
void int_k3(void);
void int_k4(void);

void isr_reset(void);
void isr_pause(void);
void isr_prev(void);
void isr_next(void);

void audio_init() {
  pinMode( AUDIO_PIN, OUTPUT );
}

void keypad_init(void) {
  pinMode( KEY_1_PIN, INPUT );
  attachInterrupt(digitalPinToInterrupt( KEY_1_PIN ), int_k1, CHANGE);
  
  pinMode( KEY_2_PIN, INPUT );
  attachInterrupt(digitalPinToInterrupt( KEY_2_PIN ), int_k2, CHANGE);
  
  pinMode( KEY_3_PIN, INPUT );
  attachInterrupt(digitalPinToInterrupt( KEY_3_PIN ), int_k3, CHANGE);

  pinMode( KEY_4_PIN, INPUT );
  attachInterrupt(digitalPinToInterrupt( KEY_4_PIN ), int_k4, CHANGE);

  pinMode( KEY_RESET_PIN, INPUT );  
  attachPCINT(digitalPinToPCINT(KEY_RESET_PIN), isr_reset, RISING);
  
  pinMode( KEY_NEXT_PROGRAM_PIN, INPUT );
  attachPCINT(digitalPinToPCINT(KEY_NEXT_PROGRAM_PIN), isr_next, RISING);
  
  pinMode( KEY_PREV_PROGRAM_PIN, INPUT );
  attachPCINT(digitalPinToPCINT(KEY_PREV_PROGRAM_PIN), isr_prev, RISING);

  pinMode( KEY_PAUSE_PROGRAM_PIN, INPUT );
  attachPCINT(digitalPinToPCINT(KEY_PAUSE_PROGRAM_PIN), isr_pause, RISING);
  
  pinMode( LED_CPU_HALT_PIN, OUTPUT );
}

void int_k1(void) {  
  uint8_t k1_state = digitalRead(KEY_1_PIN);
  CHIP8_SET_KEYPAD(chip8.keypad, ((current_program_keys & 0xF000) >> 12), k1_state);
}

void int_k2(void) {  
  uint8_t k2_state = digitalRead(KEY_2_PIN);
  CHIP8_SET_KEYPAD(chip8.keypad, ((current_program_keys & 0x0F00) >> 8), k2_state);
}

void int_k3(void) {
  uint8_t k3_state = digitalRead(KEY_3_PIN);
  CHIP8_SET_KEYPAD(chip8.keypad, ((current_program_keys & 0x00F0) >> 4), k3_state);
}

void int_k4(void) {
  uint8_t k4_state = digitalRead(KEY_4_PIN);
  CHIP8_SET_KEYPAD(chip8.keypad, (current_program_keys & 0x000F), k4_state);
}

void isr_reset(void) {
  chip8_reset_cpu(&chip8);
}

void isr_pause(void) {
  if (chip8.cpu_state == CHIP8_STATE_RUN) {
    chip8.cpu_state = CHIP8_STATE_HALT;
  }
  else {
    chip8.cpu_state = CHIP8_STATE_RUN;
  }
}

void isr_prev(void) {
  next_program(0);
}

void isr_next(void) {
  next_program(1);
}
