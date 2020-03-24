#include "TestCase.h"

using namespace std;

class SolutionValidTriangleNumber
{
public:
	int triangleNumber(vector<int>& nums) {
		std::sort(nums.begin(), nums.end());
		/*
		int total_count = 0;
		int cur_count = 0;
		int cur_len = 0;
		dfs(nums, total_count, 0, cur_count, cur_len);
		return total_count;
		*/

		int total_count = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == 0)
				continue;

			for (int j = i + 1; j < nums.size(); j++)
			{
				int cur_len = nums[i] + nums[j];
				int l = j + 1, r = nums.size() - 1;
				while (l <= r)
				{
					int mid = l + (r - l) / 2;
					if (nums[mid] >= cur_len)
						r = mid - 1;
					else
						l = mid + 1;
				}
				total_count += l - j - 1;
			}
		}
		return total_count;
	}

	void dfs(vector<int>& nums, int& total_count, int n, int& cur_count, int& cur_len)
	{
		if (cur_count == 3)
		{
			++total_count;
			return;
		}

		for (int i = n; i < nums.size(); i++)
		{
			if (nums.size() - i >= 3 - cur_count && cur_count < 2 || nums[i] < cur_len)
			{
				++cur_count;
				cur_len += nums[i];
				dfs(nums, total_count, i + 1, cur_count, cur_len);
				cur_len -= nums[i];
				--cur_count;
			}
			else
				break;
		}
	}
};

RUN_TESTCASE(ValidTriangleNumber)
{
	SolutionValidTriangleNumber sln;

	vector<int> arr1 = { 2,2,3,4 };
	TESTCASE_ASSERT(sln.triangleNumber(arr1) == 3);
}