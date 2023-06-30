#include "Game.h"

void Game::displayText() {
    for(int i = 0; i < this->size; i++) {
        cout << this->text[i];
    }
    cout << endl;
}

void Game::drawGame(int idx) {
    int i;

    // Colored text used in prompt
    for(i = 0; i <= idx; i++) {
        if(this->correctIdx[i]) {
            cout << "\033[32m" << this->text[i] << "\033[0m";
        } else {
            cout << "\033[31m" << this->text[i] << "\033[0m";
        }
    }

    // Other letters
    for(i = idx+1; i < this->size; i++) {
        cout << this->text[i];
    }
    cout << endl;
}

void Game::evaluateGame(int idx, char a, int state) {
    if(state) {
        if(text[idx] == a) {
            this->goodA++;
            this->lastGIdx = idx;
            this->correctIdx[idx] = 1;
        }
    } else {
        if(idx == this->lastGIdx) {
            this->goodA--;
            this->correctIdx[idx] = 0;
        }
    }
}

int Game::getNbCorrect() {
    int cpt = 0;
    for(int i = 0; i < this->size; i++) {
        if(this->correctIdx[i]) {
            cpt++;
        }
    }
    return cpt;
}