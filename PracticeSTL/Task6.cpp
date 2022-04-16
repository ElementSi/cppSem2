#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>

using namespace std;


struct indexedValue {
    int index;
    int value;
};


int main() {
    // Много векторов, хоть повесься. Оперативка, наверное, умрёт
    vector<int> vector_input;
    vector<indexedValue> vector_numbered;
    vector<indexedValue> vector_renumbered;
    vector<int> vector_output;

    vector<indexedValue> vector_even_numbered;
    vector<int> vector_even_index;
    vector<indexedValue> vector_even_renumbered;

    vector<indexedValue> vector_odd_numbered;
    vector<int> vector_odd_index;
    vector<indexedValue> vector_odd_renumbered;

    int size_of_input;

    cin >> size_of_input;

    // Читаем первые size_of_input чисел с клавиатуры
    copy_n(
            istream_iterator<int>(cin),
            size_of_input,
            back_inserter(vector_input)
    );

    vector<int> vector_sequence(size_of_input);

    // Заполняем vector_sequence индексами от 0 до size_of_input - 1
    iota(
            vector_sequence.begin(),
            vector_sequence.end(),
            0
    );


    // Преобразуем вектор введённых значений (int) в вектор из тех же значений, но с индексами (indexedValue)
    transform(
            vector_input.begin(),
            vector_input.end(),
            vector_sequence.begin(),
            back_inserter(vector_numbered),
            [](const int &a, const int &b) {
                indexedValue iv{b, a};
                return iv;
            }
    );

    // Копируем элементы с чётными value из vector_numbered в vector_even_numbered
    copy_if(
            vector_numbered.begin(),
            vector_numbered.end(),
            back_inserter(vector_even_numbered),
            [](const indexedValue x) {
                return x.value % 2 == 0;
            }
    );

    // Копируем элементы с нечётными value из vector_numbered в vector_odd_numbered
    copy_if(
            vector_numbered.begin(),
            vector_numbered.end(),
            back_inserter(vector_odd_numbered),
            [](const indexedValue x) {
                return x.value % 2 != 0;
            }
    );

    // Записываем в отдельный вектор vector_even_index индексы чётных элементов
    transform(
            vector_even_numbered.begin(),
            vector_even_numbered.end(),
            back_inserter(vector_even_index),
            [](const indexedValue &x) {
                return x.index;
            }
    );

    // Записываем в отдельный вектор vector_odd_index индексы нечётных элементов
    transform(
            vector_odd_numbered.begin(),
            vector_odd_numbered.end(),
            back_inserter(vector_odd_index),
            [](const indexedValue &x) {
                return x.index;
            }
    );

    // Сортируем чётные элементы в vector_even_numbered по убыванию
    sort(
            vector_even_numbered.begin(),
            vector_even_numbered.end(),
            [](const indexedValue a, const indexedValue b) {
                return a.value > b.value;
            }
    );

    // Сортируем нечётные элементы в vector_odd_numbered по возрастанию
    sort(
            vector_odd_numbered.begin(),
            vector_odd_numbered.end(),
            [](const indexedValue a, const indexedValue b) {
                return a.value < b.value;
            }
    );

    // Переиндексируем чётные элементы в vector_even_numbered, опираясь на начальное положение чётных элементов
    transform(
            vector_even_numbered.begin(),
            vector_even_numbered.end(),
            vector_even_index.begin(),
            back_inserter(vector_even_renumbered),
            [](const indexedValue &a, const int b) {
                indexedValue iv{b, a.value};
                return iv;
            }
    );

    // Переиндексируем нечётные элементы в vector_odd_numbered, опираясь на начальное положение нечётных элементов
    transform(
            vector_odd_numbered.begin(),
            vector_odd_numbered.end(),
            vector_odd_index.begin(),
            back_inserter(vector_odd_renumbered),
            [](const indexedValue &a, const int b) {
                indexedValue iv{b, a.value};
                return iv;
            }
    );

    // Сложим векторы vector_even_renumbered и vector_odd_renumbered
    vector_renumbered = vector_even_renumbered;
    vector_renumbered.insert(
            vector_renumbered.end(),
            vector_odd_renumbered.begin(),
            vector_odd_renumbered.end()
    );

    // Отсортируем элементы в vector_renumbered по возрастанию индекса
    sort(
            vector_renumbered.begin(),
            vector_renumbered.end(),
            [](const indexedValue a, const indexedValue b) {
                return a.index < b.index;
            }
    );

    // Преобразуем вектор проиндексированных значений (indexedValue) в вектор из тех же значений, но без индексов (int)
    transform(
            vector_renumbered.begin(),
            vector_renumbered.end(),
            back_inserter(vector_output),
            [](const indexedValue &x) {
                return x.value;
            }
    );

    // Выведем значения из vector_renumbered в поток вывода
    copy(
            vector_output.begin(),
            vector_output.end(),
            ostream_iterator<int>(cout, " ")
    );

    return 0;
}