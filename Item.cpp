#include<iostream>
#include"Item.h"
#include<sstream>

#include "Player.h"
using namespace std;



Item::Item(string id,string name,string roomId,string type,int value) {
    this->id=id;
    this->name=name;
    this->roomId=roomId;
    this->type=type;
    this->value=value;
    collected=false;
}
void Item:: applyEffect (Player& player) {
    if (type == "HEALTH") {
        player.heal(value);
    }
    if (type == "ATTACK") {
        player.increaseAttack(value);
    }
    if (type == "SCORE") {
        player.increaseScore(value);
    }

}
void Item:: collect() { //Metodo cambia el estado del item
    collected=true;
}

bool Item::isCollected() const {
    return collected;
}

string Item::getId() const {
    return id;
}

string Item::getName() const {
    return name;
}

string Item::getRoomId() const {
    return roomId;
}

string Item::getType() const {
    return type;
}

int Item::getValue() const {
    return value;
}

string Item:: toString() const {
    stringstream s;

    s<<"***********DATOS DEL ITEM***********"<<endl;
    s<<"ID: "<<id<<endl;
    s<<"Name: "<<name<<endl;
    s<<"Room Id: "<<roomId<<endl;
    s<<"Type: "<<type<<endl;
    s<<"Value: "<<value<<endl;
    s<<"Collected: "<<(collected ? "Yes" : "No")<<endl;
    s<<"*************************************"<<endl;
    return s.str();

}
