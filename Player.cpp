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

void Player::addItem(Item *item) { invertory.push_back(shared_ptr<Item> (item));}

bool Player::isAlive() {
    if (health <= 0)
        return false;
    return true;
}

string Player::getCurrentRoomId() { return currentRoomId; }

string Player::toString() {
    stringstream s;

    s << "--- Player ---" << endl;

}
