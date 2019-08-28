#include "TestCase.h"

using namespace std;

class SolutionCoinChange
{
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        vector<int> dp(amount+1, 0);
        for(int i=0; i<(int)coins.size(); i++)
            if (coins[i] < amount+1)
                dp[coins[i]] = 1;
        for(int i=1; i<=amount; i++)
        {
            int cur = i;
            int count = 0;
            for (int j=0; j<(int)coins.size(); j++)
            {
                if (cur < coins[j]) continue;
                if (cur == coins[j])
                {
                    count = dp[coins[j]];
                    break;
                }
                if (dp[cur - coins[j]] != 0)
                {
                    if (count == 0)
                        count = dp[cur - coins[j]] + 1;
                    else
                        count = std::min(count, dp[cur - coins[j]] + 1);
                }
            }
            if (count > 0)
                dp[i] = count;
        }
        return dp[amount] ? dp[amount] : -1;
    }
};

RUN_TESTCASE(CoinChange)
{
    SolutionCoinChange sln;
    
    vector<int> arr = {1,2,5};
    TESTCASE_ASSERT(sln.coinChange(arr, 11) == 3);
    
    vector<int> arr2 = {2};
    TESTCASE_ASSERT(sln.coinChange(arr2, 3) == -1);
    
    vector<int> arr3 = {1};
    TESTCASE_ASSERT(sln.coinChange(arr3, 0) == 0);
    
    vector<int> arr4 = {1,2};
    TESTCASE_ASSERT(sln.coinChange(arr4, 2) == 1);
    
    vector<int> arr5 = {474,83,404,3};
    TESTCASE_ASSERT(sln.coinChange(arr5, 264) == 8);
}
