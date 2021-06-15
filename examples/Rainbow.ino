#include "SdLedsPlayer.h"

#define LEDS_PER_STRIP 300
const char *files_iter_rr[] = {"1","2","3","4","5","6","7","8","9","10","11","12","13"};

/*
 * SdLedsPlayer is the class that handles reading frames from file on SD card,
 * and writing it to the leds.
 * It needs to be initialized with LEDS_PER_STRIP (must match the leds per strips
 * of the file written to SD card).
 * It also needs to recive the leds buffer for OctoWS2811, should be initialized as follows
 */
DMAMEM int   display_memory[LEDS_PER_STRIP * 6]; 
int drawing_memory[LEDS_PER_STRIP * 6];
SdLedsPlayer sd_leds_player(LEDS_PER_STRIP, display_memory, drawing_memory);
int cnt=-1;
bool loopon = true;
void setup() {
  Serial.begin(115200);
  sd_leds_player.setup();
}


void loop() {
 if(!sd_leds_player.is_file_playing()) {
    if (loopon){ cnt=cnt+1;}
    if (cnt>12){cnt=0;}
    sd_leds_player.load_file(files_iter_rr[cnt]);    
  }
   delay(40);     
  sd_leds_player.show_next_frame();
}
