#include "integrators.hpp"

TAbstractIntegrator::TAbstractIntegrator() { this->ti = 0.0; }
TAbstractIntegrator::TAbstractIntegrator(double t0, double tk, double h) {
    this->t0 = t0;
    this->tk = tk;
    this->h = h;
    this->ti = 0.0;
}
TAbstractIntegrator::~TAbstractIntegrator() {
    /// PLACEHOLDER
}
void TAbstractIntegrator::SetDynamicModel(TDynamicModel* model) {
    this->model = model;
};

TEuler::TEuler() {
    /// PLACEHOLDER
}
TEuler::TEuler(double t0, double tk, double h)
    : TAbstractIntegrator(t0, tk, h){};
TEuler::~TEuler() {
    /// PLACEHOLDER
}
std::vector<double>* TEuler::OneStep(std::vector<double>* values) {
    if (ti > tk) {
        return nullptr;
    }

    int n = (*values).size();
    std::vector<double>* derivatives = (*model).GetRightParts();
    for (int k = 0; k < n; ++k) {
        (*values)[k] += (*derivatives)[k] * h;
    }
    ti += h;
    return values;
}

TRungeKutta::TRungeKutta() {
    /// PLACEHOLDER
}
TRungeKutta::TRungeKutta(double t0, double tk, double h)
    : TAbstractIntegrator(t0, tk, h){};
TRungeKutta::~TRungeKutta() {
    /// PLACEHOLDER
}
std::vector<double>* TRungeKutta::OneStep(std::vector<double>* values) {
    if (ti > tk) {
        return nullptr;
    }
    /// PLACEHOLDER
}
