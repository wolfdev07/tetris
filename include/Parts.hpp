#include <iostream>
#include <vector>

using namespace std;

class Parts{
private:
    vector<vector<vector<bool>>> parts;

public:
    //Constructor
    Parts();

    vector<vector<bool>> ConsultPart(int ind);

    void RotatePart(int ind);

    void DerotatePart(int ind);

    
};
