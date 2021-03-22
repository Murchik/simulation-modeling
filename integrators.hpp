#include "models.hpp"

class TAbstractIntegrator {
public:
    virtual void oneStep(TDynamicModel& model, std::vector<double>& values,
                         const double t, const double h) = 0;
};

class TEuler : public TAbstractIntegrator {
public:
    void oneStep(TDynamicModel& model, std::vector<double>& values,
                 const double t, const double h) final;
};

class TRungeKutta : public TAbstractIntegrator {
private:
    std::vector<double> k1;
    std::vector<double> k2;
    std::vector<double> k3;
    std::vector<double> k4;
    std::vector<double> helpme;
    int _n;

public:
    TRungeKutta(TDynamicModel& model);
    void oneStep(TDynamicModel& model, std::vector<double>& values,
                 const double t, const double h) final;
};
