#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <chrono>
#include "Game/Game.h"
#include "Texts/Texts.h"
#include "Time/Time.h"

using namespace std;

// Function to enable raw terminal input mode
void enableRawMode() {
    termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &term);
}

// Function to disable raw terminal input mode
void disableRawMode() {
    termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= ICANON | ECHO;
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &term);
}

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
    cout << endl;

    int idx = 0;
    int state = 0; // 0 => supp | 1 => letter

    enableRawMode();
    char key;

    // start the chrono
    auto start = chrono::high_resolution_clock::now();

    // Draw sentence
    game.displayText();
    cout << "Start by typing a character" << endl;
    while(true) {
        // Get key pressed
        read(STDIN_FILENO, &key, 1);

        if(key == 127) {
            // Supp key
            state = 0;

            game.setBadChoice(idx);

            idx = idx == 0 ? idx : idx-1;

            cout << idx << endl;

            if(!idx) {
                game.displayText();
            } else {
                // Draw sentence
                game.drawGame(idx);
            }
        } else {
            // Letter found
            state = 1;

            if(idx > 0) {
                idx++;
                // Evaluate game
                game.evaluateGame(idx, key, state);
            } else {
                // Evaluate game
                game.evaluateGame(idx, key, state);
                idx++;
            }

            // Draw sentence
            game.drawGame(idx);

            
            if(idx >= strLen) {
                break;
            }
        }
    }

    // end clock
    auto stop = std::chrono::high_resolution_clock::now();

    auto durationMinutes = std::chrono::duration_cast<std::chrono::minutes>(stop - start);

    // Evaluate the final state of the game
    // Number of words = (Number of characters) / (Average word length)
    int nbWords = getNbWords(text, strLen);

    // Words per minute = (Number of words) / (Time in minutes)
    int wordsPMinutes = nbWords / static_cast<int>(durationMinutes.count());

    cout << "Number of words : " << nbWords << endl;
    cout << "Words per minute : " << wordsPMinutes << endl;

    return 0;
}
