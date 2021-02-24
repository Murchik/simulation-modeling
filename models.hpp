#include <vector>

class TDynamicModel {
protected:
    std::vector<double> RightParts;

public:
    TDynamicModel();
    ~TDynamicModel();
    std::vector<double> GetRightParts();
    virtual void Funcs(float, std::vector<double>);
};

class TSpaceCraft : public TDynamicModel {
public:
    TSpaceCraft();
    ~TSpaceCraft();
    void Funcs(float, std::vector<double>) final;  // Реализовать
};
