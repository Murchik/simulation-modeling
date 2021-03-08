#include <cmath>
#include <iostream>

#include "integrators.hpp"

const double PI = 3.1415926535897932384626433832795028841971693993751058209749;

int main() {
    TAbstractIntegrator* integrator = new TRungeKutta;
    TDynamicModel* model = new TTestFunction;

    std::vector<double> values = {5.0};  // Задание начальных условий
    double tk = PI;   // Задание терминального момента времени
    double h = 0.01;  // Шаг интегрирования
    double t;         // Текущее время
    int i, j;

    t = 0;  // Задание начального момента времени
    for (i = 0; t < tk; t += h, ++i) {
        integrator->oneStep(*model, values, t, h);
        std::cout << std::endl << "t = \t" << t << std::endl;
        std::cout << "y(t): " << std::endl;
        for (j = 0; j < values.size(); j++) {
            std::cout << values[j] << std::endl;
        }
        std::cout << std::endl << std::endl;
    }
    std::cout << std::endl << "Steps: " << i << std::endl;
    return 0;
}
