#include "TestCase.h"

using namespace std;

class SolutionMinimumPathSum
{
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        
        int XCount = (int)grid.size();
        int YCount = (int)grid[0].size();
        vector<vector<int>> dp(XCount, vector<int>(YCount, 0));
        for (int i=0; i<XCount; i++)
        {
            for (int j=0; j<YCount; j++)
            {
                if (i == 0)
                    dp[i][j] = (j > 0) ? dp[i][j-1] + grid[i][j] : grid[i][j];
                else if (j == 0)
                    dp[i][j] = (i > 0) ? dp[i-1][j] + grid[i][j] : grid[i][j];
                else
                    dp[i][j] = std::min(dp[i][j-1]+grid[i][j], dp[i-1][j]+grid[i][j]);
            }
        }
        
        return dp[XCount-1][YCount-1];
    }
};

RUN_TESTCASE(MinimumPathSum)
{
    SolutionMinimumPathSum sln;
    
    vector<vector<int>> arr = {
        {1,3,1},
        {1,5,1},
        {4,2,1},
    };
    TESTCASE_ASSERT(sln.minPathSum(arr) == 7);
}
