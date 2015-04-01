/*
 * Library to implement a morse code printer for International
 * Morse Code based on http://en.wikipedia.org/wiki/Morse_code
 */

#ifndef MorseCodePrinter_h
#define MorseCodePrinter_h

#include "Arduino.h"

class MorseCodePrinter
{
public:
    MorseCodePrinter(int pin);

    void print(int n);
    void print(char c);
    void print(char* s);
    void print(String s);

private:
    int _pin;

    const int DOT_DELAY = 100;
    const int DASH_DELAY = 3 * DOT_DELAY;
    const int CHAR_DELAY = DASH_DELAY;
    const int WORD_DELAY = 7 * DOT_DELAY;

    void dot();
    void dash();

    void dot(int i);
    void dash(int i);
};

#endif
