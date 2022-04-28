#include <iostream>
#include <set>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;


int main() {
    multiset<int> multiset_1;
    set<int> set_1;
    vector<int> vector_1;
    int size_of_input;

    cin >> size_of_input;

    copy_n(
            istream_iterator<int>(cin),
            size_of_input,
            inserter(multiset_1, multiset_1.begin())
    );

    copy_n(
            multiset_1.begin(),
            size_of_input,
            inserter(set_1, set_1.begin())
    );

    copy_n(
            set_1.begin(),
            set_1.size(),
            inserter(vector_1, vector_1.begin())
    );

    bool finished = false;

    while (!finished) {
        if (vector_1.empty())
            finished = true;

        auto max_elem = max_element(vector_1.begin(), vector_1.end());

        if (multiset_1.count(*max_elem) > 1) {
            vector_1.erase(max_elem);
            continue;
        }
        else {
            cout <<*max_elem;
            finished = true;
        }
    }

    return 0;
}