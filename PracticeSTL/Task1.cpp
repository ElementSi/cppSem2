#include <iostream>
#include <deque>
#include <iterator>
#include <algorithm>

using namespace std;


int main() {
    deque<int> deque_1;
    int size_of_input;

    cin >> size_of_input;

    copy_n(
            istream_iterator<int>(cin),
            size_of_input,
            front_inserter(deque_1)
    );

    copy(
            deque_1.begin(),
            deque_1.end(),
            ostream_iterator<int>(cout, " ")
    );

    return 0;
}