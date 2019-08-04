#include "TestCase.h"

using namespace std;

class SolutionMaxIncreaseKeepSkyline
{
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        vector<int> row_max(grid.size(), 0);
        vector<int> col_max(grid[0].size(), 0);
        for (int i=0; i<grid.size(); i++)
        {
            for (int j=0; j<grid.size(); j++)
            {
                row_max[i] = std::max(grid[i][j], row_max[i]);
                col_max[j] = std::max(grid[i][j], col_max[j]);
            }
        }
        int count = 0;
        for (int i=0; i<grid.size(); i++)
        {
            for (int j=0; j<grid.size(); j++)
            {
                count += std::min(row_max[i], col_max[j]) - grid[i][j];
            }
        }
        return count;
    }
};

RUN_TESTCASE(MaxIncreaseKeepingSkyline)
{
    SolutionMaxIncreaseKeepSkyline sln;
    
    vector<vector<int>> arr1 = {
        {3, 0, 8, 4},
        {2, 4, 5, 7},
        {9, 2, 6, 3},
        {0, 3, 1, 0},
    };
    TESTCASE_ASSERT(sln.maxIncreaseKeepingSkyline(arr1) == 35);
}
