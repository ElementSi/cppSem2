#include <iostream>

using namespace std;

class GasHolder {
    private:
    const float R = 8.31;
    float T = 273;
    float V;
    float Nu = 0;
    
    public:
    explicit GasHolder(float V);
    ~GasHolder() = default;
    void inject(float m, float M);
    void heat(float dT);
    void cool(float dT);
    [[nodiscard]] float getPressure() const;
};

GasHolder::GasHolder(float V) {
    this->V = V;
}

void GasHolder::inject(float m, float M) {
    this->Nu = Nu + m / M;
}

void GasHolder::heat(float dT) {
    this->T = T + dT;
}

void GasHolder::cool(float dT) {
    if (T - dT > 0) this->T = T - dT;
    else this->T = 0;
}

float GasHolder::getPressure() const {
    return (Nu * R * T) / V;
}

int main() {
    GasHolder h(1.0);
    h.inject(29, 29);
    cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
    h.inject(29, 29);
    cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
    h.heat(273);
    cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
    h.cool(373);
    cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
    h.cool(373);
    cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
}