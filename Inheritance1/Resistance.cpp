#include <iostream>

using namespace std;

class Material {
public:
    virtual float getStress(float strain) = 0;
};

class ElasticMaterial: public Material {
private:
    float elasticModulus;

public:
    ElasticMaterial(float elasticModulus) {
        this->elasticModulus = elasticModulus;
    }

    float getStress(float strain) {
        return(elasticModulus * strain);
    }
};

class PlasticMaterial: public Material {
private:
    float elasticModulus;
    float strainLimit;

public:
    PlasticMaterial(float elasticModulus, float strainLimit) {
        this->elasticModulus = elasticModulus;
        this->strainLimit = strainLimit;
    }

    float getStress(float strain) {
        if (strain <= strainLimit) return (elasticModulus * strain);
        return (elasticModulus * strainLimit);
    }
};

int main() {
}