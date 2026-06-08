//
// Created by XPC on 7/6/2026.
//

#ifndef SEGUNDOPROYECTO_FILEMANAGER_H
#define SEGUNDOPROYECTO_FILEMANAGER_H
#include "World.h"
#include <string>
#include "Player.h"
using namespace std;

class FileManager {
    public:
    void loadRooms(const string& filePath, World& world);
    void loadItems(const string& filePath, World& world);
    void loadEnemies(const string& filePath, World& world);
    void loadEvents(const string& filePath, World& world);
    shared_ptr<Player> loadPlayer(const string& filePath);
    void loadWorld(World& world);
};


#endif //SEGUNDOPROYECTO_FILEMANAGER_H