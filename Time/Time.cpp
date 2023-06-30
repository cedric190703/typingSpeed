#include "Time.h"
#include <string>

int nbChar(string text, int size) {
    int cpt = 0;
    for(int i = 0; i < size; i++) {
        if(text[i] != 32) {
            cpt++;
        }
    }
    return cpt;
}

int nbWord(string text, int size) {
    int cpt = 0;
    for(int i = 0; i < size; i++) {
        if(text[i] = 32) {
            cpt++;
        }
    }
    return cpt;
}

int avgWordLen(string text, int size) {
    int nbWords = nbWord(text, size);
    int s = 0;
    int sum = 0;
    for(int i = 0; i < size; i++) {
        if(text[i] == 32) {
            if(!s) {
                s = i;
            } else {
                sum += i - s;
                s = i;
            }
        }
    }
    return sum/nbWords;
}

int getNbWords(int correct, int size) {
    return correct/size;
}