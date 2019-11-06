#include "TestCase.h"

using namespace std;

class SolutionPermutations
{
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> ret;
		vector<int> empty;
		permute_helper(ret, nums, empty);
		return ret;
	}

	void permute_helper(vector<vector<int>>& ret, vector<int>& nums, vector<int>& path)
	{
		for (int i = 0; i < nums.size(); i++)
		{
			vector<int> newNums(nums);
			newNums.erase(newNums.begin() + i);
			vector<int> newPath(path);
			newPath.push_back(nums[i]);
			if (newNums.empty())
				ret.emplace_back(newPath);
			else
				permute_helper(ret, newNums, newPath);
		}
	}
};

RUN_TESTCASE(Permutations)
{
	SolutionPermutations sln;

	vector<int> arr1 = { 1,2,3 };
	vector<vector<int>> ret1 = {
		{1,2,3},
		{1,3,2},
		{2,1,3},
		{2,3,1},
		{3,1,2},
		{3,2,1}
	};
	TESTCASE_ASSERT(sln.permute(arr1) == ret1);
}