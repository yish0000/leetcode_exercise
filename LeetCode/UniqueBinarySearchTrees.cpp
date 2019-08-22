#include "TestCase.h"

using namespace std;

class SolutionUniqueBinarySearchTrees
{
public:
    int numTreesRecurse(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        int count = 0;
        for (int i=1; i<=n; i++)
        {
            if (i-1 == 0)
                count += numTreesRecurse(n-i);
            else if (n-i == 0)
                count += numTreesRecurse(i-1);
            else
                count += numTreesRecurse(i-1)*numTreesRecurse(n-i);
        }
        return count;
    }
    
    int numTrees(int n) {
        if (n <= 0) return 0;
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i=2; i<=n; i++)
        {
            int count = 0;
            for (int j=1; j<=i; j++)
            {
                if (j-1 == 0)
                    count += dp[i-j-1];
                else if (i-j == 0)
                    count += dp[j-2];
                else
                    count += dp[j-2] * dp[i-j-1];
            }
            dp[i-1] = count;
        }
        return dp[n-1];
    }
};

RUN_TESTCASE(UniqueBinarySearchTrees)
{
    SolutionUniqueBinarySearchTrees sln;
    TESTCASE_ASSERT(sln.numTrees(2) == 2);
    TESTCASE_ASSERT(sln.numTrees(3) == 5);
}
