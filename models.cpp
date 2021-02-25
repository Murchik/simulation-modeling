#include "models.hpp"

TDynamicModel::TDynamicModel() { RightParts = nullptr; }
TDynamicModel::~TDynamicModel() {
    /// PLACEHOLDER
}
std::vector<double>* TDynamicModel::GetRightParts() { return RightParts; }

TSpaceCraft::TSpaceCraft() { RightParts = new std::vector<double>(6); }
TSpaceCraft::~TSpaceCraft() {
    /// PLACEHOLDER
}
void TSpaceCraft::SetInitialValues(double x, double y, double z, double Vx,
                                   double Vy, double Vz) {
    double radius = sqrt(pow(x, 2.0) + pow(y, 2.0) + pow(z, 2.0));
    (*RightParts)[0] = Vx;
    (*RightParts)[1] = Vy;
    (*RightParts)[2] = Vz;
    (*RightParts)[3] = -(GravConst * x) / pow((radius), 3);
    (*RightParts)[4] = -(GravConst * y) / pow((radius), 3);
    (*RightParts)[5] = -(GravConst * z) / pow((radius), 3);
}
void TSpaceCraft::SetInitialValues(std::vector<double> const initialValues) {
    if (initialValues.size() != (*RightParts).size()) {
        return;
    }
    double a = initialValues[0] * initialValues[0] +
                         initialValues[1] * initialValues[1] +
                         initialValues[2] * initialValues[2];
    double radius = sqrt(a);
    (*RightParts)[0] = initialValues[3];
    (*RightParts)[1] = initialValues[4];
    (*RightParts)[2] = initialValues[5];
    (*RightParts)[3] = -(GravConst * initialValues[0]) / pow((radius), 3);
    (*RightParts)[4] = -(GravConst * initialValues[1]) / pow((radius), 3);
    (*RightParts)[5] = -(GravConst * initialValues[2]) / pow((radius), 3);
}
