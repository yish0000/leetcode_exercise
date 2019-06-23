#include <iostream>
#include <vector>
#include "TestCase.h"

class Solution
{
public:
    int reverse(int x) {
        int result = 0;
        while(x != 0)
        {
            int mod = x % 10;

            if (result > std::numeric_limits<int>::max() / 10 || (result == std::numeric_limits<int>::max() / 10 && mod > 7))
                return 0;
            if (result < std::numeric_limits<int>::min() / 10 || (result == std::numeric_limits<int>::min() / 10 && mod < -8))
                return 0;
            
            result = result * 10 + mod;
            x /= 10;
        }
        return result;
    }
};

RUN_TESTCASE(ReverseInt)
{
    Solution sln;
    TESTCASE_ASSERT(sln.reverse(123) == 321);
    TESTCASE_ASSERT(sln.reverse(-123) == -321);
    TESTCASE_ASSERT(sln.reverse(120) == 21);
    TESTCASE_ASSERT(sln.reverse(1534236469) == 0);
}
