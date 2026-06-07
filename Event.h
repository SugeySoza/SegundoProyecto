//
// Created by gabriel on 5/6/26.
//

#ifndef SEGUNDOPROYECTO_EVENT_H
#define SEGUNDOPROYECTO_EVENT_H

#include <iostream>
#include <sstream>

using namespace std;

class Player{}; // temporaly

class Event
{
    string id;
    string roomId;
    string type;
    string description;
    int value;
    bool triggered;

public:
    Event (string id, string roomId, string type, string description, int value);

    void excecute(Player player);
    void trigger();
    bool isTriggered();
    string getRoomId();
    string toString();



};


#endif //SEGUNDOPROYECTO_EVENT_H