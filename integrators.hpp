#include "models.hpp"

class TAbstractIntegrator {
protected:
    TDynamicModel* model;

public:
    TAbstractIntegrator();
    ~TAbstractIntegrator();

    void setDynamicModel(TDynamicModel* model);

    virtual std::vector<double> oneStep(std::vector<double> values, double t,
                                double h) = 0;
};

class TEuler : public TAbstractIntegrator {
public:
    std::vector<double> oneStep(std::vector<double> values, double t,
                                double h) final;
};

class TRungeKutta : public TAbstractIntegrator {
public:
    std::vector<double> oneStep(std::vector<double> values, double t,
                                double h) final;
};
