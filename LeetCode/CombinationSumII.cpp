#include "TestCase.h"

using namespace std;

class SolutionCombinationSumII
{
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> ret;
		vector<int> empty;
		std::sort(candidates.begin(), candidates.end());
		combinationSum2Helper(ret, candidates, target, empty, 0);
		return ret;
	}

	void combinationSum2Helper(vector<vector<int>>& ret, vector<int>& candidates, int target, vector<int>& path, int idx)
	{
		if (target > 0)
		{
			int last = -1;
			for (int i = idx; i < (int)candidates.size(); i++)
			{
				if (target >= candidates[i] && candidates[i] != last)
				{
					vector<int> newPath(path);
					newPath.push_back(candidates[i]);
					combinationSum2Helper(ret, candidates, target - candidates[i], newPath, i + 1);
				}
				last = candidates[i];
			}
		}
		else if (target == 0)
		{
			ret.emplace_back(path);
		}
	}
};

RUN_TESTCASE(CombinationSumII)
{
	SolutionCombinationSumII sln;

	vector<int> arr1 = { 10,1,2,7,6,1,5 };
	vector<vector<int>> ret1 = {
		{1, 1, 6},
		{1, 2, 5},
		{1, 7},
		{2, 6},
	};
	TESTCASE_ASSERT(sln.combinationSum2(arr1, 8) == ret1);

	vector<int> arr2 = { 2,5,2,1,2 };
	vector<vector<int>> ret2 = {
		{1,2,2},
		{5},
	};
	TESTCASE_ASSERT(sln.combinationSum2(arr2, 5) == ret2);
}