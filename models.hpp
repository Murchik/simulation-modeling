#include <vector>

const double GravConst = 398603000000000.0;

class TDynamicModel {
protected:
    std::vector<double>* derivatives;

public:
    TDynamicModel();
    ~TDynamicModel();

    std::vector<double>* GetDerivatives();
    virtual std::vector<double>* GetDerivatives(std::vector<double> values) = 0;
    virtual std::vector<double>* GetDerivatives(std::vector<double> values,
                                                double h) = 0;
};

class TSpaceCraft : public TDynamicModel {
public:
    TSpaceCraft();
    ~TSpaceCraft();

    std::vector<double>* GetDerivatives(std::vector<double> values) final;
    std::vector<double>* GetDerivatives(std::vector<double> values,
                                        double h) final;
};

// Для проверки правильности работы интеграторов используется функция sin(x),
// которую легко посчитать вручную
class TestFunction : public TDynamicModel {
public:
    TestFunction();
    ~TestFunction();

    std::vector<double>* GetDerivatives(std::vector<double> values) final;
    std::vector<double>* GetDerivatives(std::vector<double> values,
                                        double h) final;
};
