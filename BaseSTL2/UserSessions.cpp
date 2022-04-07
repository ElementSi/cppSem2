#include <iostream>
#include <map>

using namespace std;

class SessionManager
{
private:
    map<string, bool> users;
public:
    // Вход пользователя.
    // Один пользователь может войти несколько раз подряд,
    // считать его при этом нужно один раз.
    void login(const string& username) {
        users[username] = true;
    }

    // Выход пользователя.
    // Пользователь может выйти несколько раз подряд,
    // падать при этом не нужно.
    void logout(const string& username) {
        users[username] = false;
    }

    // Сколько сейчас пользователей залогинено.
    int getNumberOfActiveUsers() const {
        int number_of_active_users = 0;
        for (const auto& user : users)
            number_of_active_users += user.second;
        return number_of_active_users;
    }
};

int main() {
    SessionManager m;
    m.login("alice");
    cout << m.getNumberOfActiveUsers() << endl;
    m.login("bob");
    cout << m.getNumberOfActiveUsers() << endl;
    m.login("alice");
    cout << m.getNumberOfActiveUsers() << endl;
    m.logout("whoever");
    cout << m.getNumberOfActiveUsers() << endl;
    m.logout("alice");
    cout << m.getNumberOfActiveUsers() << endl;
    m.logout("bob");
    cout << m.getNumberOfActiveUsers() << endl;
}