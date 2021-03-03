#include "integrators.hpp"

TAbstractIntegrator::TAbstractIntegrator() { this->model = nullptr; }
TAbstractIntegrator::~TAbstractIntegrator() { delete model; }
void TAbstractIntegrator::SetDynamicModel(TDynamicModel* model) {
    this->model = model;
};

std::vector<double> TEuler::OneStep(std::vector<double> values,
                           std::vector<double> rightParts, double h) {
    int i;
    int n = values.size();
    for (i = 0; i < n; ++i) {
        values[i] += h * rightParts[i];
    }
    return values;
}
