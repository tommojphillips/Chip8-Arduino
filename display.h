/* display.h: implements display initialization and positioning offsets. 
 */

#include "Arduino.h"
#include <MCUFRIEND_kbv.h>  // Screen library

/* Config */
#define CFG_W 320
#define CFG_H 240
#define CFG_X 0
#define CFG_Y 0
#define CFG_PX_SPACE 0
#define CFG_PX_ON_COL 0xF0E3
#define CFG_PX_OFF_COL 0x0000

#define DISPLAY_PX_SIZE (CFG_W / CHIP8_DISPLAY_WIDTH )
#define DISPLAY_WIDTH (CHIP8_DISPLAY_WIDTH * ( DISPLAY_PX_SIZE + CFG_PX_SPACE))
#define DISPLAY_HEIGHT (CHIP8_DISPLAY_HEIGHT * ( DISPLAY_PX_SIZE + CFG_PX_SPACE))
#define DISPLAY_WIDTH_OFFSET (((CFG_W - DISPLAY_WIDTH ) >> 1)  - CFG_X)
#define DISPLAY_HEIGHT_OFFSET (((CFG_H - DISPLAY_HEIGHT ) >> 1) - CFG_Y)

#define DISPLAY_PX_X(i) ((i) & (CHIP8_DISPLAY_WIDTH-1))
#define DISPLAY_PX_Y(i) ((i) / CHIP8_DISPLAY_WIDTH)
#define DISPLAY_PX_OFFSET(i) ((i) * (DISPLAY_PX_SIZE + CFG_PX_SPACE))

#define DISPLAY_X(i) (DISPLAY_WIDTH_OFFSET + DISPLAY_PX_OFFSET(DISPLAY_PX_X(i)))
#define DISPLAY_Y(i) (DISPLAY_HEIGHT_OFFSET + DISPLAY_PX_OFFSET(DISPLAY_PX_Y(i)))
#define DISPLAY_W (DISPLAY_PX_SIZE)
#define DISPLAY_H (DISPLAY_PX_SIZE)

MCUFRIEND_kbv tft;

/* TFT Init */
void tft_init(void) {
    tft.reset();
    tft.begin(tft.readID());
    tft.setRotation(3);
    tft.fillScreen(CFG_PX_OFF_COL);
}
