//
// Created by gabriel on 7/6/26.
//

#include "Enemy.h"

Enemy::Enemy(string id, string name, string roomId, int health, int attack) :
id (id),
name (name),
roomId (roomId),
health (health),
attack (attack)
{}

void Enemy::attackPlayer(Player* player) { player -> takeDamage(attack); }

bool Enemy::isDefeated() { return defeated; }

string Enemy::getRoomId() { return roomId; }

string Enemy::toString()
{
    stringstream s;
    s << "--- Enemy ---" << endl;
    s << "ID        :       " << id << endl;
    s << "Name      :       " << name << endl;
    s << "RoomId    :       " << roomId << endl;
    s << "Health    :       " << health << endl;
    s << "Attack    :       " << attack << endl;
    s << "Defeated  :       " << defeated << endl;
    return s.str();
}
