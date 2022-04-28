#include <iostream>

using namespace std;

class MoneyBox {
private:
    unsigned int sum = 0;
    unsigned int num_of_coins = 0;
public:
    // Добавить монетку достоинством value
    void addCoin(unsigned int value) {
        sum += value;
        num_of_coins++;
    }

    // Получить текущее количество монеток в копилке
    unsigned int getCoinsNumber() const {
        return num_of_coins;
    }

    // Получить текущее общее достоинство всех монеток
    unsigned int getCoinsValue() const {
        return sum;
    }
};

int main() {
    MoneyBox m;
    // Добавили монетку достоинством 10
    m.addCoin(10);
    // Добавили монетку достоинством 5
    m.addCoin(5);

    // Ожидаем, что монеток внутри 2 штуки
    cout << m.getCoinsNumber() << endl;
    // Ожидаем, что общее достоинство всех монеток 15
    cout << m.getCoinsValue() << endl;
}