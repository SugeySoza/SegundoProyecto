
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
    Item(string id,string name,string roomId,string type,int value);
    void applyEffect (Player& player);
    void collect();
    bool isCollected() const;
    string getId() const;
    string getName() const;
    string getRoomId() const;
    string getType() const;
    int getValue() const;
    string toString() const;


};


#endif //SEGUNDOPROYECTO_ITEM_H