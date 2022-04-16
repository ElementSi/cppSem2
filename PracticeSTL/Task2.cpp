#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>

using namespace std;


int main() {
    multiset<int> multiset_1;
    multiset<int> multiset_2;
    int size_of_input;

    cin >> size_of_input;

    copy_n(
            istream_iterator<int>(cin),
            size_of_input,
            inserter(multiset_1, multiset_1.begin())
    );

    copy_n(
            istream_iterator<int>(cin),
            size_of_input,
            inserter(multiset_2, multiset_2.begin())
    );

    if (multiset_1 == multiset_2)
        cout << "true";

    else
        cout << "false";

    return 0;
}