#include<iostream>
#include<sstream>
#include "Room.h"
using namespace std;

Room::Room (string id,string name,string description) {
    this->id=id;
    this->name=name;
    this->description=description;

}
void Room ::setExit(Direction direction,string roomId) {
    switch (direction) {
        case NORTH:
            northId=roomId;
            break;
        case SOUTH:
            southId=roomId;
            break;
        case EAST:
            eastId=roomId;
            break;
        case WEST:
            westId=roomId;
            break;



    }
}
string Room:: getExit(Direction direction) {
    switch (direction) {
        case NORTH:
            return northId;
        case SOUTH:
            return southId;
        case EAST:
            return eastId;
        case WEST:
            return westId;
    }
    return "";

}
bool Room:: hasExit(Direction direction) {
    switch (direction) {
        case NORTH:
            return !northId.empty();
        case SOUTH:
            return !southId.empty();
        case EAST:
            return !eastId.empty();
        case WEST:
            return !westId.empty();
    }

}
void Room:: setGoal(bool goal) {
    this->goal=goal;

}
    bool Room:: isGoalRoom() {
        if (goal) {
            return true;
        }
        return false;

    }
string Room:: getId() {
    return id;
}
string Room:: getName() {
    return name;
}
string Room:: toString() {
    stringstream ss;

    ss<<"***********ROOM INFORMATION*********"<<endl;
    ss<<"Room Id: "<<id<<endl;
    ss<<"Room Name: "<<name<<endl;
    ss<<"Room Description: "<<description<<endl;
    ss<<"North: "<<northId<<endl;
    ss<<"South: "<<southId<<endl;
    ss<<"East: "<<eastId<<endl;
    ss<<"West: "<<westId<<endl;
    ss<<"Goal Room"<<goal<<endl;
    ss<<"*************************************"<<endl;
    return ss.str();

}