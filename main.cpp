#include <iostream>
#include <chrono>
#include "Game/Game.h"
#include "Texts/Texts.h"
#include "Time/Time.h"

int main() {
    // Select a text randomly
    string text = getText();
    int strLen = text.length();
    
    // Init objects
    Player* player = new Player("Name", 0);
    Game game(player, 0, text, strLen);

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

    char key;

    // start the chrono
    auto start = chrono::high_resolution_clock::now();

    while(true) {
        // Get key pressed
        cin >> key;

        if(key == 127) {
            // Supp key
            state = 0;
            idx = idx == 0 ? idx : idx--;

            // Evaluate game
            game.evaluateGame(idx, key, state);

            // Set boards
            game.setBadIdx(idx);

            // Draw sentence
            game.drawGame(idx);

        } else {
            // Other key (letters hopefully)
            if(key >= 'a' && key <= 'z') {
                // Letter found
            
                state = 1;
                // Evaluate game
                game.evaluateGame(idx, key, state);

                // set boards
                game.setCorrectIdx(idx);

                // Draw sentence
                game.drawGame(idx);

                idx++;
                if(idx == strLen) {
                    break;
                }

            } else {
                continue;
            }
        }
    }
    
    // end clock
    auto stop = chrono::high_resolution_clock::now();

    auto durationMinutes = chrono::duration_cast<chrono::minutes>(stop - start);

    // Evaluate the final state of the game
    // Number of words = (Number of characters) / (Average word length)
    int nbWords = getNbWords(text);

    // Words per minute = (Number of words) / (Time in minutes)
    int wordsPMinutes = getWordsPMinutes(text);

    cout << "Number of words : " << nbWords << endl;
    cout << "Words per minute : " << wordsPMinutes << endl;

    return 0;
}