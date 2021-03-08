#include "models.hpp"

#include <cmath>

TDynamicModel::TDynamicModel() { _size = 0; }
int TDynamicModel::size() { return _size; }

TSpaceCraft::TSpaceCraft() { _size = 6; }
std::vector<double> TSpaceCraft::func(std::vector<double>& values, double t) {
    std::vector<double> rightParts(_size);
    _radius =
        sqrt(pow(values[0], 2.0) + pow(values[1], 2.0) + pow(values[2], 2.0));
    rightParts[0] = values[3];
    rightParts[1] = values[4];
    rightParts[2] = values[5];
    rightParts[3] = -G * values[0] / pow(_radius, 3.0);
    rightParts[4] = -G * values[1] / pow(_radius, 3.0);
    rightParts[5] = -G * values[2] / pow(_radius, 3.0);
    return rightParts;
}

TTestFunction::TTestFunction() { _size = 1; }
std::vector<double> TTestFunction::func(std::vector<double>& values, double t) {
    std::vector<double> rightParts(_size);
    rightParts[0] = cos(t);
    return rightParts;
}
