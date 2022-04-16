#include <iostream>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>

using namespace std;


int main() {
    vector<int> vector_1;
    multiset<int> multiset_1;
    multiset<int> multiset_2;
    multiset<int> multiset_3;
    int size_of_input;

    cin >> size_of_input;

    copy_n(
            istream_iterator<int>(cin),
            size_of_input,
            back_inserter(vector_1)
    );

    copy(
            vector_1.begin(),
            vector_1.end(),
            inserter(multiset_1, multiset_1.begin())
    );

    copy_n(
            istream_iterator<int>(cin),
            size_of_input,
            inserter(multiset_2, multiset_2.begin())
    );

    set_intersection(
            multiset_1.begin(),
            multiset_1.end(),
            multiset_2.begin(),
            multiset_2.end(),
            inserter(multiset_3, multiset_3.begin())
    );

    copy_if(
            vector_1.begin(),
            vector_1.end(),
            ostream_iterator<int>(cout, " "),
            [&multiset_3](int x) {
                auto it = multiset_3.find(x);

                if (it == multiset_3.end())
                    return false;

                multiset_3.erase(it);
                return true;
            }
    );

    return 0;
}