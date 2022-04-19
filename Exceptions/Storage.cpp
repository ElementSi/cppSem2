#include <iostream>
#include <memory>

using namespace std;

class IncorrectIndexException: public runtime_error {
public:
    IncorrectIndexException() : runtime_error("Requested incorrect index") {}
};

class Storage {
private:
    unsigned int size;
    unique_ptr<int[]> data;
public:
    // Конструктор хранилища размерности n
    Storage(unsigned int n): size(n) {
        data = unique_ptr<int[]>(new int[size]);
    }

    // Получение размерности хранилища
    unsigned int getSize() const {
        return size;
    }

    // Получение значения i-го элемента из хранилища
    // Если индекс некорректен, нужно выбросить IncorrectIndexException
    int getValue(unsigned int i) const {
        if (i >= size)
            throw IncorrectIndexException();
        return data[i];
    }

    // Задание значения i-го элемента из хранилища равным value
    // Если индекс некорректен, нужно выбросить IncorrectIndexException
    void setValue(unsigned int i, int value) {
        if (i >= size)
            throw IncorrectIndexException();
        data[i] = value;
    }
};

int main() {
    unsigned int index;
    cin >> index;
    Storage s(42);
    try {
        s.setValue(index, 0);
        cout << s.getValue(index) << endl;
    } catch(const exception& error) {
        cout << error.what() << endl;
        return -1;
    }
    return 0;
}