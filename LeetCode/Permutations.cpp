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
		for (int i = 0; i < (int)nums.size(); i++)
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

	vector<vector<int>> permuteFast(vector<int>& nums) {
		vector<vector<int>> ret;
		permute_helper_fast(ret, nums, 0, (int)nums.size() - 1);
		return ret;
	}

	void permute_helper_fast(vector<vector<int>>& ret, vector<int>& nums, int l, int r)
	{
		if (l == r)
			ret.emplace_back(nums);
		else
		{
			for (int i = l; i <= r; i++)
			{
				std::swap(nums[i], nums[l]);
				permute_helper_fast(ret, nums, l + 1, r);
				std::swap(nums[i], nums[l]);
			}
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