//
// Created by gabriel on 5/6/26.
//

#ifndef SEGUNDOPROYECTO_EVENT_H
#define SEGUNDOPROYECTO_EVENT_H

#include <iostream>
#include <sstream>

using namespace std;

class Player;

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
    void execute(Player& player);
    void trigger();
    bool isTriggered();
    string getId() ;
    string getRoomId() ;
    string getType() ;
    string getDescription() ;
    int getValue() ;
    string toString() ;



};


#endif //SEGUNDOPROYECTO_EVENT_H