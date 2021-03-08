#include <cmath>
#include <iostream>

#include "integrators.hpp"

const double PI = 3.1415926535897932384626433832795028841971693993751058209749;

int main() {
    TAbstractIntegrator* integrator = new TRungeKutta;
    TDynamicModel* model = new TTestFunction;
    integrator->setDynamicModel(model);

    // std::vector<double> values = {42164000.0, 0.0, 0.0, 0.0, 3074.6, 0.0};
    std::vector<double> values = {5.0};
    double tk = PI;  // Конечное значение момента времени интегрирования
    double h = 0.0001;  // Шаг интегрирования
    int i, j;         // Номер шага
    double t;         // Текущее время

    for (t = 0, i = 0; t < tk; t += h, ++i) {
        values = integrator->oneStep(values, t, h);

        std::cout << std::endl << "t = \t" << t << std::endl;
        std::cout << "y(t) = \t";
        for (j = 0; j < values.size(); j++) {
            std::cout << values[j] << std::endl;
        }
        std::cout << "sin(t) = " << sin(t) + 5.0 << std::endl;
        std::cout << std::endl << std::endl;
    }
    std::cout << std::endl << "Steps: " << i << std::endl;

    // std::cout << std::endl << "t = " << tk << std::endl;
    // std::cout << "y(t) = ";
    // for (i = 0; i < values.size(); i++) {
    //     std::cout << values[i] << std::endl;
    // }
    // std::cout << std::endl;

    return 0;
}
