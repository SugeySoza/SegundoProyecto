//
// Created by XPC on 7/6/2026.
//

#include "FileManager.h"
#include <fstream>
#include <sstream>
#include <iostream>

void FileManager::loadRooms(const string &filePath, World &world) {
        ifstream file(filePath);
        if (!file.is_open()) {
                cout << "File not found: " <<filePath << endl;
                return;
        }
        string line;

        while (getline(file, line)) {
                if (line.empty()) {
                        continue;
                }
                stringstream stream(line);

                string id;
                string name;
                string description;
                string northId;
                string southId;
                string eastId;
                string westId;
                string goalText;

                getline(stream, id, '|');
                getline(stream, name, '|');
                getline(stream, description, '|');
                getline(stream, northId, '|');
                getline(stream, southId, '|');
                getline(stream, eastId, '|');
                getline(stream, westId, '|');
                getline(stream, goalText, '|');

                shared_ptr<Room> room = make_shared<Room>(
                    id,
                    name,
                    description
                );

                if (northId != "NONE") {
                        room->setExit(
                            Direction::NORTH,
                            northId
                        );
                }

                if (southId != "NONE") {
                        room->setExit(
                            Direction::SOUTH,
                            southId
                        );
                }

                if (eastId != "NONE") {
                        room->setExit(
                            Direction::EAST,
                            eastId
                        );
                }

                if (westId != "NONE") {
                        room->setExit(
                            Direction::WEST,
                            westId
                        );
                }

                room->setGoal(goalText == "true");

                world.addRoom(room);
        }
        file.close();
}

void FileManager::loadItems(const string &filePath, World &world) {
        ifstream file(filePath);
        if (!file.is_open()) {
                cout << "File not found: " <<filePath << endl;
                return;
        }
        string line;
        while (getline(file, line)) {
                if (line.empty()) {
                        continue;
                }
                stringstream stream(line);
                string id;
                string name;
                string roomId;
                string type;
                string valueText;

                getline(stream, id, '|');
                getline(stream, name, '|');
                getline(stream, roomId, '|');
                getline(stream, type, '|');
                getline(stream, valueText, '|');

                int value = stoi(valueText);

                shared_ptr<Item> item = make_shared<Item>(id, name, roomId, type, value);
                world.addItem(item);
        }
        file.close();
}

void FileManager::loadEnemies(const string &filePath, World &world) {
        ifstream file(filePath);
        if (!file.is_open()) {
                cout << "File not found: " <<filePath << endl;
                return;
        }
        string line;
        while (getline(file, line)) {
                if (line.empty()) {
                        continue;
                }
                stringstream stream(line);

        string id;
        string name;
        string roomId;
        string healthText;
        string attackText;

        getline(stream, id, '|');
        getline(stream, name, '|');
        getline(stream, roomId, '|');
        getline(stream, healthText, '|');
        getline(stream, attackText, '|');

        int health = stoi(healthText);
        int attack = stoi(attackText);

        shared_ptr<Enemy> enemy = make_shared<Enemy>(id, name, roomId, health, attack);

        world.addEnemy(enemy);
        }
        file.close();
}

void FileManager::loadEvents(const string &filePath, World &world) {
        ifstream file(filePath);
        if (!file.is_open()) {
                cout << "File not found: " <<filePath << endl;
                return;
        }
        string line;
        while (getline(file, line)) {
                if (line.empty()) {
                        continue;
                }
                stringstream stream(line);

                string id;
                string roomId;
                string type;
                string description;
                string valueText;

                getline(stream, id, '|');
                getline(stream, roomId, '|');
                getline(stream, type, '|');
                getline(stream, description, '|');
                getline(stream, valueText, '|');

                int value = stoi(valueText);
                shared_ptr<Event> event = make_shared<Event>(id, roomId, type,description ,value);

                world.addEvent(event);
        }
        file.close();
}

shared_ptr<Player> FileManager::loadPlayer(const string &filePath) {
        ifstream file(filePath);
        if (!file.is_open()) {
                cout << "File not found: " <<filePath << endl;
                return nullptr;
        }
        string line;
        if (!getline(file,line)||line.empty()) {
                cout<<"Player file is empty"<<endl;
                return nullptr;
        }
        stringstream stream(line);

        string name;
        string healthText;
        string maxHealthText;
        string attackText;
        string currentRoomId;

        getline(stream, name, '|');
        getline(stream, healthText, '|');
        getline(stream, maxHealthText, '|');
        getline(stream, attackText, '|');
        getline(stream, currentRoomId, '|');

        int health = stoi(healthText);
        int maxHealth = stoi(maxHealthText);
        int attack = stoi(attackText);

        shared_ptr<Player> player = make_shared<Player>(name, health, maxHealth, attack, currentRoomId);
        file.close();
        return player;
}

void FileManager::loadWorld(World &world) {
        loadRooms("data/rooms.txt",world);
        loadItems("data/items.txt", world);
        loadEnemies("data/enemies.txt", world);
        loadEvents("data/events.txt", world);

}

