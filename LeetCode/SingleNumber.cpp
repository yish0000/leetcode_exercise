#include "TestCase.h"

using namespace std;

class SolutionSingleNumber
{
public:
	int singleNumber(vector<int>& nums) {
		int result = 0;
		for (size_t i = 0; i < nums.size(); ++i)
		{
			result ^= nums[i];
		}
		return result;
	}
};

RUN_TESTCASE(SingleNumber)
{
	SolutionSingleNumber sln;

	vector<int> arr1 = { 2,2,1 };
	TESTCASE_ASSERT(sln.singleNumber(arr1) == 1);

	vector<int> arr2 = { 4, 1, 2, 1, 2 };
	TESTCASE_ASSERT(sln.singleNumber(arr2) == 4);
}