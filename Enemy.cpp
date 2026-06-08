//
// Created by gabriel on 7/6/26.
//

#include "Enemy.h"

#include "Player.h"

Enemy::Enemy(string id, string name, string roomId, int health, int attack) :
id (id),
name (name),
roomId(roomId),
health(health),
attack(attack),
defeated(0)
{}

//D09DD0B0D0B9D0B4D0B820D181D0B5D0B1D0B520D187D0B5D181D182D0BDD183D18E20D180D0B0D0B1D0BED182D1832E

void Enemy::attackPlayer(Player& player) {
    if (defeated)
        return;
    player.takeDamage(attack);
}

void Enemy::takeDamage(int amount) {
    if (amount <= 0 || defeated)
        return;
    health -=amount;
    if (health <= 0) {
        health = 0;
        defeated = true;
    }
}

bool Enemy::isDefeated() {
    return defeated;
}

string Enemy::getId() {
    return id;
}

string Enemy::getName() {
    return name;
}

string Enemy::getRoomId() {
    return roomId;
}

int Enemy::getHealth() {
    return health;
}

int Enemy::getAttack() {
    return attack;
}

string Enemy::toString(){
    stringstream s;
    s << "--- Enemy ---" << endl;
    s << "ID        :       " << id << endl;
    s << "Name      :       " << name << endl;
    s << "RoomId    :       " << roomId << endl;
    s << "Health    :       " << health << endl;
    s << "Attack    :       " << attack << endl;
    s << "Defeated  :       " << (defeated ? "yes": "N0") <<endl;
    return s.str();
}
