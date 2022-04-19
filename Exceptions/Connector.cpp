#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


class Connector {
private:
    string address;
public:
    // Конструктор. Получает параметром адрес, куда требуется подключиться.
    // Выполняет необходимую инициализацию соединения.
    // После завершения работы конструктора соединение установлено и готово к работе.
    // Если возникают какие-либо проблемы - выбрасывает exception с описанием проблемы.
    Connector(const string& address) {
        stringstream full_address(address);
        string segment;
        vector<string> seg_list;

        while(getline(full_address, segment, '.')) {
            seg_list.push_back(segment);
        }

        if (seg_list.begin() == seg_list.end())
            throw runtime_error("The address can not consist entirely of dots!");

        else if (seg_list.back() != "com")
            throw runtime_error("The address must have a .com domain!");

        this->address = address;
    }

    // Отправить по установленному соединению сообщение, текст сообщения передаётся в параметре data.
    // Если возникают какие-либо проблемы - выбрасывает exception с описанием проблемы.
    void sendRequest(const string& data) {
        if
    }
};