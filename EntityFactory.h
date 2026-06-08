//
// Created by gabriel on 8/6/26.
//

#ifndef SEGUNDOPROYECTO_ENTITYFACTORY_H
#define SEGUNDOPROYECTO_ENTITYFACTORY_H

#include <iostream>
#include <sstream>
#include <memory>
#include <vector>

#include "Room.h"
#include "Item.h"
#include "Enemy.h"
#include "Event.h"
#include "Player.h"

using namespace std;

class EntityFactory {
private:
    static vector<string> split(const string& str, char delimiter);
public:
    static Room* createRoom (string line);
    static Item* createItem(string line);
    static Enemy* createEnemy(string line);
    static Event* createEvent(string line);
    static Player* createPlayer(string line);
};


#endif //SEGUNDOPROYECTO_ENTITYFACTORY_H