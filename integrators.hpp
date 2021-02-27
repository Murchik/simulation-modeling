#include "models.hpp"

class TAbstractIntegrator {
protected:
    double h;
    TDynamicModel* model;

public:
    TAbstractIntegrator();
    ~TAbstractIntegrator();

    void SetStep(double h);
    void SetDynamicModel(TDynamicModel* model);
    virtual std::vector<double>* OneStep(std::vector<double>* values) = 0;
    virtual std::vector<double>* Integrate(std::vector<double>* values) = 0;
};

class TEuler : public TAbstractIntegrator {
private:
    double t0, tk;

public:
    TEuler();
    TEuler(double t0, double tk);
    ~TEuler();

    std::vector<double>* OneStep(std::vector<double>* values) final;
    std::vector<double>* Integrate(std::vector<double>* values) final;
};
