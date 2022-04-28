#include <iostream>
#include <string>
#include <vector>
#include <memory>


using namespace std;


class Brain {
protected:
    vector<double> data;
    string phrase;

public:
    Brain() {
        data.resize(1000000);
        phrase = "Booyahg Booyahg Booyahg";
    }

    string speak() {
        return phrase;
    }
};

class Goblin {
protected:
    shared_ptr<Brain> gob_brain;
public:
    // Подходящие конструкторы и деструкторы
    Goblin(shared_ptr<Brain> brain) {
        gob_brain = brain;
    }

    // Просто вернуть фразу, которую гоблину подсказывает мозг
    // (Метод используется для проверки, что голова гоблина содержит правильный мозг)
    string speak() {
        return gob_brain->speak();
    }
};

vector<Goblin> create_goblin_army(unsigned int size) {
    shared_ptr<Brain> army_brain = shared_ptr<Brain>(new Brain());
    vector<Goblin> goblin_army(size, Goblin(army_brain));
    return goblin_army;
};

int main()
{
    unsigned int size1 = 1;
    unsigned int size2 = 10;
    vector<Goblin> army1 = create_goblin_army(size1);
    vector<Goblin> army2 = create_goblin_army(size2);

    for(unsigned int i = 0; i < size1; i++) {
        cout << army1[i].speak() << endl;
    }
    for(unsigned int i = 0; i < size2; i++) {
        cout << army2[i].speak() << endl;
    }

    return 0;
}
