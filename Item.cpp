#include<iostream>
#include"Item.h"
#include<sstream>

#include "Player.h"
using namespace std;



Item::Item(string id,string name,string roomId,string type,int value) :
id (id),
name(name),
roomId(roomId),
type(type),
value(value),
collected(0)
{}
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

bool Item::isCollected()  {
    return collected;
}

string Item::getId()  {
    return id;
}

string Item::getName()  {
    return name;
}

string Item::getRoomId()  {
    return roomId;
}

string Item::getType()  {
    return type;
}

int Item::getValue()  {
    return value;
}

string Item:: toString()  {
    stringstream s;

    s<<"----ITEM----"<<endl;
    s<<"ID: "<<id<<endl;
    s<<"Name: "<<name<<endl;
    s<<"Room Id: "<<roomId<<endl;
    s<<"Type: "<<type<<endl;
    s<<"Value: "<<value<<endl;
    s<<"Collected: "<<(collected ? "Yes" : "No")<<endl;
    s<<"------------"<<endl;
    return s.str();

}
