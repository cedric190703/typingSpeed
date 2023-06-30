#pragma once
#include <iostream>
#include "Player.h"

class Game {
private:
    Player* player;
    int goodA;
    int lastGIdx;
    int* correctIdx;
    string text;
    int size;

public:
    Game(Player* player, int goodA, string text, int size) : player(player), goodA(goodA), text(text), size(size) {
        this->correctIdx = new int[this->size];
        for(int i = 0; i < this->size; i++) {
            this->correctIdx[i] = 0;
        }
    };
    ~Game() {
        delete[] correctIdx;
        delete player;
    };
    Player* getPlayer() { return this->player; };
    int getGoodA() { return this->goodA; };
    void drawGame(int);
    void evaluateGame(int idx, char a, int state);
    void displayText();
    void setBadChoice(int idx) { this->correctIdx[idx] = 0; };
    int getNbCorrect();
};