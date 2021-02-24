#include <iostream>

#include "integrators.hpp"

int main() {
    TDynamicModel* model = new TSpaceCraft();
    TAbstractIntegrator* integrator = new TEuler(1.0, 1.0, 1.0);
    return 0;
}
