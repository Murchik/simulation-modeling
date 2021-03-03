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

TEuler::TEuler() {}
TEuler::TEuler(double t0, double tk) : TAbstractIntegrator(t0, tk) {}
TEuler::~TEuler() {}
std::vector<double>* TEuler::OneStep(std::vector<double>* values) {
    int n = values->size();
    std::vector<double>* derivatives;
    // Для каждого элемента в векторе
    for (int k = 0; k < n; ++k) {
        // Получить производную в данной точке
        derivatives = model->GetDerivatives(*values);
        // Посчитать значение функции в следующей точке
        (*values)[k] += (*derivatives)[k] * h;
    }
    return values;
}
std::vector<double>* TEuler::Integrate(std::vector<double>* values) {
    int n = values->size();
    std::vector<double>* sum = new std::vector<double>(n);
    std::vector<double>* derivatives;
    // На промежутке от t0 до tk с шагом h
    for (double ti = t0; ti < tk; ti += h) {
        // Для каждого элемента в векторе
        for (int k = 0; k < n; ++k) {
            // Получить производную в данной точке
            derivatives = model->GetDerivatives(*values);
            // Посчитать значение функции в следующей точке по методу Эйлера
            (*values)[k] += (*derivatives)[k] * h;
            // Добавить слагаемое к инегральной сумме
            (*sum)[k] += (*values)[k] * h;
        }
    }
    return sum;
}

TRungeKutta::TRungeKutta() {}
TRungeKutta::TRungeKutta(double t0, double tk) : TAbstractIntegrator(t0, tk) {}
TRungeKutta::~TRungeKutta() {}
std::vector<double>* TRungeKutta::OneStep(std::vector<double>* values) {
    int k;
    int n = values->size();
    std::vector<double>* tmp_values = new std::vector<double>(n);
    for (k = 0; k < n; ++k) {
        (*tmp_values)[k] = (*values)[k];
    }

    std::vector<double>* k1 = new std::vector<double>(n);
    std::vector<double>* k2 = new std::vector<double>(n);
    std::vector<double>* k3 = new std::vector<double>(n);
    std::vector<double>* k4 = new std::vector<double>(n);

    k1 = model->GetDerivatives(*tmp_values);

    for (k = 0; k < n; ++k) {
        (*tmp_values)[k] = (*values)[k] + h / 2.0 * (*k1)[k];
    }
    k2 = model->GetDerivatives(*tmp_values, h / 2.0);

    for (k = 0; k < n; ++k) {
        (*tmp_values)[k] = (*values)[k] + h / 2.0 * (*k2)[k];
    }
    k3 = model->GetDerivatives(*tmp_values, h / 2.0);

    for (k = 0; k < n; ++k) {
        (*tmp_values)[k] = (*values)[k] + h * (*k3)[k];
    }
    k4 = model->GetDerivatives(*tmp_values, h);

    for (k = 0; k < n; ++k) {
        (*values)[k] += (1.0 / 8.0) *
                        ((*k1)[k] + 3.0 * (*k2)[k] + 3.0 * (*k3)[k] + (*k4)[k]);
    }

    delete k1, k2, k3, k4;
    return values;
}
std::vector<double>* TRungeKutta::Integrate(std::vector<double>* values) {
    int n = values->size();
    std::vector<double>* sum = new std::vector<double>(n);
    // На промежутке от t0 до tk с шагом h
    for (double ti = t0; ti < tk; ti += h) {
        // Для каждого элемента в векторе
        for (int k = 0; k < n; ++k) {
            // Посчитать значение функции в следующей точке по методу Рунге -
            // Кутты
            values = OneStep(values);
            // Добавить слагаемое к инегральной сумме
            (*sum)[k] += (*values)[k] * h;
        }
    }
    return sum;
}
