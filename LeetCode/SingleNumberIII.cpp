#include "TestCase.h"

using namespace std;

class SolutionSingleNumberIII
{
public:
	vector<int> singleNumber(vector<int>& nums) {
		int sum = 0;
		for (auto n : nums)
			sum ^= n;
		int i = 0;
		for (; i < 32; i++)
		{
			if (sum & (1 << i))
			{
				sum = 1 << i;
				break;
			}
		}
		int x = 0, y = 0;
		for (auto n : nums)
		{
			if (sum & n)
				x ^= n;
			else
				y ^= n;
		}
		return vector<int>({ x, y });
	}
};

RUN_TESTCASE(SingleNumberIII)
{
	SolutionSingleNumberIII sln;

	vector<int> arr1 = { 1,2,1,3,2,5 };
	vector<int> ret1 = { 3,5 };
	TESTCASE_ASSERT(sln.singleNumber(arr1) == ret1);
}