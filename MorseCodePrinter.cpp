/*
 * Library to implement a morse code printer for International
 * Morse Code based on http://en.wikipedia.org/wiki/Morse_code
 *
 * Please refer to header file for more detail.
 */

/*
 * TODO:  work through XUnit book to develop a unit testing library
 * for digital I/O
 *
 * Could use https://code.google.com/p/arduinounit/, but XUnit may
 * be good exercise.
 */

#include "Arduino.h"
#include "MorseCodePrinter.h"

MorseCodePrinter::MorseCodePrinter(int pin) {
    pinMode(pin, OUTPUT);
    _pin = pin;
}

void MorseCodePrinter::dot() {
    digitalWrite(PIN, HIGH);
    delay(DOT_DELAY);
    digitalWrite(PIN, LOW);
    delay(DOT_DELAY);
}

void MorseCodePrinter::dash() {
    digitalWrite(PIN, HIGH);
    delay(DASH_DELAY);
    digitalWrite(PIN, LOW);
    delay(DOT_DELAY);
}

void MorseCodePrinter::dot(int i) {
    while(i>0) {
        dot();
        i--;
    }
}

void MorseCodePrinter::dash(int i) {
    while(i>0) {
        dash();
        i--;
    }
}

void MorseCodePrinter::print(char c) {
    bool endOfWord = false;

    switch (c) {
        case '0':
            dash(5);
            break;
        case '1':
            dot(1);
            dash(4);
            break;
        case '2':
            dot(2);
            dash(3);
            break;
        case '3':
            dot(3);
            dash(2);
            break;
        case '4':
            dot(4);
            dash(1);
            break;
        case '5':
            dot(5);
            break;
        case '6':
            dash(1);
            dot(4);
            break;
        case '7':
            dash(2);
            dot(3);
            break;
        case '8':
            dash(3);
            dot(2);
            break;
        case '9':
            dash(4);
            dot(1);
            break;
        default:
            // treat unrecognized chars as spaces
            endOfWord = true;
            delay(WORD_DELAY);
            break;
    }

    // after every character, delay
    if (!endOfWord) {
        delay(CHAR_DELAY);
    }
}

void MorseCodePrinter::print(char* s) {
    int i=0;
    while(s[i] != '\0') {
        print(s[i]);
    }
}

void MorseCodePrinter::print(String s) {
    for(int i; i<s.length(); i++) {
        print(s[i]);
    }
}
