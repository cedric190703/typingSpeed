#pragma once
#include <string>

using namespace std;

class Player {
private:
    string name;
    int record;

public:
    Player(string name, int record) : name(name) , record(record) {};
    ~Player() {};
    string getName() { return this->name; };
    int getRecord() { return this->record; };
};