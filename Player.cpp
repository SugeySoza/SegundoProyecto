//
// Created by gabriel on 7/6/26.
//

#include "Player.h"

Player::Player(string name, int health, int maxHealth, int attack, string currentRoomId) :
name (name),
health (health),
maxHealth(maxHealth),
attack(attack),
score(0),
currentRoomId(currentRoomId)
{}

void Player::moveTo( string& roomId) { this -> currentRoomId = roomId; }

void Player::takeDamage(int amount) {
    if (amount <= 0)
        return;
    health -= amount;
    if (health < 0) {
        health = 0;
    }
}

void Player::heal(int amount) {
    if (amount <= 0)
        return;
    health += amount;
    if (health > maxHealth) {
        health = maxHealth;
    }
}

void Player::increaseAttack(int amount) {
    if (amount > 0)
        attack+=amount;
}

void Player::increaseScore(int amount) {
    if (amount > 0)
        score+=amount;
}

void Player::addItem( shared_ptr<Item>& item) {
    if (item == nullptr)
        return;
    inventory.push_back(item);
}

bool Player::isAlive()  {
    return health > 0;
}

string Player::getName()  {
    return name;
}

int Player::getHealth()  {
    return health;
}

int Player::getMaxHealth()  {
    return maxHealth;
}

int Player::getAttack()  {
    return attack;
}

int Player::getScore()  {
    return score;
}

string Player::getCurrentRoomId() { return currentRoomId; }

string Player::toString() {
    stringstream s;

    s << "--- Player ---" << endl;
    s << "Name          :       " << name << endl;
    s << "MaxHealth     :       " << maxHealth << endl;
    s << "Attack        :       " << attack << endl;
    s << "Score         :       " << score << endl;
    s << "CurrentRoom   :       " << currentRoomId << endl;

    s << endl << "invtentory : " << endl;
    if (!inventory.empty()) {
        for (const auto i : inventory) {
            if (i != nullptr) {
                s<<"└--"<<i->toString()<<endl;
            }
        }
    }else {
        s<<"Empty inventory" << endl;
    }

    return s.str();
}
