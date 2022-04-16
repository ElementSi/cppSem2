#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;


int main() {
    vector<int> vector_1;
    int size_of_input;
    int max_value;

    cin >> size_of_input;

    copy_n(
            istream_iterator<int>(cin),
            size_of_input,
            back_inserter(vector_1)
    );

    cin >> max_value;

    copy_if(
            vector_1.begin(),
            vector_1.end(),
            ostream_iterator<int>(cout, " "),
            [max_value](const int x) {
                return x <= max_value;
            }
    );

    return 0;
}