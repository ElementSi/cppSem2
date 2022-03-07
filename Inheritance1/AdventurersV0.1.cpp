#include <iostream>

using namespace std;

class Item {
public:
    Item(string title, int weight, int level, bool magical);
    
    int getWeight();

    int getLevel();

    int isMagical();
};

class Player {
protected:
    int strength;
    int level;

public:
    Player() {}

    virtual ~Player() {}

    void setStrength(int strength) {
        this->strength = strength;
    }

    void setLevel(int level) {
        this->level = level;
    }

    int getStrength() {
        return this->strength;
    }

    int getLevel() {
        return this->level;
    }

    virtual bool canUse(Item* item) = 0;
};

class Knight: public Player {
public:
    bool canUse(Item* item) {
        return(!(*item).isMagical() && (*item).getWeight() <= this->strength && (*item).getLevel() <= this->level);
    }
};

class Wizard: public Player {
public:
    bool canUse(Item* item) {
        return((*item).getWeight() <= this->strength && (*item).getLevel() <= this->level);
    }
};

int main() {
}