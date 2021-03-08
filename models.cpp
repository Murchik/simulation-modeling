#include "models.hpp"

#include <cmath>

TDynamicModel::TDynamicModel() { rightParts = nullptr; }
TDynamicModel::~TDynamicModel() { delete rightParts; }

TSpaceCraft::TSpaceCraft() { rightParts = new std::vector<double>(6); }
std::vector<double> TSpaceCraft::getRightParts(std::vector<double> values,
                                               double t) {
    double radius =
        sqrt(pow(values[0], 2.0) + pow(values[1], 2.0) + pow(values[2], 2.0));

    (*rightParts)[0] = values[3];
    (*rightParts)[1] = values[4];
    (*rightParts)[2] = values[5];
    (*rightParts)[3] = -G * values[0] / pow(radius, 3.0);
    (*rightParts)[4] = -G * values[1] / pow(radius, 3.0);
    (*rightParts)[5] = -G * values[2] / pow(radius, 3.0);
    // (*rightParts)[0] = values[3] + (*rightParts)[3] * t;
    // (*rightParts)[1] = values[4] + (*rightParts)[4] * t;
    // (*rightParts)[2] = values[5] + (*rightParts)[5] * t;

    return *rightParts;
}

TTestFunction::TTestFunction() { rightParts = new std::vector<double>(1); }
std::vector<double> TTestFunction::getRightParts(std::vector<double> values,
                                                 double t) {
    (*rightParts)[0] = cos(t);
    return *rightParts;
}
