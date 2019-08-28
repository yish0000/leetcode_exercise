#include "TestCase.h"

using namespace std;

class SolutionPlaceBrick
{
public:
    int placeBrick(int n)
    {
        if (n < 3) return 0;
        vector<int> dp(n, 0);
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 1;
        for (int i=3; i<n; i++)
            dp[i] = dp[i-2] + dp[i-1];
        return dp[n-1];
    }
};

RUN_TESTCASE(PlaceBrick)
{
    SolutionPlaceBrick sln;
    TESTCASE_ASSERT(sln.placeBrick(3) == 1);
    TESTCASE_ASSERT(sln.placeBrick(4) == 1);
    TESTCASE_ASSERT(sln.placeBrick(5) == 2);
    TESTCASE_ASSERT(sln.placeBrick(6) == 3);
    TESTCASE_ASSERT(sln.placeBrick(7) == 4);
    TESTCASE_ASSERT(sln.placeBrick(8) == 5);
}