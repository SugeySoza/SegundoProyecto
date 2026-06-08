//
// Created by gabriel on 7/6/26.
//

#include "Player.h"

Player::Player(string name, int health, int maxHealth, int attack, string currentRoomId) {
    this -> name = name;
    this -> health = health;
    this -> maxHealth = maxHealth;
    this -> attack = attack;
    this->score = 0;
    this -> currentRoomId = currentRoomId;
}

void Player::moveTo(const string& roomId) { this -> currentRoomId = roomId; }

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

void Player::addItem(const shared_ptr<Item>& item) {
    if (item == nullptr)
        return;
    inventory.push_back(item);
}

bool Player::isAlive() const {
    return health > 0;
}

string Player::getName() const {
    return name;
}

int Player::getHealth() const {
    return health;
}

int Player::getMaxHealth() const {
    return maxHealth;
}

int Player::getAttack() const {
    return attack;
}

int Player::getScore() const {
    return score;
}

string Player::getCurrentRoomId()const { return currentRoomId; }

string Player::toString()const {
    stringstream s;

    s << "--- Player ---" << endl;
    s << "Name          :       " << name << endl;
    s << "MaxHealth     :       " << maxHealth << endl;
    s << "Attack        :       " << attack << endl;
    s << "Score         :       " << score << endl;
    s << "CurrentRoom   :       " << currentRoomId << endl;

    s << endl << "invtentory : " << endl;
    if (inventory.empty()) {
        s<<"Empty inventory" << endl;
    }else
        for (const auto i : inventory) {
            if (i != nullptr) {
                s<<"-"<<i->toString()<<endl;
            }
        }
    return s.str();
}
