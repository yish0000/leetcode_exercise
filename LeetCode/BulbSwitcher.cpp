#include "TestCase.h"

using namespace std;

class SolutionBulbSwitcher
{
public:
	int bulbSwitch(int n) {
		return (int)sqrt(n);
	}
};

RUN_TESTCASE(BulbSwitcher)
{
	SolutionBulbSwitcher sln;
	TESTCASE_ASSERT(sln.bulbSwitch(3) == 1);
}