#include "models.hpp"

class TAbstractIntegrator {
protected:
    double t0;
    double tk;
    double h;  // Шаг интегрирования
    TDynamicModel model;

public:
    TAbstractIntegrator();
    TAbstractIntegrator(double t0, double tk, double h);
    ~TAbstractIntegrator();

    virtual void SetRightParts(TDynamicModel);
    virtual void MoveTo(double);
    virtual std::vector<double> OneStep(std::vector<double>);
};

class TEuler : public TAbstractIntegrator {
public:
    TEuler();
    TEuler(double t0, double tk, double h);
    ~TEuler();

    std::vector<double> OneStep(std::vector<double> values) final;
};
