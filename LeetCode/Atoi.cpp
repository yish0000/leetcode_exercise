#include "TestCase.h"

using namespace std;

class SolutionAtoi
{
public:
    enum State
    {
        WHITESPACE,
        SIGN,
        NUMBER,
    };
    
    int myAtoi(string str) {
        char state = WHITESPACE;
        char num_count = 0;
        int64_t result = 0;
        bool negative = false;
        string::const_iterator it = str.begin();
        while(it != str.end())
        {
            if (state == WHITESPACE)
            {
                if (*it == '+' || *it == '-')
                {
                    state = SIGN;
                    negative = (*it == '-');
                }
                else if (*it >= '0' && *it <= '9')
                {
                    state = NUMBER;
                    result = result * 10 + (*it - '0');
                    if (result > 0)
                        num_count++;
                }
                else if (*it != ' ')
                    break;
            }
            else if (state == SIGN)
            {
                if (*it >= '0' && *it <= '9')
                {
                    state = NUMBER;
                    result = result * 10 + (*it - '0');
                    if (result > 0)
                        num_count++;
                }
                else
                    break;
            }
            else if (state == NUMBER)
            {
                if (*it >= '0' && *it <= '9')
                {
                    if (num_count == 10)
                        return negative ? std::numeric_limits<int>::min() : std::numeric_limits<int>::max();
                    result = result * 10 + (*it - '0');
                    if (result > 0)
                        num_count++;
                }
                else
                    break;
            }
            
            ++it;
        }
        
        result = negative ? -result : result;
        if (result > INT_MAX)
            result = INT_MAX;
        else if (result < INT_MIN)
            result = INT_MIN;
        return (int)result;
    }
};

RUN_TESTCASE(Atoi)
{
    SolutionAtoi sln;
    
    TESTCASE_ASSERT(sln.myAtoi("42") == 42);
    TESTCASE_ASSERT(sln.myAtoi("   -42") == -42);
    TESTCASE_ASSERT(sln.myAtoi("4193 with words") == 4193);
    TESTCASE_ASSERT(sln.myAtoi("words and 987") == 0);
    TESTCASE_ASSERT(sln.myAtoi("-91283472332") == -2147483648);
    TESTCASE_ASSERT(sln.myAtoi("  0000000000012345678") == 12345678);
}
