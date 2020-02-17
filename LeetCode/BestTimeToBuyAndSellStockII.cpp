#include "TestCase.h"

using namespace std;

class SolutionBestTimeToBuyAndSellStockII
{
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty())
			return 0;

		int profit = 0;
		int cur = std::numeric_limits<int>::min();
		for (int i = 0; i < (int)prices.size(); i++)
		{
			if (cur == std::numeric_limits<int>::min())
			{
				if (i + 1 < (int)prices.size() && prices[i + 1] > prices[i])
					cur = prices[i];
			}
			else
			{
				if ((i + 1 < (int)prices.size() && prices[i + 1] < prices[i]) ||
					i + 1 == (int)prices.size())
				{
					profit += prices[i] - cur;
					cur = std::numeric_limits<int>::min();
				}
			}
		}

		return profit;
	}
};

RUN_TESTCASE(BestTimeToBuyAndSellStockII)
{
	SolutionBestTimeToBuyAndSellStockII sln;

	vector<int> arr1 = { 7,1,5,3,6,4 };
	TESTCASE_ASSERT(sln.maxProfit(arr1) == 7);

	vector<int> arr2 = { 1,2,3,4,5 };
	TESTCASE_ASSERT(sln.maxProfit(arr2) == 4);

	vector<int> arr3 = { 7,6,4,3,1 };
	TESTCASE_ASSERT(sln.maxProfit(arr3) == 0);

	vector<int> arr4 = { 2,1,2,0,1 };
	TESTCASE_ASSERT(sln.maxProfit(arr4) == 2);
}