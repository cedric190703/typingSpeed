#include "Game.h"

void Game::drawGame(int idx) {
    int i;

    // Colored text used in prompt
    for(i = 0; i < idx; i++) {
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
        }
    } else {
        if(idx == this->lastGIdx) {
            this->goodA--;
        }
    }
}