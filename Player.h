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
    vector <shared_ptr<Item>> inventory;

public:
    Player (string name, int health, int maxHealth, int attack,string currentRoomId);
    void moveTo (const string& roomId);
    void takeDamage (int amount);
    void heal (int amount);
    void increaseAttack (int amount);
    void increaseScore (int amount);
    void addItem (const shared_ptr<Item>& item);
    bool isAlive () const;
    string getName() const;
    int getHealth () const;
    int getMaxHealth () const;
    int getAttack() const;
    int getScore () const;
    string getCurrentRoomId() const;
    string toString() const;
};


#endif //SEGUNDOPROYECTO_PLAYER_H