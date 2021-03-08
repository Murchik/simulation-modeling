#include "integrators.hpp"

TAbstractIntegrator::TAbstractIntegrator() { this->model = nullptr; }
TAbstractIntegrator::~TAbstractIntegrator() { delete model; }
void TAbstractIntegrator::setDynamicModel(TDynamicModel* model) {
    this->model = model;
};

std::vector<double> TEuler::oneStep(std::vector<double> values, double t,
                                    double h) {
    int i;
    int n = values.size();
    std::vector<double> rightParts = model->func(values, t);
    for (i = 0; i < n; ++i) {
        values[i] += h * rightParts[i];
    }
    return values;
}

std::vector<double> TRungeKutta::oneStep(std::vector<double> values, double t,
                                         double h) {
    int i, j;
    int n = values.size();
    std::vector<double> k1(n);
    std::vector<double> k2(n);
    std::vector<double> k3(n);
    std::vector<double> k4(n);
    std::vector<double> helpme(n);

    for (i = 0; i < n; ++i) {
        helpme = values;
        k1 = model->func(helpme, t);

        for (j = 0; j < n; ++j) {
            helpme[j] = values[j] + h * k1[j] / 2.0;
        }
        k2 = model->func(helpme, t + h / 2.0);

        for (j = 0; j < n; ++j) {
            helpme[j] = values[j] + h * k2[j] / 2.0;
        }
        k3 = model->func(helpme, t + h / 2.0);

        for (j = 0; j < n; ++j) {
            helpme[j] = values[j] + h * k3[j] / 2.0;
        }
        k4 = model->func(helpme, t + h);

        values[i] += h * (k1[i] / 6.0 + k2[i] / 3.0 + k3[i] / 3.0 + k4[i] / 6.0);
    }
    return values;
}
