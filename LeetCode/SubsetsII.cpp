#include "TestCase.h"

using namespace std;

class SolutionSubsetsII
{
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> arr;
		arr.push_back(vector<int>());
		if (nums.empty()) return arr;
		std::sort(nums.begin(), nums.end());
		bool dup = true;
		int last = nums[0];
		arr.push_back(vector<int>({ nums[0] }));
		int offset = 1;
		for (int i = 1; i < (int)nums.size(); i++)
		{
			if (last == nums[i])
			{
				dup = true;
			}
			else
			{
				dup = false;
				last = nums[i];
				offset = (int)arr.size();
			}

			vector<int> tmp;
			int pos = dup ? offset : 0;
			int n = (int)arr.size();
			for (int j = pos; j < n; j++)
			{
				tmp = arr[j];
				tmp.push_back(nums[i]);
				arr.push_back(tmp);
			}
			if (dup)
				offset += n - pos;
		}
		return arr;
	}
};

RUN_TESTCASE(SubsetsII)
{
	SolutionSubsetsII sln;

	vector<int> arr1 = { 1,2,2 };
	vector<vector<int>> ret1 = {
		{},
		{1},
		{2},
		{1,2},
		{2,2},
		{1,2,2},
	};
	TESTCASE_ASSERT(sln.subsetsWithDup(arr1) == ret1);

	vector<int> arr2 = { 2,2,1,2 };
	vector<vector<int>> ret2 = {
		{},
		{1},
		{2},
		{1,2},
		{2,2},
		{1,2,2},
		{2,2,2},
		{1,2,2,2},
	};
	TESTCASE_ASSERT(sln.subsetsWithDup(arr2) == ret2);

	vector<int> arr3 = { 3,2,1,3 };
	vector<vector<int>> ret3 = {
		{},
		{1},
		{2},
		{1,2},
		{3},
		{1,3},
		{2,3},
		{1,2,3},
		{3,3},
		{1,3,3},
		{2,3,3},
		{1,2,3,3},
	};
	TESTCASE_ASSERT(sln.subsetsWithDup(arr3) == ret3);

	vector<int> arr4 = { 1,1,2,2 };
	vector<vector<int>> ret4 = {
		{},
		{1},
		{1,1},
		{2},
		{1,2},
		{1,1,2},
		{2,2},
		{1,2,2},
		{1,1,2,2},
	};
	TESTCASE_ASSERT(sln.subsetsWithDup(arr4) == ret4);

	vector<int> arr5 = { 2,2,1,2,2 };
	vector<vector<int>> ret5 = {
		{},
		{1},
		{2},
		{1,2},
		{2,2},
		{1,2,2},
		{2,2,2},
		{1,2,2,2},
		{2,2,2,2},
		{1,2,2,2,2},
	};
	TESTCASE_ASSERT(sln.subsetsWithDup(arr2) == ret2);
}