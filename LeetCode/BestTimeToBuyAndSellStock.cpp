#include "TestCase.h"

using namespace std;

class SolutionBestTimeToBuyAndSellStock
{
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty())
			return 0;

		int min_price = prices[0];
		int max_profit = 0;
		for (size_t i = 1; i < prices.size(); i++)
		{
			if (prices[i] - min_price > max_profit)
				max_profit = prices[i] - min_price;

			min_price = std::min(min_price, prices[i]);
		}
		return max_profit;
	}
};

RUN_TESTCASE(BestTimeToBuyAndSellStock)
{
	SolutionBestTimeToBuyAndSellStock sln;

	vector<int> arr1 = { 7,1,5,3,6,4 };
	TESTCASE_ASSERT(sln.maxProfit(arr1) == 5);

	vector<int> arr2 = { 7,6,4,3,1 };
	TESTCASE_ASSERT(sln.maxProfit(arr2) == 0);
}