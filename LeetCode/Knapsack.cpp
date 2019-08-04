#include "TestCase.h"

using namespace std;

class SolutionKnapsack
{
public:
    int knapsack(vector<int>& weights, vector<int>& prices, int capacity)
    {
        vector<vector<int>> dp((int)weights.size()+1, vector<int>(capacity+1, 0));
        for(int i=1; i<=weights.size(); i++)
        {
            for (int j=1; j<=capacity; j++)
            {
                if (j < weights[i-1])
                {
                    dp[i][j] = dp[i-1][j];
                    continue;
                }
                else
                {
                    dp[i][j] = std::max(dp[i-1][j-weights[i-1]]+prices[i-1], dp[i-1][j]);
                }
            }
        }
        return dp[(int)weights.size()][capacity];
    }
};

RUN_TESTCASE(Knapsack)
{
    SolutionKnapsack sln;
    
    vector<int> w1 = {5,4,7,2,6};
    vector<int> p1 = {12,3,10,3,6};
    TESTCASE_ASSERT(sln.knapsack(w1, p1, 15) == 25);
}
