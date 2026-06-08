//
// Created by gabriel on 5/6/26.
//

#include "Event.h"

#include "Player.h"

Event::Event(string id, string roomId, string type, string description, int value):

id (id),
roomId(roomId),
type(type),
description(description),
value(value),
triggered(0)
{}

//D09DD0B0D0B9D0B4D0B820D181D0B5D0B1D0B520D187D0B5D181D182D0BDD183D18E20D180D0B0D0B1D0BED182D1832E

void Event::execute(Player& player)
{
    if (triggered) {
        return;
    }
    if (type == "HEALTH") {
       player.heal(value);
    }
    if (type == "DAMAGE") {
        player.takeDamage(value);
    }
    if (type == "ATTACK") {
        player.increaseAttack(value);
    }
    if (type == "SCORE") {
        player.increaseScore(value);
    }

    trigger();
}

void Event::trigger()
{
    triggered = true;
}

bool Event::isTriggered() {
    return triggered;
}

string Event::getId()  {
    return id;
}

string Event::getRoomId()  {
    return roomId;
}

string Event::getType()  {
    return type;
}

string Event::getDescription()  {
    return description;
}

int Event::getValue()  {
    return value;
}


string Event::toString() {
    stringstream s;
    s << "--- Event ---" << endl;
    s << "Id            :   " << id << endl;
    s << "RoomId        :   " << roomId << endl;
    s << "Type          :   " << type << endl;
    s << "Description   :   " << description << endl;
    s << "Value         :   " << value << endl;
    s << "Triggered     :   " << triggered << endl;
    return s.str();
}
