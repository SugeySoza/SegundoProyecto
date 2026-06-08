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

using namespace std;

int main () {
    World world;
    FileManager fileManager;

    fileManager.loadWorld(world);

    shared_ptr<Player> player =
        fileManager.loadPlayer("data/player.txt");

    if (player != nullptr) {
        cout << player->toString() << endl;
    }
    return 0;
}