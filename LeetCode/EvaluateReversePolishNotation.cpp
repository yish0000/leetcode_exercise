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

    vector<string> tokens1({ "2", "1", "+", "3", "*" });
	TESTCASE_ASSERT(sln.evalRPN(tokens1) == 9);
    
    vector<string> tokens2({ "4", "13", "5", "/", "+" });
	TESTCASE_ASSERT(sln.evalRPN(tokens2) == 6);
    
    vector<string> tokens3({ "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" });
	TESTCASE_ASSERT(sln.evalRPN(tokens3) == 22);
}
