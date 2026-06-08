//
// Created by XPC on 7/6/2026.
//

#ifndef SEGUNDOPROYECTO_WORD_H
#define SEGUNDOPROYECTO_WORD_H
#include <memory>
#include <vector>
#include <string>
#include "Item.h"
#include "Enemy.h"
#include "Event.h"
#include "Room.h"
using namespace std;


class World {
private:
    vector<shared_ptr<Room>> rooms;
    vector<shared_ptr<Item>> items;
    vector<shared_ptr<Enemy>> enemies;
    vector<shared_ptr<Event>> events;
    public:
    void addRoom(const shared_ptr<Room>& room);
    void addItem(const shared_ptr<Item>& item);
    void addEnemy(const shared_ptr<Enemy>& enemy);
    void addEvent(const shared_ptr<Event>& event);
    shared_ptr<Room> getRoomById(const string& id) const;
    vector<shared_ptr<Item>> getItemsInRoom(const string& roomId) const;
    vector<shared_ptr<Enemy>> getEnemiesInRoom(const string& roomId) const;
    vector<shared_ptr<Event>> getEventsInRoom(const string& roomId) const;
};


#endif //SEGUNDOPROYECTO_WORD_H