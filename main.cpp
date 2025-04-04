#include <Adafruit_NeoPixel.h>
#include "heart_effect.h"

#define NLED 110
#define PIN 3

#define BTN_FLECHE_GAUCHE 4
#define BTN_FLECHE_DROITE 5
#define BTN_RALENTISSEMENT 6
#define BTN_COEUR 7

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NLED, PIN, NEO_GRB + NEO_KHZ800);

// États des boutons
bool etatFlecheGauche = false;
bool etatFlecheDroite = false;
bool etatRalentissement = false;
bool lastBtnFlecheGauche = HIGH;
bool lastBtnFlecheDroite = HIGH;
bool lastBtnRalentissement = HIGH;

// Groupes LED
int flecheGauche[] = {15, 26, 37, 38, 39, 40, 50, 63};
int flecheDroite[] = {19, 32, 42, 43, 44, 45, 56, 67};
int ralentissement[] = {41, 53, 65, 89};

void setup() {
  pixels.begin();
  pixels.setBrightness(255);
  pixels.show();

  pinMode(BTN_FLECHE_GAUCHE, INPUT_PULLUP);
  pinMode(BTN_FLECHE_DROITE, INPUT_PULLUP);
  pinMode(BTN_RALENTISSEMENT, INPUT_PULLUP);
  pinMode(BTN_COEUR, INPUT_PULLUP);
}

void loop() {
  bool btnState;

  btnState = digitalRead(BTN_FLECHE_GAUCHE);
  if (btnState == LOW && lastBtnFlecheGauche == HIGH) {
    etatFlecheGauche = !etatFlecheGauche;
    delay(200);
  }
  lastBtnFlecheGauche = btnState;

  btnState = digitalRead(BTN_FLECHE_DROITE);
  if (btnState == LOW && lastBtnFlecheDroite == HIGH) {
    etatFlecheDroite = !etatFlecheDroite;
    delay(200);
  }
  lastBtnFlecheDroite = btnState;

  btnState = digitalRead(BTN_RALENTISSEMENT);
  if (btnState == LOW && lastBtnRalentissement == HIGH) {
    etatRalentissement = !etatRalentissement;
    delay(200);
  }
  lastBtnRalentissement = btnState;

  pixels.clear();

  if (etatFlecheGauche) {
    setColorToPixels(flecheGauche, sizeof(flecheGauche)/sizeof(int), pixels.Color(255, 255, 0));
    pixels.show(); delay(500); pixels.clear(); pixels.show(); delay(500);
  }

  if (etatFlecheDroite) {
    setColorToPixels(flecheDroite, sizeof(flecheDroite)/sizeof(int), pixels.Color(255, 255, 0));
    pixels.show(); delay(500); pixels.clear(); pixels.show(); delay(500);
  }

  if (etatRalentissement) {
    setColorToPixels(ralentissement, sizeof(ralentissement)/sizeof(int), pixels.Color(255, 0, 0));
  }

  if (digitalRead(BTN_COEUR) == LOW) {
    playHeartEffect(pixels);
  }

  pixels.show();
  delay(50);
}

void setColorToPixels(int indices[], int size, uint32_t color) {
  for (int i = 0; i < size; i++) {
    pixels.setPixelColor(indices[i], color);
  }
}
