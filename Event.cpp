//
// Created by gabriel on 5/6/26.
//

#include "Event.h"

Event::Event(string id, string roomId, string type, string description, int value) :
id (id ),
roomId(roomId ),
type ( type ),
description( description ),
value( value )
{}

void Event::trigger() { triggered != triggered; }

bool Event::isTriggered() { return triggered; }

string Event::getRoomId() { return roomId; }

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
