#include <iostream>
#include <set>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;


int main() {
    set<int> set_1;
    set<int> set_2;
    vector<int> vector_1;
    int size_of_input;

    cin >> size_of_input;

    copy_n(
            istream_iterator<int>(cin),
            size_of_input,
            inserter(set_1, set_1.begin())
    );

    copy_n(
            istream_iterator<int>(cin),
            size_of_input,
            inserter(set_2, set_2.begin())
    );

    set_intersection(
            set_1.begin(),
            set_1.end(),
            set_2.begin(),
            set_2.end(),
            back_inserter(vector_1)
    );

    sort(
            vector_1.begin(),
            vector_1.end()
    );

    copy(
            vector_1.begin(),
            vector_1.end(),
            ostream_iterator<int>(cout, " ")
    );

    return 0;
}