#include <iostream>
#include <map>

using namespace std;

class Animal {
public:
    virtual string getType() const = 0;
    virtual ~Animal() {}
};

class Monkey: public Animal {
public:
    string getType() const {
        return "monkey";
    }
    ~Monkey() = default;
};

class Lion: public Animal {
public:
    string getType() const {
        return "lion";
    }
    ~Lion() = default;
};

class Cat: public Animal {
public:
    string getType() const {
        return "cat";
    }
    ~Cat() = default;
};

class ZooKeeper {
private:
    map<string, int> animals;
public:
    // Создаём смотрителя зоопарка
    ZooKeeper() = default;

    // Смотрителя попросили обработать очередного зверя.
    void handleAnimal(const Animal& a) {
        animals[a.getType()]++;
    }

    // Возвращает, сколько зверей такого типа было обработано.
    // Если таких не было, возвращает 0.
    int getAnimalCount(const string& type) const {
        if (animals.find(type) != animals.end())
            return animals.find(type)->second;
        return 0;
    }
};

int main() {
    ZooKeeper z;
    Animal *a = new Monkey();
    z.handleAnimal(*a);
    delete a;
    a = new Monkey();
    z.handleAnimal(*a);
    delete a;
    a = new Lion();
    z.handleAnimal(*a);
    delete a;
    cout << z.getAnimalCount("monkey") << endl;
    cout << z.getAnimalCount("lion") << endl;
    cout << z.getAnimalCount("cat") << endl;
}