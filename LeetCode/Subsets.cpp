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