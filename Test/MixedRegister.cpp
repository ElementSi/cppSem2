#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>

using namespace std;


// Трансформация в нижний регистр
string lowercase_conversion(string s1) {
    for (unsigned int i = 0; i < s1.size(); i++) {
        if (s1[i] >= 'A' && s1[i] <= 'Z') {
            s1[i] += 32;
        }
    }

    return s1;
}


int main() {
    vector<string> vector_1;
    map<string, unsigned int> map_1;
    map<string, set<string>> map_2;
    vector<pair<unsigned int, string>> vector_2;
    unsigned int size_of_input;

    cin >> size_of_input;

    copy_n(
            istream_iterator<string>(cin),
            size_of_input,
            inserter(vector_1, vector_1.begin())
    );

    for (const auto &word: vector_1) {
        map_1[lowercase_conversion(word)]++;
    }

    for (const auto &word1: map_1) {
        if (word1.second > 1) {
            for (const auto &word2: vector_1) {
                if (lowercase_conversion(word2) == word1.first)
                    map_2[word1.first].insert(word2);
            }
        }
    }

    for (const auto &word: map_2) {
        vector_2.push_back(make_pair(word.second.size(), word.first));
    }

    sort(
            vector_2.begin(),
            vector_2.end(),
            [](const pair<unsigned int, string>& word1, const pair<unsigned int, string>& word2) {
                if (word1.first != word2.first)
                    return word1.first > word2.first;

                return word1.second[0] < word2.second[0];
            }
    );

    for (const auto &word: vector_2) {
        if (word.first > 2)
            cout << word.second << endl;
    }
}