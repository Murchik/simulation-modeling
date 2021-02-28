#include "models.hpp"

class TAbstractIntegrator {
protected:
    double t0;
    double tk;
    double h;
    TDynamicModel* model;

public:
    TAbstractIntegrator();
    TAbstractIntegrator(double t0, double tk);
    ~TAbstractIntegrator();

    // Устанавливает шаг интегрирования (длину частичного отрезка),
    // не может быть отрицательной
    int SetStep(double h);
    void SetInterval(double t0, double tk);
    void SetDynamicModel(TDynamicModel* model);

    virtual std::vector<double>* OneStep(std::vector<double>* values) = 0;
    virtual std::vector<double>* Integrate(std::vector<double>* values) = 0;
};

class TEuler : public TAbstractIntegrator {
private:
public:
    TEuler();
    TEuler(double t0, double tk);
    ~TEuler();

    std::vector<double>* OneStep(std::vector<double>* values) final;
    std::vector<double>* Integrate(std::vector<double>* values) final;
};
