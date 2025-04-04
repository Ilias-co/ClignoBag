#include "../heart_effect.h"

int coeur[] = {3, 7, 14, 16, 18, 20, 25, 29, 33, 36, 46, 49, 57, 62, 68, 75, 79, 88, 90, 101};

void playHeartEffect(Adafruit_NeoPixel& strip) {
  for (int i = 0; i < sizeof(coeur)/sizeof(int); i++) {
    strip.setPixelColor(coeur[i], strip.Color(255, 192, 203)); // Couleur rose
  }
}
