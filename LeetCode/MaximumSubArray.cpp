#include "TestCase.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxSubArrayLinear(const vector<int>& nums, vector<int>& subarray) {
		int curSum = nums[0];
		int totalSum = curSum;
		int s = 0, e = 0;
		int start = 0, end = 0;
		for (size_t i = 1; i < nums.size(); i++)
		{
			if (nums[i] > curSum + nums[i])
			{
				curSum = nums[i];
				s = (int)i;
				e = (int)i;
			}
			else
			{
				curSum += nums[i];
				e = (int)i;
			}

			if (curSum > totalSum)
			{
				totalSum = curSum;
				start = s;
				end = e;
			}
		}
		for (int i = start; i <= end; i++)
			subarray.push_back(nums[i]);
		return totalSum;
	}

	int maxSubArray(const vector<int>& nums)
	{
		int curSum = nums[0];
		int totalSum = curSum;
		for (size_t i = 1; i < nums.size(); i++)
		{
			if (nums[i] > curSum + nums[i])
				curSum = nums[i];
			else
				curSum += nums[i];

			if (curSum > totalSum)
				totalSum = curSum;
		}
		return totalSum;
	}

	int maxSubArrayDivideAndConquer(const vector<int>& nums)
	{
		return maxSubArrayDivideAndConquerR(nums, 0, (int)nums.size() - 1);
	}

	int maxSubArrayDivideAndConquerR(const vector<int>& nums, int s, int e)
	{
		if (s >= e)
			return nums[s];

		int mid = s + (e - s) / 2;
		int crossMax = maxSubArrayCross(nums, s, e, mid);
		int lmax = maxSubArrayDivideAndConquerR(nums, s, mid);
		int rmax = maxSubArrayDivideAndConquerR(nums, mid + 1, e);

		if (crossMax >= lmax && crossMax >= rmax)
			return crossMax;
		else if (lmax > rmax)
			return lmax;
		else
			return rmax;
	}

	int maxSubArrayCross(const vector<int>& nums, int s, int e, int mid)
	{
		int lmax = std::numeric_limits<int>::min();
		int lsum = 0;
		for (int i = mid; i >= 0; i--)
		{
			lsum += nums[i];
			if (lsum > lmax)
				lmax = lsum;
		}

		int rmax = std::numeric_limits<int>::min();
		int rsum = 0;
		for (int i = mid + 1; i <= e; i++)
		{
			rsum += nums[i];
			if (rsum > rmax)
				rmax = rsum;
		}

		return lmax + rmax;
	}
};

RUN_TESTCASE(MaximumSubArray)
{
	Solution sln;
	vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	vector<int> result = { 4, -1, 2, 1 };
	vector<int> sub_array;
	TESTCASE_ASSERT(sln.maxSubArray(arr) == 6);
	TESTCASE_ASSERT(sln.maxSubArrayDivideAndConquer(arr) == 6);
	TESTCASE_ASSERT(sln.maxSubArrayLinear(arr, sub_array) == 6);
	TESTCASE_ASSERT(sub_array == result);
}
