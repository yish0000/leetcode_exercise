#include "TestCase.h"

using namespace std;

class SolutionAddDigits
{
public:
	int addDigits(int num) {
		while (num >= 10)
		{
			int cur = 0;
			while (num > 0)
			{
				cur += num % 10;
				num /= 10;
			}
			num = cur;
		}
		return num;
	}
};

RUN_TESTCASE(AddDigits)
{
	SolutionAddDigits sln;
	TESTCASE_ASSERT(sln.addDigits(38) == 2);
	TESTCASE_ASSERT(sln.addDigits(777) == 3);
}