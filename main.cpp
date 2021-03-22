#include <cmath>
#include <iostream>

#include "integrators.hpp"

const double PI = 3.1415926535897932384626433832795028841971693993751058209749;

int main() {
    TAbstractIntegrator* integrator = new TRungeKutta;
    TDynamicModel* model = new TSpaceCraft;

    std::vector<double> values = {31200000.0, 31200000.0, 0.0,  -1700.0, 1200.0, -1900.0};  // Задание начальных условий
    double tk = 200000;   // Задание терминального момента времени
    double h = 1;  // Шаг интегрирования
    double t;         // Текущее время
    int i, j, n;

    n = values.size();
    t = 0;  // Задание начального момента времени
    for (i = 0; t < tk; t += h, ++i) {
        integrator->oneStep(*model, values, t, h);
        std::cout << std::endl << "t = " << t << std::endl;
        std::cout << "y(t): " << std::endl;
        for (j = 0; j < n; ++j) {
            std::cout << "\t" << values[j] << std::endl;
        }
        std::cout << std::endl << std::endl;
    }
    std::cout << std::endl << "Steps: " << i << std::endl;
    return 0;
}
