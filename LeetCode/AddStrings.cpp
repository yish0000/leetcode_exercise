#include "TestCase.h"

using namespace std;

class SolutionAddStrings
{
public:
	string addStrings(string num1, string num2) {
		string& larger = num1;
		string& smaller = num2;
		if (larger.size() < smaller.size())
		{
			std::swap(larger, smaller);
		}
		int carry = 0;
		string::reverse_iterator it1 = larger.rbegin();
		string::reverse_iterator it2 = smaller.rbegin();
		for (; it1 != larger.rend(); ++it1)
		{
			if (it2 != smaller.rend())
			{
				int num1 = *it1 - '0';
				int num2 = *it2 - '0';
				int value = num1 + num2 + carry;
				if (value >= 10)
				{
					value %= 10;
					carry = 1;
				}
				else
					carry = 0;
				*it1 = '0' + value;

				++it2;
			}
			else
			{
				if (carry)
				{
					int num1 = *it1 - '0';
					int value = num1 + carry;
					if (value >= 10)
					{
						value %= 10;
						carry = 1;
					}
					else
						carry = 0;
					*it1 = '0' + value;
				}
				else
					break;
			}
		}
		if (carry)
			larger = "1" + larger;
		return larger;
	}
};

RUN_TESTCASE(AddStrings)
{
	SolutionAddStrings sln;
	TESTCASE_ASSERT(sln.addStrings("8895232", "8866983") == "17762215");
}