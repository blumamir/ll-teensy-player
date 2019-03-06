#include "SdLedsPlayer.h"

const unsigned int leds_per_strip = 1000;

DMAMEM int display_memory[leds_per_strip * 6]; 
int drawing_memory[leds_per_strip * 6];
SdLedsPlayer sd_leds_player(leds_per_strip, display_memory, drawing_memory);

void setup() {
  Serial.begin(9600);
  while (!Serial) {
  }
  Serial.println("ll-teensy Started .");
  sd_leds_player.setup();
}

void loop() {
  
  if(!sd_leds_player.is_file_playing()) {
    sd_leds_player.load_file("out1");    
  }

  sd_leds_player.show_next_frame();
}
