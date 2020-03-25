#include "TestCase.h"

using namespace std;

class SolutionMissingNumber
{
public:
	int missingNumber(vector<int>& nums) {
		int sum = 0;
		for (auto n : nums) sum += n;
		int n = (int)nums.size();
		int expected = n*(n + 1) / 2;
		return expected - sum;
	}
};

RUN_TESTCASE(MissingNumber)
{
	SolutionMissingNumber sln;

	vector<int> arr1 = { 3,0,1 };
	TESTCASE_ASSERT(sln.missingNumber(arr1) == 2);

	vector<int> arr2 = { 9,6,4,2,3,5,7,0,1 };
	TESTCASE_ASSERT(sln.missingNumber(arr2) == 8);
}