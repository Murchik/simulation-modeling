#include "models.hpp"

class TAbstractIntegrator {
protected:
    TDynamicModel* model;

public:
    TAbstractIntegrator();
    ~TAbstractIntegrator();

    void SetDynamicModel(TDynamicModel* model);

    virtual std::vector<double> OneStep(std::vector<double> values,
                                        std::vector<double> rightParts,
                                        double h) = 0;
};

class TEuler : public TAbstractIntegrator {
public:
    std::vector<double> OneStep(std::vector<double> values,
                                std::vector<double> rightParts, double h) final;
};
