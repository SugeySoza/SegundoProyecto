//
// Created by gabriel on 7/6/26.
//

#include "Enemy.h"

#include "Player.h"

Enemy::Enemy(string id, string name, string roomId, int health, int attack) {
    this->id = id;
    this->name = name;
    this->roomId = roomId;
    this->health = health;
    this->attack = attack;
    defeated = false;
}

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

string Enemy::getId() const {
    return id;
}

string Enemy::getName() const {
    return name;
}

string Enemy::getRoomId() const {
    return roomId;
}

int Enemy::getHealth() const {
    return health;
}

int Enemy::getAttack() const {
    return attack;
}

string Enemy::toString() const{
    stringstream s;
    s << "--- Enemy ---" << endl;
    s << "ID        :       " << id << endl;
    s << "Name      :       " << name << endl;
    s << "RoomId    :       " << roomId << endl;
    s << "Health    :       " << health << endl;
    s << "Attack    :       " << attack << endl;
    s << "Defeated  :       " << (defeated ? "Yes": "No") <<endl;
    return s.str();
}
