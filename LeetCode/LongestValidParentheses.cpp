#include "TestCase.h"
#include <stack>

using namespace std;

class SolutionLongestValidParentheses
{
public:
	int longestValidParentheses(string s) {
		return dp(s);
		/*
		stack<int> st;
		int max_len = 0;
		st.push(-1);
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
				st.push(i);
			else
			{
				st.pop();
				if (st.empty())
					st.push(i);
				else
					max_len = std::max(max_len, i - st.top());
			}
		}
		return max_len;
		*/
	}

	int dp(string& s)
	{
		if (s.empty()) return 0;

		int max_len = 0;
		vector<int> dp(s.size(), 0);
		dp[0] = 0;
		for (int i = 1; i < s.size(); i++)
		{
			if (s[i] == '(')
				dp[i] = 0;
			else
			{
				if (s[i - 1] == '(')
					dp[i] = (i - 2 >= 0) ? dp[i - 2] + 2 : 2;
				else
				{
					if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(')
					{
						if (i - dp[i - 1] - 2 >= 0)
							dp[i] = dp[i - dp[i - 1] - 2] + dp[i - 1] + 2;
						else
							dp[i] = dp[i - 1] + 2;
					}
					else
						dp[i] = 0;
				}

				max_len = std::max(max_len, dp[i]);
			}
		}

		return max_len;
	}
};

RUN_TESTCASE(LongestValidParentheses)
{
	SolutionLongestValidParentheses sln;
	TESTCASE_ASSERT(sln.longestValidParentheses("))") == 0);
	TESTCASE_ASSERT(sln.longestValidParentheses("(()") == 2);
	TESTCASE_ASSERT(sln.longestValidParentheses(")()())") == 4);
	TESTCASE_ASSERT(sln.longestValidParentheses("((())") == 4);
	TESTCASE_ASSERT(sln.longestValidParentheses("()(()") == 2);
	TESTCASE_ASSERT(sln.longestValidParentheses("(()(((()") == 2);
	TESTCASE_ASSERT(sln.longestValidParentheses("(()(((()(()") == 2);
	TESTCASE_ASSERT(sln.longestValidParentheses("(()(((()(())") == 6);
	TESTCASE_ASSERT(sln.longestValidParentheses("())") == 2);
}