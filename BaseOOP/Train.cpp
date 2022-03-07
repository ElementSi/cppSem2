#include <iostream>

using namespace std;

class Train {
    private:
    double m;
    double V;
    double x;
    
    public:
    explicit Train(double m);
    void move(double dt);
    void accelerate(double dp);
    [[nodiscard]] double getX() const;
};

Train::Train(double m) {
    this->m = m;
    this->x = 0;
    this->V = 0;
}

void Train::move(double dt) {
    this->x = this->x + this->V * dt;
}

void Train::accelerate(double dp) {
    this->V = this->V + dp / this->m;
}

double Train::getX() const {
    return this->x;
}

int main() {
    Train t(10);
    t.accelerate(1); // Скорость стала 0.1
    t.move(1);
    cout << "Current X: " << t.getX() << endl;
    t.move(1);
    cout << "Current X: " << t.getX() << endl;
    t.accelerate(-2); // Скорость стала -0.1
    t.move(3);
    cout << "Current X: " << t.getX() << endl;
}