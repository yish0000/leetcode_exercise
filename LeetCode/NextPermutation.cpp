#include "TestCase.h"

using namespace std;

class SolutionNextPermutation
{
public:
	void nextPermutation(vector<int>& nums)
	{
		int N = (int)nums.size();
		int a = -1;
		for (int i = N - 1; i > 0; i--)
		{
			if (nums[i - 1] < nums[i])
			{
				a = i - 1;
				break;
			}
		}
		if (a == -1)
		{
			reverse(nums, 0, N - 1);
			return;
		}

		int b = -1;
		for (int i = N - 1; i >= 0; i--)
		{
			if (nums[i] > nums[a])
			{
				b = i;
				break;
			}
		}

		std::swap(nums[a], nums[b]);
		reverse(nums, a + 1, N - 1);
	}

	void reverse(vector<int>& nums, int l, int r)
	{
		while (l < r)
		{
			std::swap(nums[l], nums[r]);
			l++;
			r--;
		}
	}
};

RUN_TESTCASE(NextPermutation)
{
	SolutionNextPermutation sln;

	vector<int> arr1 = { 1,2,3 };
	sln.nextPermutation(arr1);
	TESTCASE_ASSERT(arr1 == vector<int>({ 1, 3, 2 }));
	sln.nextPermutation(arr1);
	TESTCASE_ASSERT(arr1 == vector<int>({ 2, 1, 3 }));
	sln.nextPermutation(arr1);
	TESTCASE_ASSERT(arr1 == vector<int>({ 2, 3, 1 }));
	sln.nextPermutation(arr1);
	TESTCASE_ASSERT(arr1 == vector<int>({ 3, 1, 2 }));
	sln.nextPermutation(arr1);
	TESTCASE_ASSERT(arr1 == vector<int>({ 3, 2, 1 }));
	sln.nextPermutation(arr1);
	TESTCASE_ASSERT(arr1 == vector<int>({ 1, 2, 3 }));

	vector<int> arr2 = { 1,1,5 };
	sln.nextPermutation(arr2);
	TESTCASE_ASSERT(arr2 == vector<int>({ 1, 5, 1 }));
}