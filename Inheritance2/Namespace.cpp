#include <iostream>

using namespace std;


namespace namespaceA {
    class Engine {
    public:
        static void run() {
            cout << "EngineA run" << endl;
        }
    };
}


namespace namespaceB {
    class Engine {
    public:
        static void run() {
            cout << "EngineB run" << endl;
        }
    };
}


namespace namespaceC {
    class Engine {
    public:
        static void run() {
            cout << "EngineC run" << endl;
        }
    };
}


class MyEngine {
public:
    static void run(unsigned int number) {
        // Если передан параметр 1 - должен быть вызван метод run и Engine-а из библиотеки A.
        if (number == 1) {
            namespaceA::Engine e;
            namespaceA::Engine::run();
        }

        // Если передан параметр 2 - должен быть вызван метод run и Engine-а из библиотеки B.
        else if (number == 2) {
            namespaceB::Engine e;
            namespaceB::Engine::run();
        }

        // Если передан параметр 3 - должен быть вызван метод run и Engine-а из библиотеки C.
        else if (number == 3) {
            namespaceC::Engine e;
            namespaceC::Engine::run();
        }

        // Если передано что-то иное - должно ничего не произойти.
    }
};


int main() {
    MyEngine::run(1); // вызов run из Engine-а из библиотеки A
    MyEngine::run(2); // вызов run из Engine-а из библиотеки B
    MyEngine::run(3); // вызов run из Engine-а из библиотеки C
    MyEngine::run(10); // ничего не происходит
    return(0);
}