#include "TestCase.h"
#include "BinaryTreeCommon.h"
#include <stack>

using namespace std;

class SolutionVerifyPreorderSOfBT : public BinaryTreeCommmon
{
public:
	bool isValidSerialization(string preorder) {
		stack<int> s;
		bool first = true;
		string::const_iterator it = preorder.begin();
		for (; it != preorder.end(); ++it)
		{
			bool isNull = false;
			if (*it == '#')
			{
				isNull = true;
				if (it + 1 != preorder.end())
					++it;
			}
			else
			{
				while (it + 1 != preorder.end() && *it != ',')
					++it;
			}
			if (isNull)
			{
				if (s.size() > 0)
				{
					if (++s.top() >= 2)
						s.pop();
				}
				else
				{
					++it;
					break;
				}
			}
			else
			{
				if (s.size() > 0)
				{
					if (++s.top() >= 2)
						s.pop();
				}
				else
				{
					if (!first)
						return false;
				}
				s.push(0);
				first = false;
			}
		}
		return s.empty() && it == preorder.end();
	}
};

RUN_TESTCASE(VerifyPreorderSOfBT)
{
	SolutionVerifyPreorderSOfBT sln;
	TESTCASE_ASSERT(sln.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#"));
	TESTCASE_ASSERT(!sln.isValidSerialization("9,3,4,#,#,1,#,#,#,2,#,6,#,#"));
	TESTCASE_ASSERT(!sln.isValidSerialization("1,#"));
	TESTCASE_ASSERT(!sln.isValidSerialization("9,#,#,1"));
	TESTCASE_ASSERT(sln.isValidSerialization("#"));
	TESTCASE_ASSERT(!sln.isValidSerialization("1"));
	TESTCASE_ASSERT(!sln.isValidSerialization("1,2"));
}