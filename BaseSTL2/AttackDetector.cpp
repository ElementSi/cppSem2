#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Connection {
protected:
    string source;
    unsigned short int port;
    unsigned long long timestamp;

public:
    Connection(string source, unsigned short int port, unsigned long long timestamp) {
        this->source = source;
        this->port = port;
        this->timestamp = timestamp;
    }
    ~Connection() {}

    string getSource() const {
        return source;
    }

    unsigned short int getPort() const {
        return port;
    }

    unsigned long long getTimestamp() const {
        return timestamp;
    }
};

class IntrusionDetector {
private:
    unsigned short int time_threshold;
    unsigned short int port_limit;
    map<string, vector<pair<unsigned long long, unsigned short int>>> connections;
public:
    // Задать временное окно для анализа
    void setTimeThreshold(unsigned short int time_threshold) {
        this->time_threshold = time_threshold;
    }

    // Задать минимальное количество портов для срабатывания
    void setPortLimit(unsigned short int port_limit) {
        this->port_limit = port_limit;
    }

    // Вызов этого метода уведомляет анализатор о новом подключении.
    void handleConnection(const Connection& c) {
        connections[c.getSource()].push_back(make_pair(c.getTimestamp(), c.getPort()));
    }

    // Проверить, является ли указанный адрес нарушителем
    bool isIntruder(const string& source) const {
        if (connections.find(source) != connections.end()) {
            auto source_story = connections.find(source)->second;
            sort(source_story.begin(), source_story.end());
            for (auto it1 = source_story.begin(); it1 != source_story.end(); ++it1) {
                set<unsigned short int> ports;
                for (auto it2 = it1; it2 != source_story.end() && it2->first - it1->first < time_threshold; ++it2) {
                    ports.insert(it2->second);
                    if (ports.size() >= port_limit)
                        return true;
                }
            }
        }

        return false;
    }
};

int main () {
    IntrusionDetector id;
    id.setTimeThreshold(5);
    id.setPortLimit(3);

    id.handleConnection({"load.com", 80, 100504});
    id.handleConnection({"load.com", 80, 100501});
    id.handleConnection({"load.com", 80, 100502});
    id.handleConnection({"load.com", 80, 100503});
    id.handleConnection({"load.com", 80, 100500});
    cout << boolalpha << "Checking if load.com is intruder: " << id.isIntruder("cum.com") << endl;
}
