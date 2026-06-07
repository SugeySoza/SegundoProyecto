#include <iostream>

#include "Item.h"
#include "Player.h"

using namespace std;

int main () {

    auto i1 = new Item ("111", "test1", "0001", "Test", 1000, true );
    auto i2 = new Item ("222", "test2", "0001", "Test", 1000, true );
    auto i3 = new Item ("333", "test3", "0001", "Test", 1000, true );

    auto p1 = make_unique<Player>("PlayerTest", 100, 100, 30, "0001");
    p1 -> addItem(i1);
    p1 -> addItem(i2);
    p1 -> addItem(i3);

    cout << p1 -> toString() << endl;

    delete i1;
    delete i2;
    delete i3;

    return 1;
}