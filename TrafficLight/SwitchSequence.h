#include "Arduino.h"

class SwitchSequence {

  private:
    int pin;
    int quantum;
    int length;
    uint8_t *sequence;

  public:
    // Konstruktor
    SwitchSequence(int p_pin, int p_quantum) {
      pin = p_pin;
      quantum = p_quantum;
      pinMode(pin, OUTPUT);
    }

    void set_sequence(uint8_t* p_sequence, int p_length) {
      length = p_length;
      sequence = p_sequence;
    }

    void update() {
      // Aktuelle Zeit im Sequenzverlauf bestimmen
      // Zeit wird Modulo Gesamtlaenge der Sequenz berechnet
      unsigned long time = millis() % (quantum * length);
      // Index im Arry berechnen
      int idx = (int)(floor(time / quantum));
      // Status des Pins aus Sequenz lesen
      uint8_t state = sequence[idx];
      // Pin setzen
      digitalWrite(pin, state);
    }
};
