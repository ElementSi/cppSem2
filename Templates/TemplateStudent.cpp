#include <iostream>

using namespace std;

struct student {
    string name;
    string id_number_string;
};

bool operator== (const student& stud1, const student& stud2){
    return stud1.id_number_string == stud2.id_number_string;
}

template<typename T>
bool check_them(T& x, T& y, T& z) {
    if (x == y)
        return true;
    else
        return false;
}

int main()
{
    student a = {"Andy", "1234 123123"};
    student b = {"Andrew", "1234 123123"};
    student c = {"Andy", "1234123123"};
    cout << boolalpha << "Check result is: " << check_them(a, b, c) << endl;
    return 0;
}