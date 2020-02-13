#include "TestCase.h"

using namespace std;

class SolutionRegularExpressionMatching
{
public:
    enum
    {
        INIT,
        CHAR,
        MODE,
    };
    
    bool isMatch(string s, string p)
    {
        char state = INIT;
        char cur_char = 0;
        string::const_iterator itS = s.begin();
        string::const_iterator itP = p.begin();
        string::const_iterator lastItS = s.end();
        string::const_iterator lastItP = p.end();

        while (itS != s.end())
        {
            if (state == INIT)
            {
                if (*itP == '*')
                    return false;
                else
                {
                    cur_char = *itP++;
                    state = CHAR;
                }
            }
            else if (state == CHAR)
            {
                if (*itP == '*')
                {
                    state = MODE;
                    lastItP = itP - 1;
                    ++itP;
                }
                else
                {
                    if (*itS == cur_char || cur_char == '.')
                    {
                        cur_char = *itP++;
                        itS++;
                    }
                    else
                    {
                        itP = lastItP;
                        itS = lastItS;
                        state = INIT;
                    }
                }
            }
            else if (state == MODE)
            {
                if (itS == s.end())
                    break;
                else
                {
                    if (cur_char != '.' && cur_char != *itS)
                        state = INIT;
                    else
                    {
                        lastItS = itS;
                        state = INIT;
                    }
                }
            }
        }
        
        while (itP != p.end())
        {
            if (*itP != '*' && itP + 1 != p.end() && *(itP + 1) == '*')
                itP += 2;
            else
                break;
        }
        
        return itS == s.end() && itP == p.end();
    }
};

RUN_TESTCASE(RegularExpressionMatching)
{
    //SolutionRegularExpressionMatching sln;
    
    //TESTCASE_ASSERT(sln.isMatch("aab", "aa*ab"));
}
