#include <iostream>

#include "integrators.hpp"

int main() {
    TAbstractIntegrator* integrator = new TEuler(0.0, 10.0, 0.2);
    TDynamicModel* model = new TSpaceCraft;
    std::vector<double>* rightParts = model->GetRightParts();

    std::cout << "Right parts before initialization:" << std::endl;
    for (int i = 0; i < (*rightParts).size(); ++i) {
        std::cout << " " << (*rightParts)[i];
    }
    std::cout << std::endl;

    integrator->SetDynamicModel(model);
    std::vector<double> values = {1.0, 1.0, 1.0, 2.0, 2.0, 0.0};
    model->SetInitialValues(values);

    std::cout << "Right parts after initialization:" << std::endl;
    for (int i = 0; i < (*rightParts).size(); ++i) {
        std::cout << " " << (*rightParts)[i];
    }
    std::cout << std::endl;

    std::cout << "Vector of values before one step:" << std::endl;
    for (int i = 0; i < values.size(); ++i) {
        std::cout << " " << values[i];
    }
    std::cout << std::endl;

    integrator->OneStep(&values);

    std::cout << "Vector of values after one step:" << std::endl;
    for (int i = 0; i < values.size(); ++i) {
        std::cout << " " << values[i];
    }
    std::cout << std::endl;

    return 0;
}
