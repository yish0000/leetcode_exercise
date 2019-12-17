#include "TestCase.h"

using namespace std;

class SolutionMergeSortedArray
{
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		for (int i = m; i < (int)nums1.size(); i++)
			nums1[i] = nums2[i - m];
		std::sort(nums1.begin(), nums1.end());
	}
};

RUN_TESTCASE(MergeSortedArray)
{
	SolutionMergeSortedArray sln;

	vector<int> arr1 = { 1,2,3,0,0,0 };
	vector<int> arr2 = { 2,5,6 };
	vector<int> arr3 = { 1,2,2,3,5,6 };
	sln.merge(arr1, 3, arr2, 3);
	TESTCASE_ASSERT(arr1 == arr3);
}