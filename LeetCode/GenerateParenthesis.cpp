#include "TestCase.h"
#include <stack>

using namespace std;

class SolutionGenerateParenthesis
{
public:
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		generateParenthesisHelper(res, n-1, 1, "(");
		return res;
	}

	void generateParenthesisHelper(vector<string>& arr, int n, int stack_size, const string& cur)
	{
		if (n > 0)
		{
			string res = cur;
			generateParenthesisHelper(arr, n - 1, stack_size + 1, res + '(');

			if (stack_size > 0)
				generateParenthesisHelper(arr, n, stack_size - 1, res + ')');
		}
		else
		{
			string res = cur;
			for (int i = 0; i < stack_size; i++)
				res.push_back(')');
			arr.push_back(res);
		}
	}
};

RUN_TESTCASE(GenerateParenthesis)
{
	SolutionGenerateParenthesis sln;

	vector<string> res = {
		"((()))",
		"(()())",
		"(())()",
		"()(())",
		"()()()",
	};
	TESTCASE_ASSERT(sln.generateParenthesis(3) == res);
}