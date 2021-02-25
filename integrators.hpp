#include "models.hpp"

class TAbstractIntegrator {
protected:
    double t0;
    double tk;
    double h;  // Шаг интегрирования
    double ti;
    TDynamicModel* model;

public:
    TAbstractIntegrator();
    TAbstractIntegrator(double t0, double tk, double h);
    ~TAbstractIntegrator();

    void SetDynamicModel(TDynamicModel* model);
    virtual std::vector<double>* OneStep(std::vector<double>* values) = 0;
};

class TEuler : public TAbstractIntegrator {
public:
    TEuler();
    TEuler(double t0, double tk, double h);
    ~TEuler();

    std::vector<double>* OneStep(std::vector<double>* values) final;
};
