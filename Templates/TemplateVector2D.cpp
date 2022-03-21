#include <iostream>

using namespace std;

template<typename T>
class Vector2D
{
private:
    T x;
    T y;
public:
    // Конструкторы
    Vector2D() = default;
    Vector2D(T x, T y): x(x), y(y) {};

    // Деструктор
    ~Vector2D() = default;

    // Получение координат
    T getX() const {
        return x;
    }

    T getY() const {
        return y;
    }

    // Задание координат
    void setX(T x) {
        this->x = x;
    }

    void setY(T y){
        this->y = y;
    }

    // Перегруженный оператор - сравнение двух векторов на равенство
    bool operator== (const Vector2D& v2) const {
        return x == v2.getX() && y == v2.getY();
    }

    // Ещё один перегруженный оператор - неравенство векторов
    // Да, это отдельный оператор! Хинт - настоящие джедаи смогут для != использовать уже написанное ==
    bool operator!= (const Vector2D& v2) const {
        return !(*this == v2);
    }

    // Сумма двух векторов, исходные вектора не меняются, возвращается новый вектор
    Vector2D operator+ (const Vector2D& v2) const {
        Vector2D v3(x + v2.getX(), y + v2.getY());
        return v3;
    }

    // Вычитание векторов, исходные вектора не меняются, возвращается новый вектор
    Vector2D operator- (const Vector2D& v2) const {
        Vector2D v3(x - v2.getX(), y - v2.getY());
        return v3;
    }

    // Оператор умножения вектора на скаляр, исходный вектор не меняется, возвращается новый вектор
    Vector2D operator* (const T a) const {
        Vector2D v3(x * a, y * a);
        return v3;
    }
};

// Оператор умножения скаляра на вектор, исходный вектор не меняется, возвращается новый вектор
// Неожиданно, правда? Умножение скаляра на вектор - это отдельный оператор, причём описанный *вне* класса.
template<typename T>
Vector2D<T> operator* (int a, const Vector2D<T>& v) {
    Vector2D<T> v3(a * v.getX(), a * v.getY());
    return v3;
}

// Вывод вектора, ожидается строго в формате (1; 1)
template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector2D<T>& v) {
    os <<"(" <<v.getX() <<"; " <<v.getY() <<")";
    return os;
}

// Чтение вектора, читает просто две координаты без хитростей
template<typename T>
std::istream& operator>>(std::istream &is, Vector2D<T>& v) {
    T x, y;
    is >> x >> y;
    v.setX(x);
    v.setY(y);
    return is;
}

int main() {
    Vector2D<int> v1;
    cin >> v1;
    cout << "Read vector: " << v1 << endl;
    cout << "Vector multiplied by 42: " << v1 * 42 << endl;

    Vector2D<double> v2;
    cin >> v2;
    cout << "Read vector: " << v2 << endl;
    cout << "Vector multiplied by 42: " << 42 * v2 << endl;
}
