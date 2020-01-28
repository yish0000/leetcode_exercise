#include "TestCase.h"

using namespace std;

class SolutionDivideTwoIntegers
{
public:
    int divide(int dividend, int divisor) {
        if (dividend == std::numeric_limits<int>::min())
        {
            if (divisor == -1)
                return std::numeric_limits<int>::max();
            else if (divisor == 1)
                return std::numeric_limits<int>::min();
            else if (divisor == std::numeric_limits<int>::min())
                return 1;
            else if (divisor == std::numeric_limits<int>::max())
                return -1;
        }
        
        int sign = ((dividend > 0) ^ (divisor > 0)) ? -1 : 1;
        int result = 0;
        int shift = 32;
        int64_t y = abs((int64_t)dividend);
        int64_t x = abs((int64_t)divisor);
        while (y >= x)
        {
            while ((x << shift) > y)
                shift--;
            y -= (x << shift);
            result += (1 << shift);
        }
        return sign > 0 ? result : -result;
    }
};

RUN_TESTCASE(DivideTwoIntegers)
{
    SolutionDivideTwoIntegers sln;
    
    TESTCASE_ASSERT(sln.divide(10, 3) == 3);
    TESTCASE_ASSERT(sln.divide(7, -3) == -2);
}
