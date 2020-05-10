#include "TestCase.h"

using namespace std;

class SolutionCountingBits
{
public:
	vector<int> countBits(int num)
	{
		vector<int> ret;
		ret.push_back(0);
		if (num > 0)
			ret.push_back(1);
		for (int i = 2, remain = i; i <= num; i++)
		{
			ret.push_back(ret[i - remain] + 1);
			if (--remain == 0)
				remain = i + 1;
		}
		return ret;
	}
};

RUN_TESTCASE(CountingBits)
{
	SolutionCountingBits sln;

	vector<int> ret1 = { 0,1,1 };
	TESTCASE_ASSERT(sln.countBits(2) == ret1);

	vector<int> ret2 = { 0,1,1,2,1,2 };
	TESTCASE_ASSERT(sln.countBits(5) == ret2);

	vector<int> ret3 = { 0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4,1 };
	TESTCASE_ASSERT(sln.countBits(16) == ret3);
}