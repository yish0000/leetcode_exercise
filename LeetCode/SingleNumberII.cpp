#include "TestCase.h"
#include <unordered_map>

using namespace std;

class SolutionSingleNumberII
{
public:
	int singleNumber(vector<int>& nums) {
		int res = 0;
		int mask = 0;
		for (int i = 0; i < 32; i++)
		{
			mask = 1 << i;

			int cnt = 0;
			for (size_t n = 0; n < nums.size(); ++n)
			{
				if ((nums[n] & mask) != 0)
					cnt++;
			}

			if (cnt % 3 != 0)
				res |= mask;
		}
		return res;
	}
};

RUN_TESTCASE(SingleNumberII)
{
	SolutionSingleNumberII sln;

	vector<int> arr1 = { 2,2,3,2 };
	TESTCASE_ASSERT(sln.singleNumber(arr1) == 3);
	vector<int> arr2 = { 0,1,0,1,0,1,99 };
	TESTCASE_ASSERT(sln.singleNumber(arr2) == 99);
}