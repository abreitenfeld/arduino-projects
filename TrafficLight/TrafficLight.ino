#include "SwitchSequence.h"

// Zeit in Millisekunden die eine Schaltung andauert
static const int QUANTUM = 200;
// Laenge einer Sequenz
static const int LENGTH = 20;
// Anzahl der angeschlossenen LEDs
static const int SEQUENCES = 3;

uint8_t seqLED1[LENGTH] = { HIGH,HIGH,LOW,LOW,LOW,HIGH,HIGH,HIGH,LOW,LOW,LOW,LOW,HIGH,LOW,HIGH,LOW,HIGH,LOW,LOW,LOW };
uint8_t seqLED2[LENGTH] = { LOW,HIGH,HIGH,LOW,HIGH,HIGH,LOW,HIGH,HIGH,LOW,HIGH,HIGH,HIGH,LOW,HIGH,LOW,HIGH,HIGH,LOW,HIGH };
uint8_t seqLED3[LENGTH] = { LOW,LOW,HIGH,HIGH,HIGH,LOW,LOW,LOW,HIGH,HIGH,HIGH,LOW,HIGH,LOW,HIGH,LOW,HIGH,LOW,HIGH,LOW };

SwitchSequence* sequences[SEQUENCES];

void setup() {
  // Schaltsequenzen erzeugen
  sequences[0] = new SwitchSequence(11, QUANTUM);
  sequences[1] = new SwitchSequence(12, QUANTUM);
  sequences[2] = new SwitchSequence(13, QUANTUM);
  
  // Sequenz an jeweilige Pin uebergeben
  sequences[0]->set_sequence(seqLED1, LENGTH);
  sequences[1]->set_sequence(seqLED2, LENGTH);
  sequences[2]->set_sequence(seqLED3, LENGTH);
}

void loop() {
  // Schaltsequenzen updaten
  for (int i = 0; i < SEQUENCES; i++) {
    sequences[i]->update();
  }
}
