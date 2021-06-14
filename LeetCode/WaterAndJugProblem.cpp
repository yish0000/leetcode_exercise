#include "TestCase.h"

using namespace std;

class SolutionWaterAndJugProblem
{
public:
	int gcd(int a, int b) {
		if (a < b)
			std::swap(a, b);

		int mod;
		do
		{
			mod = a % b;
			if (mod == 0)
				break;
			a = b;
			b = mod;
		} while (mod != 0);

		return b;
	}

	bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
		if (jug1Capacity + jug2Capacity < targetCapacity)
			return false;
		return targetCapacity % gcd(jug1Capacity, jug2Capacity) == 0;
	}
};

RUN_TESTCASE(WaterAndJugProblem)
{
	SolutionWaterAndJugProblem sln;
	TESTCASE_ASSERT(sln.canMeasureWater(3, 5, 4));
	TESTCASE_ASSERT(!sln.canMeasureWater(2, 6, 5));
	TESTCASE_ASSERT(sln.canMeasureWater(1, 2, 3));
	TESTCASE_ASSERT(sln.canMeasureWater(34, 5, 6));
	TESTCASE_ASSERT(!sln.canMeasureWater(1, 1, 12));
	TESTCASE_ASSERT(sln.canMeasureWater(11, 7, 1));
}