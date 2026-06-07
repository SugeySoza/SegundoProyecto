//
// Created by gabriel on 7/6/26.
//

#ifndef SEGUNDOPROYECTO_PLAYER_H
#define SEGUNDOPROYECTO_PLAYER_H

#include <iostream>
#include <sstream>
#include <vector>
#include <memory>

#include "Item.h"

using namespace std;

class Player {
private:
    string name;
    int health;
    int maxHealth;
    int attack;
    int score;
    string currentRoomId;
    vector <shared_ptr<Item>> invertory;

public:
    Player ( string name, int health, int maxHealth, int attack, string currentRoomId );

    void moveTo ( string roomId );
    void takeDamage ( int amount );
    void heal ( int amount );
    void increaseAttack ( int amount );
    void addItem ( Item* item);
    bool isAlive ();
    string getCurrentRoomId();
    string toString();
};


#endif //SEGUNDOPROYECTO_PLAYER_H