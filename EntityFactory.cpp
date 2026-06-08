//
// Created by gabriel on 8/6/26.
//

#include "EntityFactory.h"


vector<string> EntityFactory::split(const string &str, char delimiter) {
    vector<string> tokens;
    stringstream s(str);
    string token;

    while (getline(s,token,delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

Room *EntityFactory::createRoom(string line) {
    auto data = split(line,',');
    if (data.size() < 3) {
        cout << "INVALID FORMAT" << endl;
        return nullptr;
    }

    string id = data[0];
    string name = data[1];
    string descripcion = data[2];

    auto room = new Room(
        id,
        name,
        descripcion
        );
    return room;
}

Item *EntityFactory::createItem(string line) {
    auto data = split(line,',');

    if (data.size() < 5) {
        cout << "INVALID FORMAT" << endl;
        return nullptr;
    }

    return new Item (
        data[0],
        data[1],
        data[2],
        data[3],
        stoi(data[4])
        );
}

Event *EntityFactory::createEvent(string line) {
    auto data = split(line,',');

    if (data.size() < 5) {
        cout << "INVALID FORMAT" << endl;
        return nullptr;
    }

    return new Event(
        data[0],
        data[1],
        data[2],
        data[3],
        stoi(data[4])

    );
}

Player *EntityFactory::createPlayer(string line) {
    auto data = split(line,',');

    if (data.size() < 5) {
        cout << "INVALID FORMAT" << endl;
        return nullptr;
    }

    return new Player(
        data[0],
        stoi(data[1]),
        stoi(data[2]),
        stoi(data[3]),
        data[4]

    );
}

Enemy *EntityFactory::createEnemy(string line) {
    auto data = split(line,',');

    if (data.size() < 5) {
        cout << "INVALID FORMAT" << endl;
        return nullptr;
    }

    return new Enemy(
        data[0],
        data[1],
        data[2],
        stoi(data[3]),
        stoi(data[4])

    );
}
