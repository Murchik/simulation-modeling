#include <vector>

const double G = 398603000000000.0;  // Гравитационная постоянная земли

class TDynamicModel {
protected:
    std::vector<double>* rightParts;

public:
    TDynamicModel();
    virtual std::vector<double> getRightParts(std::vector<double> values, double t) = 0;
};

class TSpaceCraft : public TDynamicModel {
public:
    TSpaceCraft();
    std::vector<double> getRightParts(std::vector<double> values, double t) final;
};
