#include <iostream>

#include "integrators.hpp"

int main() {    
    std::vector<double>* inegr;
    // Инициализация интегратора и модели
    TAbstractIntegrator* integrator = new TEuler(0.0, 2.0);
    TDynamicModel* model = new TestFunction;
    // Задание модели и шага интегрирования
    integrator->SetDynamicModel(model);
    integrator->SetStep(0.001);
    // Задание начального значения аргумента
    std::vector<double> values = {0.0};
    // Печать аргументов до интегрирования
    std::cout << "Vector of values before:" << std::endl;
    for (int i = 0; i < values.size(); ++i) {
        std::cout << " " << values[i];
    }
    std::cout << std::endl;

    // Интегрирование
    inegr = integrator->Integrate(&values);

    // Печать аргументов после интегрирования
    std::cout << "Vector of values after:" << std::endl;
    for (int i = 0; i < values.size(); ++i) {
        std::cout << " " << values[i];
    }
    std::cout << std::endl;
    
    std::cout << "Integration results:" << std::endl;
    for (int i = 0; i < (*inegr).size(); ++i) {
        std::cout << " " << (*inegr)[i];
    }
    std::cout << std::endl;

    return 0;
}
