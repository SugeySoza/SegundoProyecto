
using namespace std;
#ifndef SEGUNDOPROYECTO_ITEM_H
#define SEGUNDOPROYECTO_ITEM_H


class Player;

class Item {
private:
    string id;
    string name;
    string roomId;
    string type;
    int value;
    bool collected;

public:
    Item(string id,string name,string roomId,string type,int value,bool collected);
    void applyEffect (Player& player);
    void collect();
    bool isCollected();
    string getRoomId();
    string tostring();


};


#endif //SEGUNDOPROYECTO_ITEM_H