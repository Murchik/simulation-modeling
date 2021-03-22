#include "integrators.hpp"

void TEuler::oneStep(TDynamicModel& model, std::vector<double>& values,
                     double t, double h) {
    int i;
    int n = model.size();
    std::vector<double> rightParts = model.func(values, t);
    for (i = 0; i < n; ++i) {
        values[i] += h * rightParts[i];
    }
}

TRungeKutta::TRungeKutta(TDynamicModel& model) {
    _n = model.size();
    k1.reserve(_n);
    k2.reserve(_n);
    k3.reserve(_n);
    k4.reserve(_n);
    helpme.reserve(_n);
}

void TRungeKutta::oneStep(TDynamicModel& model, std::vector<double>& values,
                          const double t, const double h) {
    int i, j;
    for (i = 0; i < _n; ++i) {
        helpme = values;
        k1 = model.func(helpme, t);
        for (j = 0; j < _n; ++j) {
            helpme[j] = values[j] + h * k1[j] / 2.0;
        }
        k2 = model.func(helpme, t + h / 2.0);
        for (j = 0; j < _n; ++j) {
            helpme[j] = values[j] + h * k2[j] / 2.0;
        }
        k3 = model.func(helpme, t + h / 2.0);
        for (j = 0; j < _n; ++j) {
            helpme[j] = values[j] + h * k3[j] / 2.0;
        }
        k4 = model.func(helpme, t + h);
        values[i] +=
            h * (k1[i] / 6.0 + k2[i] / 3.0 + k3[i] / 3.0 + k4[i] / 6.0);
    }
}
