#include "integrators.hpp"

TAbstractIntegrator::TAbstractIntegrator() {
    /// PLACEHOLDER
}
TAbstractIntegrator::TAbstractIntegrator(double t0, double tk, double h) {
    this->t0 = t0;
    this->tk = tk;
    this->h = h;
}
TAbstractIntegrator::~TAbstractIntegrator() {
    /// PLACEHOLDER
}
void TAbstractIntegrator::SetRightParts(TDynamicModel) {
    /// PLACEHOLDER
}
void TAbstractIntegrator::MoveTo(double) {
    /// PLACEHOLDER
}
std::vector<double> TAbstractIntegrator::OneStep(std::vector<double>) {
    /// PLACEHOLDER
}

TEuler::TEuler() {
    /// PLACEHOLDER
}
TEuler::TEuler(double t0, double tk, double h)
    : TAbstractIntegrator(t0, tk, h){};
TEuler::~TEuler() {
    /// PLACEHOLDER
}
std::vector<double> TEuler::OneStep(std::vector<double> values) {
    int n = values.size();
    std::vector<double> NewValues(n);
    std::vector<double> direviteves = model.GetRightParts();
    for (int k = 0; k < n; ++k) {
        NewValues[k] = values[k] + h * direviteves[k];
    }
    return NewValues;
}
