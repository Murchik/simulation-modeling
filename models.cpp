#include "models.hpp"

#include <cmath>

TDynamicModel::TDynamicModel() { derivatives = nullptr; }
TDynamicModel::~TDynamicModel() { delete derivatives; }
std::vector<double>* TDynamicModel::GetDerivatives() { return derivatives; }

TSpaceCraft::TSpaceCraft() { derivatives = new std::vector<double>(6); }
TSpaceCraft::~TSpaceCraft() {
    /// PLACEHOLDER
}

std::vector<double>* TSpaceCraft::GetDerivatives(std::vector<double> values) {
    double radius = sqrt(values[0] * values[0] + values[1] * values[1] +
                         values[2] * values[2]);
    (*derivatives)[0] = values[3];
    (*derivatives)[1] = values[4];
    (*derivatives)[2] = values[5];
    (*derivatives)[3] = -(GravConst * values[0]) / pow((radius), 3);
    (*derivatives)[4] = -(GravConst * values[1]) / pow((radius), 3);
    (*derivatives)[5] = -(GravConst * values[2]) / pow((radius), 3);

    return derivatives;
}
std::vector<double>* TSpaceCraft::GetDerivatives(std::vector<double> values,
                                                 double h) {
    values[0] += h;
    values[1] += h;
    values[2] += h;
    double radius = sqrt(values[0] * values[0] + values[1] * values[1] +
                         values[2] * values[2]);
    (*derivatives)[0] = values[3];
    (*derivatives)[1] = values[4];
    (*derivatives)[2] = values[5];
    (*derivatives)[3] = -(GravConst * values[0]) / pow((radius), 3);
    (*derivatives)[4] = -(GravConst * values[1]) / pow((radius), 3);
    (*derivatives)[5] = -(GravConst * values[2]) / pow((radius), 3);

    return derivatives;
}

TestFunction::TestFunction() { derivatives = new std::vector<double>(1); }
TestFunction::~TestFunction() {
    /// PLACEHOLDER
}

// Производная sin(x) это cos(x)
std::vector<double>* TestFunction::GetDerivatives(std::vector<double> values) {
    (*derivatives)[0] = cos(values[0]);
    return derivatives;
}
std::vector<double>* TestFunction::GetDerivatives(std::vector<double> values,
                                                  double h) {
    (*derivatives)[0] = cos(values[0] + h);
    return derivatives;
}