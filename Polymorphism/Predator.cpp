#include <iostream>

using namespace std;

class Animal {
protected:
    double mass;
    double speed;

public:
    Animal() {}

    virtual ~Animal() {}

    Animal(double mass, double speed) {
        this->mass = mass;
        this->speed = speed;
    }

    virtual double getMass() const {
        return mass;
    }

    virtual double getSpeed() const {
        return speed;
    }

    virtual bool canAtack() const {
        return false;
    }

    virtual void eat(const Animal &a) {
    }
};

class Predator : public Animal {
public:
    Predator(double mass, double speed) : Animal(mass, speed) {}

    virtual bool canAtack() const {
        return true;
    }

    virtual void eat(const Animal &a) {
        if (a.getMass() <= this->mass && a.getSpeed() <= this->speed) this->mass = this->mass + a.getMass();
    }
};

int main() {
    Animal *predator = new Predator(1, 10);
    cout << "Current mass: " << predator->getMass() << endl;

    if (predator->canAtack()) {
        predator->eat(Animal(2, 1)); // Этого не съедим - слишком большой
        cout << "Current mass: " << predator->getMass() << endl;
        predator->eat(Animal(1, 1)); // А вот этого вполне
        cout << "Current mass: " << predator->getMass() << endl;
        predator->eat(Animal(1, 20)); // Этого не выйдет - слишком быстрый
        cout << "Current mass: " << predator->getMass() << endl;
        predator->eat(Animal(2, 2)); // А вот этого догоним
        cout << "Current mass: " << predator->getMass() << endl;
    }

    delete predator;
}