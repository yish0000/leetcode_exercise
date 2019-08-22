#include "TestCase.h"

using namespace std;

class SolutionTriangle
{
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) return 0;
        for (int i=(int)triangle.size()-1; i>=1; i--)
        {
            for (int j=0; j<(int)triangle[i].size()-1; j++)
            {
                triangle[i-1][j] += std::min(triangle[i][j], triangle[i][j+1]);
            }
        }
        return triangle[0][0];
    }
};

RUN_TESTCASE(Triangle)
{
    SolutionTriangle sln;
    
    vector<vector<int>> arr = {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3},
    };
    TESTCASE_ASSERT(sln.minimumTotal(arr) == 11);
}
