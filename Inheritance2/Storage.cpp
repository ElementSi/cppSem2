#include <iostream>

using namespace std;


class Storage {
private:
    unsigned int capacity;
    int* StorageUnit;
public:
    // Конструктор хранилища размерности n
    explicit Storage(unsigned int n) {
        this->capacity = n;
        this->StorageUnit = new int[this->capacity];
    }

    // Добавьте нужный деструктор
    virtual ~Storage() {
        delete[] StorageUnit;
    }

    // Получение размерности хранилища
    unsigned getSize() {
        return(this->capacity);
    }

    // Получение значения i-го элемента из хранилища,
    // i находится в диапазоне от 0 до n-1,
    // случаи некорректных i можно не обрабатывать.
    int getValue(unsigned int i) {
        return(this->StorageUnit[i]);
    }

    // Задание значения i-го элемента из хранилища равным value,
    // i находится в диапазоне от 0 до n-1,
    // случаи некорректных i можно не обрабатывать.
    void setValue(unsigned int i, int value) {
        this->StorageUnit[i] = value;
    }
};


// Класс TestStorage, наследуется от вашей реализации Storage
class TestStorage : public Storage {
protected:
    // Унаследованная реализация зачем-то хочет выделить ещё памяти. Имеет право.
    int* more_data;

public:
    // В конструкторе память выделяется,
    explicit TestStorage(unsigned int n) : Storage(n) {
        more_data = new int[n];
    }

    // ... а в деструкторе освобождается - всё честно.
    ~TestStorage() override {
        delete[] more_data;
    }
};


int main() {
    Storage *ts = new TestStorage(42);
    delete ts;
    return 0;
}