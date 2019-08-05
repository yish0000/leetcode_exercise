#include "TestCase.h"

using namespace std;

class SolutionGenerateRandomPointInCircle
{
public:
    SolutionGenerateRandomPointInCircle(double radius, double x_center, double y_center) {
        x = x_center;
        y = y_center;
        r = radius;
    }
    
    vector<double> randPoint() {
        const double PI = 3.14159265;
        double angle = ((double)rand() / RAND_MAX) * PI * 2;
        double radius = sqrt((double)rand() / RAND_MAX) * r;
        vector<double> res = {cos(angle)*radius+x, sin(angle)*radius+y};
        return res;
    }
    
protected:
    double x;
    double y;
    double r;
};

RUN_TESTCASE(GenerateRandomInCircle)
{
    SolutionGenerateRandomPointInCircle sln(1, 0, 0);
    for (int i=0; i<10; i++)
    {
        vector<double> res = sln.randPoint();
        std::cout << res[0] << "," << res[1] << std::endl;
    }
}
