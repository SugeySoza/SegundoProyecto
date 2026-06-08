//
// Created by XPC on 7/6/2026.
//

#include "World.h"

void World::addRoom(const shared_ptr<Room> &room) {
    if (room != nullptr) {
        rooms.push_back(room);
    }
}

void World::addItem(const shared_ptr<Item> &item) {
    if (item != nullptr) {
        items.push_back(item);
    }
}

void World::addEnemy(const shared_ptr<Enemy> &enemy) {
    if (enemy != nullptr) {
        enemies.push_back(enemy);
    }
}

void World::addEvent(const shared_ptr<Event> &event) {
    if (event != nullptr) {
        events.push_back(event);
    }
}

shared_ptr<Room> World::getRoomById(const string &id) const {
    for (const shared_ptr<Room>& room : rooms) {
        if (room != nullptr && room->getId() == id) {
            return room;
        }
    }
    return nullptr;
}

vector<shared_ptr<Item>> World::getItemsInRoom(const string &roomId) const {
    vector<shared_ptr<Item>> roomItems;
    for (const shared_ptr<Item>& item : items) {
        if (item != nullptr && item->getRoomId() == roomId && !item->isCollected()) {
            roomItems.push_back(item);
        }
    }
    return roomItems;
}

vector<shared_ptr<Enemy>> World::getEnemiesInRoom(const string &roomId) const {
    vector<shared_ptr<Enemy>> roomEnemies;
    for (const shared_ptr<Enemy>& enemy : enemies) {
        if (enemy != nullptr && enemy->getRoomId() == roomId && !enemy->isDefeated()) {
            roomEnemies.push_back(enemy);
        }
    }
    return roomEnemies;
}

vector<shared_ptr<Event>> World::getEventsInRoom(const string &roomId) const {
    vector<shared_ptr<Event>> roomEvents;
    for (const shared_ptr<Event>& event : events) {
        if (event != nullptr && event->getRoomId() == roomId && !event->isTriggered()) {
            roomEvents.push_back(event);
        }
    }
    return roomEvents;
}
