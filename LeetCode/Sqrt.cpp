#include "TestCase.h"

class SolutionSqrt
{
public:
	int mySqrt(int x)
	{
		if (x == 0)
			return 0;
		if (x < 4)
			return 1;
		int l = 2, r = x;
		while (l < r)
		{
			int mid = l + (r - l) / 2;
			int64_t y = (int64_t)mid * mid;
			if (y == x)
				return mid;
			else if (y < x)
			{
				if (l == mid)
					return mid;
				l = mid;
			}
			else
				r = mid;
		}

		return l;
	}

	int mySqrtNewton(int x)
	{
		if (x == 0) return 0;
		if (x == 1) return 1;
		double x0 = (double)x / 2;
		for (int i = 0; i < 1000; i++)
		{
			double x1 = (x0 + x / x0) / 2;
			if (fabs(x1 - x0) <= 0.1)
				return (int)x1;
			x0 = x1;
		}
		return (int)x0;
	}
};

RUN_TESTCASE(Sqrt)
{
	SolutionSqrt sln;
	TESTCASE_ASSERT(sln.mySqrtNewton(1) == 1);
	TESTCASE_ASSERT(sln.mySqrtNewton(16) == 4);
	TESTCASE_ASSERT(sln.mySqrtNewton(188) == 13);
	TESTCASE_ASSERT(sln.mySqrtNewton(1582654520) == 39782);
	TESTCASE_ASSERT(sln.mySqrtNewton(2147395599) == 46339);
}
