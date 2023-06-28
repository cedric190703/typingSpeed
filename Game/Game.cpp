#include "Game.h"

void Game::drawPlayer() {
    // TODO
}

void Game::drawGame() {
    // TODO
}

void Game::evaluateGame(int idx, string text, char a, int state) {
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