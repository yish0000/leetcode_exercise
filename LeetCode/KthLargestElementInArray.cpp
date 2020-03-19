#include "TestCase.h"

using namespace std;

class SolutionKthLargestElementInArray
{
public:
	int findKthLargestSort(vector<int>& nums, int k) {
		if (k > nums.size()) return 0;
		std::sort(nums.begin(), nums.end(), [](int a, int b) { return a > b; });
		return nums[k - 1];
	}

	int findKthLargest(vector<int>& nums, int k) {
		return quick_select(nums, 0, (int)nums.size() - 1, k);
	}

	int quick_select(vector<int>& nums, int beg, int end, int k)
	{
		if (beg == end)
			return nums[beg];
		int i = beg;
		int j = end + 1;
		int pivot = nums[i];
		while (i < j)
		{
			while (nums[++i] > pivot)
			{
				if (i >= end)
					break;
			}

			while (nums[--j] < pivot)
			{
				if (j <= beg)
					break;
			}

			if (i >= j)
				break;

			std::swap(nums[i], nums[j]);
		}

		std::swap(nums[beg], nums[j]);

		if (j == k - 1)
			return nums[j];
		else if (j < k - 1)
			return quick_select(nums, j + 1, end, k);
		else
			return quick_select(nums, beg, j - 1, k);
	}
};

RUN_TESTCASE(KthLargestElementInArray)
{
	SolutionKthLargestElementInArray sln;

	vector<int> arr1 = { 3,2,1,5,6,4 };
	TESTCASE_ASSERT(sln.findKthLargest(arr1, 2) == 5);

	vector<int> arr2 = { 3,2,3,1,2,4,5,5,6 };
	TESTCASE_ASSERT(sln.findKthLargest(arr2, 4) == 4);

	vector<int> arr3 = { 1 };
	TESTCASE_ASSERT(sln.findKthLargest(arr3, 1) == 1);
}