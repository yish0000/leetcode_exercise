#include "TestCase.h"

using namespace std;

class SolutionCombinationSumIII
{
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> arr;
		vector<int> cur;
		dfs(arr, cur, k, n, 1);
		return arr;
	}

	void dfs(vector<vector<int>>& out, vector<int>& cur, int k, int target, int i)
	{
		if (cur.size() == k)
		{
			if (target == 0)
				out.push_back(cur);
			return;
		}

		for (; i <= 9; i++)
		{
			if (target >= i)
			{
				cur.push_back(i);
				target -= i;
				dfs(out, cur, k, target, i + 1);
				target += i;
				cur.pop_back();
			}
			else
				break;
		}
	}
};

RUN_TESTCASE(CombinationSumIII)
{
	SolutionCombinationSumIII sln;

	vector<vector<int>> ret1 = {
		{1,2,4},
	};
	TESTCASE_ASSERT(sln.combinationSum3(3, 7) == ret1);

	vector<vector<int>> ret2 = {
		{1,2,6},{1,3,5},{2,3,4}
	};
	TESTCASE_ASSERT(sln.combinationSum3(3, 9) == ret2);
}