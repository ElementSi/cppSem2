#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

class SignalsInfo {
private:
    unsigned int events_count;
    long min_value;
    long max_value;
public:
    SignalsInfo() {
        events_count = 0;
    }

    void handleSignal(long value) {
        if (events_count == 0) {
            min_value = value;
            max_value = value;
        }

        else {
            if (value < min_value)
                min_value = value;
            else if (value > max_value)
                max_value = value;
        }

        events_count++;
    }

    unsigned int getEventsCount() const {
        return events_count;
    }

    long getMinValue() const {
        return min_value;
    }

    long getMaxValue() const {
        return max_value;
    }
};

class TelemetryController {
private:
    map<string, SignalsInfo> devices;
public:
    // Получить и обработать событие. Параметрами передаются:
    // - device - идентификатор устройства, с которого пришло значение;
    // - value - собственно значение некоторой величины, переданное устройством.
    void handleEvent(const string& device, long value) {
        devices[device].handleSignal(value);
    }

    // По идентификатору устройства возвращает,
    // сколько всего значений от него пришло за всё время
    unsigned int getEventsCount(const string& device) const {
        return devices.find(device)->second.getEventsCount();
    }

    // По идентификатору устройства возвращает
    // минимальное значение за всё время, пришедшее от данного устройства
    long getMinValue(const string& device) const {
        return devices.find(device)->second.getMinValue();
    }

    // По идентификатору устройства возвращает
    // максимальное значение за всё время, пришедшее от данного устройства
    long getMaxValue(const string& device) const {
        return devices.find(device)->second.getMaxValue();
    }
};

int main() {
    TelemetryController tc;

    tc.handleEvent("d1", 42);
    tc.handleEvent("d1", -42);
    tc.handleEvent("d2", 100);

    cout << "Events count for d1: " << tc.getEventsCount("d1") << endl;
    cout << "Min value for d1: " << tc.getMinValue("d1") << endl;
    cout << "Max value for d1: " << tc.getMaxValue("d1") << endl;
}
