#include <iostream>
#include <vector>

using namespace std;

class Task
{
protected:
    int cpuNum;
    int size;

public:
    Task(int cpuNum, int size) {
        this->cpuNum = cpuNum;
        this->size = size;
    }

// На каком ядре процессора выполняется задача
    int getCPU() const {
        return cpuNum;
    }

// Оценка сложности задачи (в попугаях)
    int getSize() const {
        return size;
    }
};

class Analyzer
{
private:
    unsigned int numCores;
    int* loads;
public:
    Analyzer(unsigned int numCores): numCores(numCores) {
        loads = new int[numCores];
        for (unsigned int i = 0; i < numCores; i++) {
            loads[i] = 0;
        }
    }

    ~Analyzer() {
        delete[] loads;
    }

    void analyze(const vector<Task>& tasks) {
        for(unsigned int i = 0; i < tasks.size(); i++) {
            loads[tasks[i].getCPU()] += tasks[i].getSize();
        }
    }

    int getLoadForCPU(int cpuNum) {
        return loads[cpuNum];
    }
};

int main() {
    int numberOfCores = 4;
    vector<Task> data = { {0, 1}, {1, 10}, {0, 6}, {2, 12}, {3, 5} };
    Analyzer a(numberOfCores);
    a.analyze(data);
    for(int i = 0; i < numberOfCores; i++)
        cout << a.getLoadForCPU(i) << endl;
}