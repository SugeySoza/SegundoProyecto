#include<iostream>
#include"Direction.h"
using namespace std;

#ifndef SEGUNDOPROYECTO_ROOM_H
#define SEGUNDOPROYECTO_ROOM_H

class Room {
private:
    string id;
    string name;
    string description;
    string northId;
    string southId;
    string eastId;
    string westId;
    bool goal;

public:
    Room (string id,string name,string description);
    void setExit(Direction direction,string roomId);
    string getExit(Direction direction);
    bool hasExit(Direction direction);
    void setGoal(bool goal);
    bool isGoalRoom();
    string getId();
    string getName();
    string toString();

};

#endif //SEGUNDOPROYECTO_ROOM_H