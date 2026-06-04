#include<iostream>
#include"Item.h"
#include<sstream>
using namespace std;



Item::Item(string id,string name,string roomId,string type,int value, bool collected) {
    this->id=id;
    this->name=name;
    this->roomId=roomId;
    this->type=type;
    this->value=value;
    this->collected=false;


}
void Item:: applyEffect (Player&
    player) {  // para poder implementar este metodo hay que hacer archivo CVS o TXT para definir los efectos

}
void Item:: collect() { //Metodo cambia el estado del item
    if (!collected) {
        collected=true;
    }

}
bool Item:: isCollected() { // Metodo consulta el estado del item
    return collected;
}

string Item:: getRoomId() {
    return roomId;
}
string Item:: tostring() {
    stringstream ss;

    ss<<"***********DATOS DEL ITEM***********"<<endl;
    ss<<"ID: "<<id<<endl;
    ss<<"Name: "<<name<<endl;
    ss<<"Room Id: "<<roomId<<endl;
    ss<<"Type: "<<type<<endl;
    ss<<"Value: "<<value<<endl;
    ss<<"Collected: "<<collected<<endl;
    ss<<"*************************************"<<endl;
    return ss.str();

}
