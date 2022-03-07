#include <iostream>

using namespace std;

class SpacePort {
    private:
    int* docks;
    unsigned int size = 0;
    
    public:
    explicit SpacePort(unsigned int size);
    ~SpacePort();
    bool requestLanding(unsigned int dockNumber);
    bool requestTakeoff(unsigned int dockNumber);
};

SpacePort::SpacePort(unsigned int size) {
    this->size = size;
    docks = new int[size];
    for (unsigned int i = 0; i < size; i++) docks[i] = 0;
}

SpacePort::~SpacePort() {
    delete[] docks;
}

bool SpacePort::requestLanding(unsigned int dockNumber) {
    bool display = false;
    if (dockNumber >= size || docks[dockNumber] == 1) return display;
    else display = true;

    docks[dockNumber] = 1;

    return display;
}

bool SpacePort::requestTakeoff(unsigned int dockNumber) {
    bool display = false;
    if (dockNumber >= size || docks[dockNumber] == 0) return display;
    else display = true;

    docks[dockNumber] = 0;

    return display;
}

int main() {
    SpacePort s(5);
    cout << boolalpha << s.requestLanding(0) << endl;
    cout << boolalpha << s.requestLanding(4) << endl;
    cout << boolalpha << s.requestLanding(5) << endl;

    cout << boolalpha << s.requestTakeoff(0) << endl;
    cout << boolalpha << s.requestTakeoff(4) << endl;
    cout << boolalpha << s.requestTakeoff(5) << endl;
}