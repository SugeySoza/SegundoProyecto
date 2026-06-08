#include "World.h"
#include <algorithm>

template<typename T, typename Predicate>
static std::vector<std::shared_ptr<T>> filterEntities(
    const std::vector<std::shared_ptr<T>>& entities,
    Predicate predicate)
{
    std::vector<std::shared_ptr<T>> result;
    result.reserve(entities.size());

    for (const auto& entity : entities) {
        if (entity && predicate(entity)) {
            result.push_back(entity);
        }
    }

    return result;
}

void World::addRoom(const std::shared_ptr<Room>& room) {
    if (room)
        rooms.push_back(room);
}

void World::addItem(const std::shared_ptr<Item>& item) {
    if (item)
        items.push_back(item);
}

void World::addEnemy(const std::shared_ptr<Enemy>& enemy) {
    if (enemy)
        enemies.push_back(enemy);
}

void World::addEvent(const std::shared_ptr<Event>& event) {
    if (event)
        events.push_back(event);
}

std::shared_ptr<Room> World::getRoomById(const std::string& id) const {
    auto it = std::find_if(
        rooms.begin(),
        rooms.end(),
        [&id](const auto& room) {
            return room && room->getId() == id;
        });

    return (it != rooms.end()) ? *it : nullptr;
}

std::vector<std::shared_ptr<Item>> World::getItemsInRoom(const std::string& roomId) const {
    return filterEntities<Item>(
        items,
        [&roomId](const auto& item) {
            return item->getRoomId() == roomId &&
                   !item->isCollected();
        });
}

std::vector<std::shared_ptr<Enemy>> World::getEnemiesInRoom(const std::string& roomId) const {
    return filterEntities<Enemy>(
        enemies,
        [&roomId](const auto& enemy) {
            return enemy->getRoomId() == roomId &&
                   !enemy->isDefeated();
        });
}

std::vector<std::shared_ptr<Event>> World::getEventsInRoom(const std::string& roomId) const {
    return filterEntities<Event>(
        events,
        [&roomId](const auto& event) {
            return event->getRoomId() == roomId &&
                   !event->isTriggered();
        });
}