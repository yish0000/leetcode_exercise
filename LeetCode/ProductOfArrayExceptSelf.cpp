#include "TestCase.h"

using namespace std;

class SolutionProductOfArrayExceptSelf
{
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> L, R;
		L.resize(nums.size(), 1);
		R.resize(nums.size(), 1);
		for (int i = 1; i < nums.size(); i++)
		{
			L[i] = L[i - 1] * nums[i - 1];
			R[nums.size() - 1 - i] = R[nums.size() - i] * nums[nums.size() - i];
		}
		for (int i = 0; i < nums.size(); i++)
			nums[i] = L[i] * R[i];
		return nums;
	}
};

RUN_TESTCASE(ProductOfArrayExceptSelf)
{
	SolutionProductOfArrayExceptSelf sln;

	vector<int> arr1 = { 1,2,3,4 };
	vector<int> ret1 = { 24,12,8,6 };
	TESTCASE_ASSERT(sln.productExceptSelf(arr1) == ret1);
}