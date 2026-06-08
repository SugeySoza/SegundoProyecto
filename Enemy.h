//
// Created by gabriel on 7/6/26.
//

#ifndef SEGUNDOPROYECTO_ENEMY_H
#define SEGUNDOPROYECTO_ENEMY_H

#include <iostream>
#include <sstream>

using namespace std;

class Player;

class Enemy
{
private:
    string id;
    string name;
    string roomId;
    int health;
    int attack;
    bool defeated;

public:
    Enemy(string id, string name, string roomId, int health, int attack);
    void attackPlayer (Player& player);
    void takeDamage (int amount);
    bool isDefeated ();
    string getId() ;
    string getName() ;
    string getRoomId() ;
    int getHealth() ;
    int getAttack() ;
    string toString () ;
};


#endif //SEGUNDOPROYECTO_ENEMY_H