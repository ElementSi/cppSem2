#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class Tracker
{
private:
    map<string, set<unsigned long long>> users;
public:
    // При любом действии пользователя вызывается этот метод.
    // Методу передаётся:
    // - какой пользователь совершил действие (username);
    // - когда (timestamp - для простоты условные секунды от начала времён).
    // Внимание: не гарантируется, что timestamp расположены строго по
    // возрастанию, в них может быть любой бардак.
    void click(const string& username, unsigned long long timestamp) {
        users[username].insert(timestamp);
    }

    // По имени пользователя нужно вернуть, сколько всего было кликов
    unsigned long long getClickCount(const string& username) const {
        return users.find(username)->second.size();
    }

    // Когда был первый клик
    unsigned long long getFirstClick(const string& username) const {
        return  *min_element(users.find(username)->second.begin(), users.find(username)->second.end());
    }

    // Когда был последний клик
    unsigned long long getLastClick(const string& username) const {
        return  *max_element(users.find(username)->second.begin(), users.find(username)->second.end());
    }
};

int main() {
    Tracker t;
    t.click("alice", 1000);
    t.click("bob", 1100);
    t.click("alice", 1001);
    t.click("alice", 1200);
    t.click("alice", 1002);
    cout << t.getClickCount("alice") << endl;
    cout << t.getClickCount("bob") << endl;
    cout << t.getFirstClick("alice") << endl;
    cout << t.getFirstClick("bob") << endl;
    cout << t.getLastClick("alice") << endl;
    cout << t.getLastClick("bob") << endl;
}