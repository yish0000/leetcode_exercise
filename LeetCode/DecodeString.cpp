#include "TestCase.h"
#include <stack>

using namespace std;

class SolutionDecodeString
{
public:
    string decodeString(string s) {
        if (s.empty()) return s;
        if (s.find_first_of('[') == string::npos)
            return s;
        string res;
        stack<int> stk;
        int i = 0;
        int num = 0;
        while(i < (int)s.length())
        {
            if (isdigit(s[i]) && stk.empty())
                num = num * 10 + (s[i] - '0');
            else if (s[i] == '[')
                stk.push(i);
            else if (s[i] == ']')
            {
                int pos = stk.top();
                stk.pop();
                if (stk.empty())
                {
                    string sub = decodeString(s.substr(pos+1, i-pos-1));
                    for (int i=0; i<num; i++)
                        res += sub;
                    num = 0;
                }
            }
            else if (stk.empty())
                res += s[i];
            i++;
        }
        return res;
    }
};

RUN_TESTCASE(DecodeString)
{
    SolutionDecodeString sln;
    TESTCASE_ASSERT(sln.decodeString("3[a]2[bc]") == "aaabcbc");
    TESTCASE_ASSERT(sln.decodeString("yy3[a2[c]]") == "yyaccaccacc");
    TESTCASE_ASSERT(sln.decodeString("2[abc]3[cd]ef") == "abcabccdcdcdef");
}
