#include <cmath>
#include <vector>

const double GravConst = 398603000000000.0;

class TDynamicModel {
protected:
    std::vector<double>* RightParts;

public:
    TDynamicModel();
    ~TDynamicModel();

    std::vector<double>* GetRightParts();
    virtual void SetInitialValues(double x, double y, double z, double Vx,
                                  double Vy, double Vz) = 0;
    virtual void SetInitialValues(std::vector<double> initialValues) = 0;
};

class TSpaceCraft : public TDynamicModel {
public:
    TSpaceCraft();
    ~TSpaceCraft();

    void SetInitialValues(double x, double y, double z, double Vx, double Vy,
                          double Vz) final;
    void SetInitialValues(std::vector<double> const initialValues) final;
};
