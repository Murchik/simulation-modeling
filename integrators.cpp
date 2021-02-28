#include "integrators.hpp"

TAbstractIntegrator::TAbstractIntegrator() {
    this->h = 0.001;
    this->model = nullptr;
}
TAbstractIntegrator::TAbstractIntegrator(double t0, double tk) {
    this->h = 0.001;
    this->model = nullptr;
    this->t0 = t0;
    this->tk = tk;
}
TAbstractIntegrator::~TAbstractIntegrator() { delete model; }
void TAbstractIntegrator::SetDynamicModel(TDynamicModel* model) {
    this->model = model;
};

void TAbstractIntegrator::SetInterval(double t0, double tk) {
    this->t0 = t0;
    this->tk = tk;
}
int TAbstractIntegrator::SetStep(double h) {
    if (h > 0.0) {
        this->h = h;
    }
    return -1;
}

TEuler::TEuler() {
    /// PLACEHOLDER
}
TEuler::TEuler(double t0, double tk) : TAbstractIntegrator(t0, tk) {}
TEuler::~TEuler() {
    /// PLACEHOLDER
}
std::vector<double>* TEuler::OneStep(std::vector<double>* values) {
    int n = (*values).size();
    std::vector<double>* derivatives;
    // Для каждого элемента в векторе
    for (int k = 0; k < n; ++k) {
        // Получить производную в данной точке
        derivatives = (*model).GetDerivatives(*values);
        // Посчитать значение функции в следующей точке
        (*values)[k] += (*derivatives)[k] * h;
    }
    return values;
}
std::vector<double>* TEuler::Integrate(std::vector<double>* values) {
    int n = (*values).size();
    std::vector<double>* sum = new std::vector<double>(n);
    std::vector<double>* derivatives;
    // На промежутке от t0 до tk с шагом h
    for (double ti = t0; ti < tk; ti += h) {
        // Для каждого элемента в векторе
        for (int k = 0; k < n; ++k) {
            // Получить производную в данной точке
            derivatives = (*model).GetDerivatives(*values);
            // Посчитать значение функции в следующей точке по Эйлеру
            (*values)[k] += (*derivatives)[k] * h;
            // Добавить слагаемое к инегральной сумме
            (*sum)[k] += (*values)[k] * h;
        }
    }
    return sum;
}
