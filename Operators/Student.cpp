#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
    string name;
    unsigned int score;
public:
    // Задать имя студента
    void setName(const string& name) {
        this->name = name;
    }

    // Указать количество баллов за контрольную
    void setScore(unsigned int score) {
        this->score = score;
    }

    // Получить имя студента
    string getName() const {
        return name;
    }

    // Получить количество баллов студента
    unsigned int getScore() const {
        return score;
    }
};

istream& operator >>(istream& is, Student& stud) {
    string name;
    getline(is, name);
    stud.setName(name);
    stud.setScore(0);
    return is;
}

ostream& operator <<(ostream& os, Student& stud) {
    cout << "'" << stud.getName() << "'" << ": " <<stud.getScore();
    return os;
}

int main() {
    Student s;
    cin >> s;
    s.setScore(10);
    cout << s << endl;
}