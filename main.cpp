#include <cmath>
#include <iostream>
#include <fstream>

#include "integrators.hpp"

const double PI = 3.1415926535897932384626433832795028841971693993751058209749;

int main() {
    TDynamicModel* model = new TSpaceCraft;
    TAbstractIntegrator* integrator = new TRungeKutta(*model);

    std::vector<double> values = {31200000.0, 31200000.0, 0.0,  -1700.0, 1200.0, -1900.0}; // Задание начальных условий
    double tk = 200000; // Задание терминального момента времени
    double h = 1; // Шаг интегрирования
    double t; // Текущее время
    int i, j;

    std::ofstream fout_t("t.txt");
    std::ofstream fout_x("x.txt");
    std::ofstream fout_y("y.txt");
    std::ofstream fout_z("z.txt");

    int n = values.size();
    t = 0;  // Задание начального момента времени
    for (i = 0; t < tk; t += h, ++i) {
        integrator->oneStep(*model, values, t, h);
        fout_t << std::fixed << t << '\n';
        fout_x << std::fixed << values[0] << '\n';
        fout_y << std::fixed << values[1] << '\n';
        fout_z << std::fixed << values[2] << '\n';
    }
    fout_x.close();
    fout_y.close();
    fout_z.close();

    return 0;
}
