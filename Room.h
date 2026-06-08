#ifndef SEGUNDOPROYECTO_ROOM_H
#define SEGUNDOPROYECTO_ROOM_H

#include<iostream>
#include"Direction.h"
using namespace std;

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
    void setExit(Direction direction,const string& roomId);
    string getExit(Direction direction) const;
    bool hasExit(Direction direction) const;
    void setGoal(bool goal);
    bool isGoalRoom() const;
    string getId() const;
    string getName() const;
    string getDescription() const;
    string toString() const;

};

#endif //SEGUNDOPROYECTO_ROOM_H