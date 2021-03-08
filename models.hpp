#include <vector>

const double G = 398603000000000.0;  // Гравитационная постоянная земли

class TDynamicModel {
protected:
    std::vector<double>* rightParts;

public:
    TDynamicModel();
    ~TDynamicModel();
    virtual std::vector<double> func(std::vector<double> values,
                                              double t) = 0;
};

class TSpaceCraft : public TDynamicModel {
public:
    TSpaceCraft();
    std::vector<double> func(std::vector<double> values,
                                      double t) final;
};

class TTestFunction : public TDynamicModel {
public:
    TTestFunction();
    std::vector<double> func(std::vector<double> values,
                                      double t) final;
};
