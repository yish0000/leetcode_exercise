#include "TestCase.h"
#include <set>

using namespace std;

class SolutionPermutationsII {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> result;
		if (nums.empty()) return result;
		result.push_back(vector<int>());
		permuteUnique(nums, result, result.back());
		return result;
	}

	void permuteUnique(vector<int>& nums, vector<vector<int>>& results, vector<int>& cur_result)
	{
		set<int> handled;
		vector<int> next_nums;
		vector<int> clone(cur_result);

		for (size_t i = 0; i < nums.size(); i++)
		{
			if (handled.find(nums[i]) != handled.end())
				continue;

			handled.insert(nums[i]);

			vector<int>* narr = &cur_result;
			if (i > 0)
			{
				results.push_back(clone);
				narr = &results.back();
			}
			narr->push_back(nums[i]);

			next_nums.clear();
			for (size_t j = 0; j < nums.size(); j++)
			{
				if (j != i)
					next_nums.push_back(nums[j]);
			}
			if (!next_nums.empty())
				permuteUnique(next_nums, results, *narr);
		}
	}
};

RUN_TESTCASE(PermutationsII)
{
	SolutionPermutationsII sln;
	vector<int> input1 = { 1,1,2 };
	vector<vector<int>> output1 = {
		{1,1,2},
		{1,2,1},
		{2,1,1},
	};
	TESTCASE_ASSERT(sln.permuteUnique(input1) == output1);

	vector<int> input2 = { 1,2,3 };
	vector<vector<int>> output2 = {
		{ 1,2,3 },
		{ 1,3,2 },
		{ 2,1,3 },
		{ 2,3,1 },
		{ 3,1,2 },
		{ 3,2,1 },
	};
	TESTCASE_ASSERT(sln.permuteUnique(input2) == output2);
}