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
private:
    std::vector<double> k1;
    std::vector<double> k2;
    std::vector<double> k3;
    std::vector<double> k4;
    std::vector<double> helpme;

public:
    void oneStep(TDynamicModel& model, std::vector<double>& values, double t,
                 double h) final;
};
