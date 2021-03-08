#include <cmath>
#include <iostream>

#include "integrators.hpp"

const double PI = 3.1415926535897932384626433832795028841971693993751058209749;

int main() {
    TAbstractIntegrator* integrator = new TEuler;
    TDynamicModel* model = new TTestFunction;
    integrator->SetDynamicModel(model);

    // std::vector<double> values = {42164000.0, 0.0, 0.0, 0.0, 3074.6, 0.0};
    std::vector<double> values = {5.0};
    double tk = 2 * PI;  // Конечное значение момента времени интегрирования
    double h = PI / 5;  // Шаг интегрирования
    int i;              // Номер шага
    double t;           // Текущее время

    std::cout << "Estimated result:" << std::endl
              << sin(tk) << std::endl
              << std::endl;

    t = 0;  // Задание начального момента времени интегрирования
    for (i = 0; t < tk; ++i) {
        values =
            integrator->OneStep(values, model->getRightParts(values, t), h);
        t += h;

        std::cout << std::endl << "t = \t" << t << std::endl;
        std::cout << "y(t) = \t";
        for (i = 0; i < values.size(); i++) {
            std::cout << values[i] << std::endl;
        }
        std::cout << std::endl << std::endl;
    }

    // std::cout << std::endl << "t = " << tk << std::endl;
    // std::cout << "y(t) = ";
    // for (i = 0; i < values.size(); i++) {
    //     std::cout << values[i] << std::endl;
    // }
    // std::cout << std::endl;

    return 0;
}
