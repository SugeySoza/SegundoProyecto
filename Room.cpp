#include<iostream>
#include<sstream>
#include "Room.h"
using namespace std;

Room::Room (string id,string name,string description) {
    this->id=id;
    this->name=name;
    this->description=description;
    northId="";
    southId="";
    eastId="";
    westId="";
    goal=false;

}
void Room ::setExit(Direction direction, const string& roomId) {
    switch (direction) {
        case Direction::NORTH:
            northId=roomId;
            break;
        case Direction::SOUTH:
            southId=roomId;
            break;
        case Direction::EAST:
            eastId=roomId;
            break;
        case Direction::WEST:
            westId=roomId;
            break;

    }
}
string Room:: getExit(Direction direction)const {
    switch (direction) {
        case Direction::NORTH:
            return northId;
        case Direction::SOUTH:
            return southId;
        case Direction::EAST:
            return eastId;
        case Direction::WEST:
            return westId;
    }
    return "";

}
bool Room:: hasExit(Direction direction)const {
    return !getExit(direction).empty();
   /* switch (direction) {
        case NORTH:
            return !northId.empty();
        case SOUTH:
            return !southId.empty();
        case EAST:
            return !eastId.empty();
        case WEST:
            return !westId.empty();
    }
    */
}
void Room:: setGoal(bool goal) {
    this->goal=goal;
}

bool Room::isGoalRoom() const {
    return goal;
}

string Room::getId() const {
    return id;
}

string Room::getName() const {
    return name;
}

string Room::getDescription() const {
    return description;
}


string Room:: toString()const {
    stringstream s;

    s<<"***********ROOM INFORMATION*********"<<endl;
    s<<"Room Id: "<<id<<endl;
    s<<"Room Name: "<<name<<endl;
    s<<"Room Description: "<<description<<endl;
    s<<"North:"<<(northId.empty()? "No exit":northId)<<endl;
    s<<"South:"<<(southId.empty()? "No exit":southId)<<endl;
    s<<"East:"<<(eastId.empty()? "No exit":eastId)<<endl;
    s<<"West:"<<(westId.empty()? "No exit":westId)<<endl;
    s<<"Goal room: "<<(goal ? "Yes" : "No")<<endl;
    s<<"*************************************"<<endl;
    return s.str();

}
