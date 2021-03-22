#include "models.hpp"

class TAbstractIntegrator {
public:
    virtual void oneStep(TDynamicModel& model, std::vector<double>& values,
                         double t, double h) = 0;
};

class TEuler : public TAbstractIntegrator {
public:
    void oneStep(TDynamicModel& model, std::vector<double>& values, double t,
                 double h) final;
};

class TRungeKutta : public TAbstractIntegrator {
public:
    void oneStep(TDynamicModel& model, std::vector<double>& values, double t,
                 double h) final;
};
