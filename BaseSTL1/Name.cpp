#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Person
{
private:
    string surname;
    string name;
    string middleName;
public:
    Person(string surname, string name, string middleName): surname(surname), name(name), middleName(middleName) {}

    Person()=default;

    void setSurname(const string& surname) {
        this->surname = surname;
    }

    void setName(const string& name) {
        this->name = name;
    }

    void setMiddleName(const string& middleName) {
        this->middleName = middleName;
    }

    string getSurname() const {
        return surname;
    }

    string getName() const {
        return name;
    }

    string getMiddleName() const {
        return middleName;
    }
};

istream& operator >>(istream& is, Person& human) {
    string surname, name, middleName;
    cin >> surname >> name >> middleName;
    human.setSurname(surname);
    human.setName(name);
    human.setMiddleName(middleName);
    return is;
}

ostream& operator <<(ostream& os, const Person& human) {
    cout << human.getSurname() << " " << human.getName() << " " << human.getMiddleName();
    return os;
}

bool operator <(Person& human1, Person& human2) {
    if (human1.getSurname()[0] == human2.getSurname()[0]){
        if (human1.getName()[0] == human2.getName()[0]){
            return human1.getMiddleName()[0] < human2.getMiddleName()[0];
            }
        return human1.getName()[0] < human2.getName()[0];
    }
    return human1.getSurname()[0] < human2.getSurname()[0];
}

int main() {
    cout << "Testing I/O" << endl;
    Person p;
    cin >> p;
    cout << p << endl;

    cout << "Testing sorting" << endl;
    vector<Person> people;
    people.push_back(Person("Ivanov", "Ivan", "Ivanovich"));
    people.push_back(Person("Petrov", "Petr", "Petrovich"));
    people.push_back(Person("Ivanov", "Ivan", "Petrovich"));
    people.push_back(Person("Ivanov", "Petr", "Ivanovich"));

    sort(people.begin(), people.end());
    for(vector<Person>::const_iterator it = people.begin(); it < people.end(); it++) {
        cout << *it << endl;
    }
}