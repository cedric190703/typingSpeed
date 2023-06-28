#include <iostream>
#include <conio.h>
#include "Game/Game.h"
#include "Texts/Texts.h"
#include "Time/Time.h"

int main() {
    // Init objects
    Player player("Name", 0);
    Game game(player, 0);

    // Select a text randomly
    string text = getText();

    cout << "Type 'start' to start the game : " << endl;
    string st;
    cin >> st;
    while(st != "start" && st != "s") {
        cout << endl;
        cout << "Invalid instruction" << endl;
        cout << "Try again : " << endl;
        cin >> st;
    }

    int idx = 0;
    int state = 0; // 0 => supp | 1 => letter

    while(true) {
        // Get key pressed
        if (_kbhit()) {
            key = _getch();
            if(key == 127) {
                // Supp key
                state = 0;

            } else {
                // Other key (letters hopefully)
                if(key >= 'a' && key <= 'z') {
                    // Letter found
                    state = 1;
                } else {
                    continue;
                }
            }
        }
        // Evaluate game
        game.evaluateGame(idx, text, key, state);

        // Draw sentence
        game.drawGame();
    }

    // Evaluate the final state of the game
    // Number of words = (Number of characters) / (Average word length)
    int nbWords;

    // Words per minute = (Number of words) / (Time in minutes)
    int wordsPMinutes;

    cout << "Number of words : " << nbWords << endl;
    cout << "Words per minute : " << wordsPMinutes << endl;

    return 0;
}