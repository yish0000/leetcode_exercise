#include "TestCase.h"

using namespace std;

class SolutionSpiralMatrix
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return vector<int>();
        vector<int> res;
        int x = 0, y = 0;
        int n = (int)matrix.size() * (int)matrix[0].size();
        int w = (int)matrix[0].size();
        int h = (int)matrix.size();
        int offset = 0;
        for (int i=0; i<n; i++)
        {
            res.push_back(matrix[y][x]);
            
            if (y == offset && x < w - offset - 1)
                x++;
            else if (x == w - offset - 1 && y < h - offset - 1)
                y++;
            else if (y == h - offset - 1 && x > offset)
                x--;
            else if (x == offset && y > offset + 1)
            {
                y--;
                if (y == offset + 1)
                    offset++;
            }
        }
        return res;
    }
};

RUN_TESTCASE(SpiralMatrix)
{
    SolutionSpiralMatrix sln;
    
    vector<vector<int>> m1 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12}
    };
    vector<int> arr1 = {1,2,3,4,8,12,11,10,9,5,6,7};
    TESTCASE_ASSERT(sln.spiralOrder(m1) == arr1);
    
    vector<vector<int>> m2 = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };
    vector<int> arr2 = {1,2,3,6,9,8,7,4,5};
    TESTCASE_ASSERT(sln.spiralOrder(m2) == arr2);
}
