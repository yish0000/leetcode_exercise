#include "TestCase.h"

class SolutionPow
{
public:
    double myPow(double x, int n) {
        if (x == 0.0) return 0.0;
        if (x == 1.0) return 1.0;
        if (n == 0)
            return 1.0;
        else if (n == 1)
            return x;
        else if (n == -1)
            return 1 / x;
        else
        {
            int half = n / 2;
            int mod = n % 2;
            double r1 = myPow(x, half);
            if (!mod)
                return r1 * r1;
            else if (mod == 1)
                return r1 * r1 * x;
            else
                return r1 * r1 * (1/x);
        }
    }
};

RUN_TESTCASE(Pow)
{
    SolutionPow sln;
    TESTCASE_ASSERT(doubleEqual(sln.myPow(2.0, 0), 1.0));
    TESTCASE_ASSERT(doubleEqual(sln.myPow(2.0, 10), 1024.0));
    TESTCASE_ASSERT(doubleEqual(sln.myPow(2.1, 3), 9.261));
    TESTCASE_ASSERT(doubleEqual(sln.myPow(2.0, -2), 0.25));
    TESTCASE_ASSERT(doubleEqual(sln.myPow(0.00001, 2147483647), 0));
    TESTCASE_ASSERT(doubleEqual(sln.myPow(2.00000, -2147483648), 0));
    TESTCASE_ASSERT(doubleEqual(sln.myPow(34.00515, -3), 3e-05));
}
