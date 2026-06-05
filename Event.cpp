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

void Event::trigger()
{
    cout << "Has been triggered" << endl;
}

bool Even
