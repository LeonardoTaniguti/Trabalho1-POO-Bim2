#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Neuronio {
public:
    virtual double predict(const vector<double>& entradas) const = 0;
    virtual ~Neuronio() = default;
};

class NeuronioReLU : public Neuronio {
private:
    vector<double> pesos;
    double bias;

public:
    NeuronioReLU(const vector<double>& pesos, double bias)
        : pesos(pesos), bias(bias) {}

    double predict(const vector<double>& entradas) const override {
        double soma = 0.0;
        for (size_t i = 0; i < entradas.size(); ++i) {
            soma += entradas[i] * pesos[i];
        }
        soma += bias;
        return max(0.0, soma);
    }
};

int main() {
    NeuronioReLU neuronio1({0.1, 0.3}, -0.8);
    vector<double> entradas1 = {0.5, 1.5};
    double saida1 = neuronio1.predict(entradas1);
    cout << "Teste 1 - Saída: " << saida1 << endl;

    NeuronioReLU neuronio2({0.4, 0.2}, -0.2);
    vector<double> entradas2 = {1.0, 2.0};
    double saida2 = neuronio2.predict(entradas2);
    cout << "Teste 2 - Saída: " << saida2 << endl;

    NeuronioReLU neuronio3({0.3, 0.5}, -1.0);
    vector<double> entradas3 = {2.0, 1.0};
    double saida3 = neuronio3.predict(entradas3);
    cout << "Teste 3 - Saída: " << saida3 << endl;

    return 0;
}