//
// Created by gabriel on 5/6/26.
//

#include "Event.h"

#include "Player.h"

Event::Event(string id, string roomId, string type, string description, int value) {
    this->id = id;
    this->roomId = roomId;
    this->type = type;
    this->description = description;
    this->value = value;
    triggered = false;
}

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

bool Event::isTriggered()const {
    return triggered;
}

string Event::getId() const {
    return id;
}

string Event::getRoomId() const {
    return roomId;
}

string Event::getType() const {
    return type;
}

string Event::getDescription() const {
    return description;
}

int Event::getValue() const {
    return value;
}


string Event::toString() const{
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
