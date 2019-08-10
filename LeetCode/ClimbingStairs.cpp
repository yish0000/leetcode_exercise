#include "TestCase.h"

using namespace std;

class SolutionClimbingStairs
{
public:
    int climbStairs(int n) {
        if (n <= 0) return 0;
        vector<int> dp(n, 0);
        dp[0] = 1;
        if (n > 1)
        {
            dp[1] = 2;
            for (int i=2; i<n; i++)
                dp[i] = dp[i-2] + dp[i-1];
        }
        return dp[n-1];
    }
};

RUN_TESTCASE(ClimbingStairs)
{
    SolutionClimbingStairs sln;
    TESTCASE_ASSERT(sln.climbStairs(1) == 1);
    TESTCASE_ASSERT(sln.climbStairs(2) == 2);
    TESTCASE_ASSERT(sln.climbStairs(3) == 3);
    TESTCASE_ASSERT(sln.climbStairs(4) == 5);
    TESTCASE_ASSERT(sln.climbStairs(5) == 8);
}
