#include "TestCase.h"
using namespace std;

class SolutionRomanToNumber {
public:
    int romanToInt(string s) {
        int curNum = 0;
        string::const_iterator it = s.begin();
        while(it != s.end())
        {
            if (*it == 'I')
            {
                if (it+1 != s.end() && (*(it+1) == 'V' || *(it+1) == 'X'))
                    curNum -= 1;
                else
                    curNum += 1;
            }
            else if (*it == 'V')
                curNum += 5;
            else if (*it == 'X')
            {
                if (it+1 != s.end() && (*(it+1) == 'L' || *(it+1) == 'C'))
                    curNum -= 10;
                else
                    curNum += 10;
            }
            else if (*it == 'L')
                curNum += 50;
            else if (*it == 'C')
            {
                if (it+1 != s.end() && (*(it+1) == 'D' || *(it+1) == 'M'))
                    curNum -= 100;
                else
                    curNum += 100;
            }
            else if (*it == 'D')
                curNum += 500;
            else if (*it == 'M')
                curNum += 1000;
            
            ++it;
        }
        
        return curNum;
    }
};

RUN_TESTCASE(RomanToNumber)
{
    SolutionRomanToNumber sln;
    TESTCASE_ASSERT(sln.romanToInt("III") == 3);
    TESTCASE_ASSERT(sln.romanToInt("IV") == 4);
    TESTCASE_ASSERT(sln.romanToInt("IX") == 9);
    TESTCASE_ASSERT(sln.romanToInt("LVIII") == 58);
    TESTCASE_ASSERT(sln.romanToInt("MCMXCIV") == 1994);
}
