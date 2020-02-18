#include "TestCase.h"
#include <stack>

using namespace std;

class SolutionEvaluateReversePolishNotation
{
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> s;
		for (auto& token : tokens)
		{
			if (token == "+" || token == "-" || token == "*" || token == "/")
			{
				int n2 = s.top();
				s.pop();
				int n1 = s.top();
				s.pop();

				if (token == "+")
					s.push(n1 + n2);
				else if (token == "-")
					s.push(n1 - n2);
				else if (token == "*")
					s.push(n1 * n2);
				else if (token == "/")
					s.push(n1 / n2);
			}
			else
			{
				s.push(atoi(token.c_str()));
			}
		}
		return s.top();
	}
};

RUN_TESTCASE(EvaluateReversePolishNotation)
{
	SolutionEvaluateReversePolishNotation sln;

	TESTCASE_ASSERT(sln.evalRPN(vector<string>({ "2", "1", "+", "3", "*" })) == 9);
	TESTCASE_ASSERT(sln.evalRPN(vector<string>({ "4", "13", "5", "/", "+" })) == 6);
	TESTCASE_ASSERT(sln.evalRPN(vector<string>({ "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" })) == 22);
}