#include <iostream>

#include "integrators.hpp"

int main() {
    TAbstractIntegrator* integrator = new TEuler;
    TDynamicModel* model = new TSpaceCraft;
    integrator->SetDynamicModel(model);

    std::vector<double> values = {42164000.0, 0.0, 0.0, 0.0, 3074.6, 0.0};
    double tk = 30.0;  // Конечное значение момента времени интегрирования
    double h = 0.001;  // Шаг интегрирования
    int i;             // Номер шага
    double t;          // Текущее время

    t = 0;  // Задание начального момента времени интегрирования
    for (i = 0; t < tk; ++i) {
        values = integrator->OneStep(values, model->getRightParts(values, t), h);
        t += h;
    }

    for (i = 0; i < values.size(); i++) {
        std::cout << values[i] << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
