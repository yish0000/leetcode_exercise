#include "TestCase.h"

using namespace std;

class SolutionSearch2DMatrix
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int l = 0, r = (int)matrix.size() * (int)matrix[0].size();
        while(l < r)
        {
            int mid = l + (r - l) / 2;
            int y = mid / (int)matrix[0].size();
            int x = mid % (int)matrix[0].size();
            if (matrix[y][x] == target)
                return true;
            else if (matrix[y][x] < target)
                l = mid + 1;
            else
                r = mid;
        }
        return false;
    }
};

RUN_TESTCASE(Search2DMatrix)
{
    SolutionSearch2DMatrix sln;
    
    vector<vector<int>> m1 = {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,50}
    };
    TESTCASE_ASSERT(sln.searchMatrix(m1, 3));
    
    vector<vector<int>> m2 = {{1}};
    TESTCASE_ASSERT(!sln.searchMatrix(m2, 2));
}
