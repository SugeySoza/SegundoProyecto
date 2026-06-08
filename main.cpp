#include <iostream>

#include <iostream>
#include <memory>
#include "Player.h"
#include "Item.h"
#include "Enemy.h"
#include "Event.h"
#include "Room.h"
#include "World.h"
#include "FileManager.h"
#include "EntityFactory.h"

using namespace std;

int main () {

    auto enemy = EntityFactory::createEnemy("001,TestEnemy,0001,100,30");
    auto room = EntityFactory::createRoom("0001,TestRoom,TestRoomIsDescription");
    auto item = EntityFactory::createItem("0001,TestItem,0001,TestItemType,10");
    auto event = EntityFactory::createEvent("0001,0001,TestEvent,TestEventDescription,20");
    auto player = EntityFactory::createPlayer("TestPlayer,100,120,30,000");

    cout << enemy -> toString() << endl;
    cout << room -> toString() << endl;
    cout << item -> toString() << endl;
    cout << event -> toString() << endl;
    cout << player -> toString() << endl;

    if (enemy != nullptr) delete enemy;
    if (room != nullptr) delete room;
    if (item != nullptr) delete item;
    if (event != nullptr) delete event;
    if (player != nullptr) delete player;

    //Вся работа!//



    return 0;
}