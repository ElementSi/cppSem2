#include <iostream>

using namespace std;

class Animal {
public:
    virtual string getType() = 0;
    virtual bool isDangerous() = 0;
};

class ZooKeeper {
private:
    int DangerousCount = 0;

public:
    ZooKeeper();
    void handleAnimal(Animal* a);
    int getDangerousCount();
};

ZooKeeper::ZooKeeper() {
}

void ZooKeeper::handleAnimal(Animal* a) {
    if((*a).isDangerous()) DangerousCount++;
}

int ZooKeeper::getDangerousCount() {
    return DangerousCount;
}

int main() {
}