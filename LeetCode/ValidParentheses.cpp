#include "TestCase.h"
#include <stack>

using namespace std;

class SolutionValidParentheses {
public:
    bool isValid(string s) {
        stack<char> stk;
        string::const_iterator it = s.begin();
        for (; it != s.end(); ++it)
        {
            if (*it == '(' || *it == '[' || *it == '{')
            {
                stk.push(*it);
                continue;
            }
            else if (stk.empty() ||
                     (*it == ')' && '(' != stk.top()) ||
                     (*it == ']' && '[' != stk.top()) ||
                     (*it == '}' && '{' != stk.top()))
                return false;
            stk.pop();
        }
        return stk.empty();
    }
};

RUN_TESTCASE(ValidParentheses)
{
    SolutionValidParentheses sln;
    TESTCASE_ASSERT(sln.isValid("()"));
    TESTCASE_ASSERT(sln.isValid("()[]{}"));
    TESTCASE_ASSERT(!sln.isValid("(]"));
    TESTCASE_ASSERT(!sln.isValid("([)]"));
    TESTCASE_ASSERT(sln.isValid("{[]}"));
    TESTCASE_ASSERT(sln.isValid("{[()]}"));
    TESTCASE_ASSERT(!sln.isValid("]"));
    TESTCASE_ASSERT(!sln.isValid("(])"));
}
