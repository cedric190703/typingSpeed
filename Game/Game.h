#pragma once
#include "Player.h"

class Game {
private:
    Player player;
    int goodA;
    int lastGIdx;

public:
    Game(Player player, int goodA) : player(player), goodA(goodA) {};
    Player getPlayer() { return this->player; };
    int getGoodA() { return this->goodA; };
    void drawPlayer();
    void drawGame();
    void evaluateGame(int idx, string text, char a, int state);
};