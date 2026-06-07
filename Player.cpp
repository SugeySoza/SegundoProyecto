//
// Created by gabriel on 7/6/26.
//

#include "Player.h"

Player::Player(string name, int health, int maxHealth, int attack, string currentRoomId) :
name ( name ),
health (health ),
maxHealth( maxHealth ),
attack ( attack ),
currentRoomId( currentRoomId )
{}

void Player::moveTo(string roomId) { this -> currentRoomId = roomId; }

void Player::takeDamage(int amount) { this -> health -= amount; }

void Player::heal(int amount) { this -> health += amount; }

void Player::increaseAttack(int amount) { this -> attack += attack; }

void Player::addItem(Item *item) {
    if (currentRoomId ==item -> getRoomId())
    invertory.push_back(shared_ptr<Item> (item));
}

bool Player::isAlive() {
    if (health <= 0)
        return false;
    return true;
}

string Player::getCurrentRoomId() { return currentRoomId; }

string Player::toString() {
    stringstream s;

    s << "--- Player ---" << endl;
    s << "Name          :       " << name << endl;
    s << "MaxHealth     :       " << maxHealth << endl;
    s << "Attack        :       " << attack << endl;
    s << "Score         :       " << score << endl;
    s << "CurrentRoomId :       " << currentRoomId << endl;
    s << endl << "intentory : " << endl;

     for (const auto& item : invertory) {
         if (item != nullptr ) {
             s << "└--" << item->tostring() << endl;
         }
     }

    return s.str();
}
