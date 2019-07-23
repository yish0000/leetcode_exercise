#include "TestCase.h"
#include <unordered_set>

using namespace std;

class SolutionCombinationSum
{
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> r;
		vector<int> empty;
		combinationSumHelper(r, candidates, target, empty, 0);
		return r;
	}

	void combinationSumHelper(vector<vector<int>>& res, vector<int>& candidates, int target, vector<int>& path, int n)
	{
		if (target > 0)
		{
			for (size_t i = n; i < candidates.size(); i++)
			{
				if (target >= candidates[i])
				{
					vector<int> newPath(path);
					newPath.push_back(candidates[i]);
					combinationSumHelper(res, candidates, target - candidates[i], newPath, i);
				}
			}
		}
		else
		{
			res.emplace_back(path);
		}
	}
};

RUN_TESTCASE(CombinationSum)
{
	SolutionCombinationSum sln;

	vector<int> arr1 = { 2,3,6,7 };
	vector<vector<int>> res1 = {
		{ 2,2,3 },
		{7},
	};
	TESTCASE_ASSERT(sln.combinationSum(arr1, 7) == res1);

	vector<int> arr2 = { 2,3,5 };
	vector<vector<int>> res2 = {
		{2,2,2,2},
		{ 2,3,3 },
		{ 3,5 },
	};
	TESTCASE_ASSERT(sln.combinationSum(arr2, 8) == res2);
}