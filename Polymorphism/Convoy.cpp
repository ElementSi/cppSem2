#include <iostream>

using namespace std;

class Car {
protected:
    bool allowesBoarding;
    bool allowesLoading;
    unsigned int numberOfSeats;
    unsigned int numberOfContainers;

public:
    Car(bool allowesBoarding, bool allowesLoading, unsigned int numberOfSeats, unsigned int numberOfContainers) {
        this->allowesBoarding = allowesBoarding;
        this->allowesLoading = allowesLoading;
        this->numberOfSeats = numberOfSeats;
        this->numberOfContainers = numberOfContainers;
    }

    ~Car() {}

    bool isBoardingAllowed() const {
        return allowesBoarding;
    }

    bool isLoadingAllowed() const {
        return allowesLoading;
    }

    unsigned int getNumberOfSeats() const {
        return numberOfSeats;
    }

    unsigned int getNumberOfContainers() const {
        return numberOfContainers;
    }
};

class ConvoyManager {
private:
    Car const **convoy = nullptr;
    int convoySize = 0;
public:
    ~ConvoyManager() {
        delete[] this->convoy;
    }

    // Зарегистрировать новую машину в колонне
    void registerCar(const Car &c) {
        if (convoy == nullptr) {
            convoy = new Car const *[1];
        } else {
            Car const **tempConvoy = new Car const *[convoySize + 1];

            for (int i = 0; i < convoySize; i++) {
                tempConvoy[i] = convoy[i];
                if (convoy[i] == &c)
                    std::cout << "!!!!!!!!!" << std::endl;
            }

            delete[] convoy;

            convoy = tempConvoy;
        }

        convoy[convoySize] = &c;

        convoySize++;
    }

    // Сообщить, сколько всего пассажиров может принять колонна
    unsigned int getTotalSeats() const {
        unsigned int SeatsNumber = 0;

        if (convoy != nullptr) {
            for (int i = 0; i < convoySize; i++) {
                if (convoy[i]->isBoardingAllowed())
                    SeatsNumber = SeatsNumber + convoy[i]->getNumberOfSeats();
            }
        }

        return SeatsNumber;
    }

    // Сообщить, сколько всего грузовых контейнеров может взять колонна
    unsigned int getTotalContainers() const {
        unsigned int ContainersNumber = 0;

        if (convoy != nullptr) {
            for (int i = 0; i < convoySize; i++) {
                if (convoy[i]->isLoadingAllowed())
                    ContainersNumber = ContainersNumber + convoy[i]->getNumberOfContainers();
            }
        }

        return ContainersNumber;
    }
};

int main() {
    ConvoyManager cm;

    Car c1(true, false, 12, 3);
    cm.registerCar(c1);
    Car c2(false, true, 1, 15);
    cm.registerCar(c2);
    Car c3(false, false, 2, 2);
    cm.registerCar(c3);
    Car c4(true, true, 2, 4);
    cm.registerCar(c4);
    Car c5(true, true, 1, 8);
    cm.registerCar(c5);

    cout << "Total available seats: " << cm.getTotalSeats() << endl;
    cout << "Total available containers: " << cm.getTotalContainers() << endl;
};