#include <iostream>

using namespace std;

class VectorN
{
private:
    unsigned int dim;
    int* coordinates;
public:
    // Конструктор вектора размерности n
    VectorN(unsigned int n): dim(n) {
        coordinates = new int[dim];
    }

    // Деструктор
    ~VectorN() {
        delete[] coordinates;
    }

    // Получение размерности вектора
    unsigned getSize() const {
        return dim;
    }

    // Получение значения i-ой координаты вектора,
    // i находится в диапазоне от 0 до n-1
    int getValue(unsigned int i) const {
        return coordinates[i];
    }

    // Задание значения i-ой координаты вектора равным value,
    // i находится в диапазоне от 0 до n-1
    void setValue(unsigned int i, int value) {
        coordinates[i] = value;
    }

    /*
     * Далее реализуйте перегруженные операторы
     */

    // Оператор == проверяет два вектора на равенство,
    // равны они, если строго равны всех их координаты
    bool operator== (const VectorN& v2) const {
        bool isequal = true;
        for (unsigned int i = 0; i < dim; i++) {
            isequal = isequal && coordinates[i] == v2.getValue(i);
        }
        return isequal;
    }

    // Оператор != проверяет два вектора на неравенство,
    // они не равны, если хотя бы одна координата отличается
    bool operator!= (const VectorN& v2) const {
        return !(*this == v2);
    }

    // Оператор + складывает два вектора покоординатно,
    // возвращает результат как новый экземпляр вектора
    VectorN operator+ (const VectorN& v2) const {
        VectorN v3(dim);
        for (unsigned int i = 0; i < dim; i++) {
            v3.setValue(i, coordinates[i] + v2.getValue(i));
        }
        return v3;
    }

    // Оператор * умножает вектор на скаляр типа int покоординатно,
    // возвращает результат как новый экземпляр вектора.
    // Умножение должно работать при любом порядке операндов.
    VectorN operator* (const int& a) const {
        VectorN v3(dim);
        for (unsigned int i = 0; i < dim; i++) {
            v3.setValue(i, coordinates[i] * a);
        }
        return v3;
    }
};

VectorN operator* (const int& a, const VectorN& v) {
    VectorN v3(v.getSize());
    for (unsigned int i = 0; i < v.getSize(); i++) {
        v3.setValue(i, a * v.getValue(i));
    }
    return v3;
}

int main() {
    VectorN a(4);
    a.setValue(0, 0);
    a.setValue(1, 1);
    a.setValue(2, 2);
    a.setValue(3, 3);

    VectorN b(4);
    b.setValue(0, 0);
    b.setValue(1, -1);
    b.setValue(2, -2);
    b.setValue(3, -3);

    cout << (a == b) << endl;
    cout << (a != b) << endl;

    VectorN c = a + b;
    VectorN d = 5 * c;

    for(unsigned int i = 0; i < a.getSize(); ++i)
        cout << d.getValue(i) << endl;
}