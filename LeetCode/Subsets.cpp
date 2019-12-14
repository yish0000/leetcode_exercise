#include "TestCase.h"

using namespace std;

class SolutionSubsets
{
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> ret;
		ret.push_back(vector<int>());
		for (int i = 0; i < nums.size(); i++)
		{
			vector<int> n;
			vector<vector<int>> arr;
			for (auto& s : ret)
			{
				n = s;
				n.push_back(nums[i]);
				arr.push_back(n);
			}
			ret.insert(ret.end(), arr.begin(), arr.end());
		}
		return ret;
	}

	vector<vector<int>> subsets_bt(vector<int>& nums) {
		vector<vector<int>> ret;
		vector<int> tmp;
		ret.push_back(tmp);
		for (int i = 1; i <= nums.size(); i++)
		{
			backtrack(ret, tmp, nums, i, 0);
		}
		return ret;
	}

protected:
	void backtrack(vector<vector<int>>& out, vector<int>& tmp, vector<int>& nums, int k, int pos)
	{
		if (tmp.size() >= k)
			out.push_back(tmp);
		else
		{
			for (int i = pos; i < nums.size(); i++)
			{
				tmp.push_back(nums[i]);
				backtrack(out, tmp, nums, k, i + 1);
				tmp.pop_back();
			}
		}
	}
};

RUN_TESTCASE(Subsets)
{
	SolutionSubsets sln;

	vector<int> arr = { 1,2,3 };
	vector<vector<int>> ret =
	{
		{},
		{1},
		{2},
		{1,2},
		{3},
		{1,3},
		{2,3},
		{1,2,3},
	};
	TESTCASE_ASSERT(sln.subsets(arr) == ret);
}