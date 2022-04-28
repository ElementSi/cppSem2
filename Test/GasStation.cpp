#include <iostream>

using namespace std;


class GasStation {
private:
    unsigned int _capacity;
    unsigned int _amount_of_fuel = 0;
public:
    // Конструктор, принимающий один параметр - ёмкость резервуара колонки
    // Резервуар создаётся пустой
    GasStation(unsigned int capacity): _capacity(capacity) {
    }

    // Залить в резервуар колонки n литров топлива
    // Если столько не влезает в резервуар - не заливать ничего, выбросить std::exception
    void fill(unsigned int n) {
        if (_amount_of_fuel + n > _capacity)
            throw exception();
        else _amount_of_fuel += n;
    }

    // Заправиться, забрав при этом из резервура n литров топлива
    // Если столько нет в резервуаре - не забирать из резервуара ничего, выбросить std::exception
    void tank(unsigned int n) {
        if (int(_amount_of_fuel) - int(n) < 0)
            throw exception();
        else _amount_of_fuel -= n;
    }

    // Запросить остаток топлива в резервуаре
    unsigned int get_limit() const {
        return _amount_of_fuel;
    }
};

int main() {
    GasStation s = GasStation(1000);            // Колонка на 1000, пока пустая
    s.fill(300);                                // Это влезет в резервуар,
    cout << s.get_limit() << endl;              // ... так что здесь увидим на экране 300.

    s.tank(100);                                // Забрали из резервуара 100,
    s.fill(300);                                // ... после чего долили ещё 300,
    cout << s.get_limit() << endl;              // ... так что на экране ожидаем 500.

    for(unsigned int i = 0; i < 5; i++)         // В цикле забрали 5 раз по 50,
        s.tank(50);
    cout << s.get_limit() << endl;              // ... так что на экране ожидаем 250.

    s.fill(1000);                               // А вот тут ожидаем exception.
    // (После проверки exception-а строку стоит просто убрать.)

    for(unsigned int i = 0; i < 50; i++) {      // Теперь пытаемся забрать 50 раз по 100,
        s.tank(100);                            // из-за чего на третьей попытке ждём exception.
        cout << s.get_limit() << endl;
    }
}