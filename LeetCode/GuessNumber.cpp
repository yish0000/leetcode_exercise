#include "TestCase.h"

using namespace std;

class SolutionGuessNumber
{
public:
	int guessNumber(int n) {
		int l = 1, r = n;
		while (l < r)
		{
			int mid = l + (r - l) / 2;
			if (guess(mid) == 0)
				return mid;
			else if (guess(mid) < 0)
				r = mid - 1;
			else
				l = mid + 1;
		}
		return l;
	}

	int pick = 0;
	int guess(int num)
	{
		return pick - num;
	}
};

RUN_TESTCASE(GuessNumber)
{
	SolutionGuessNumber sln;

	sln.pick = 6;
	TESTCASE_ASSERT(sln.guessNumber(10) == 6);
}