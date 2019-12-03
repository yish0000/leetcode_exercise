#include "TestCase.h"

using namespace std;

class SolutionAddBinary
{
public:
	string addBinary(string a, string b) {
		string& larger = a;
		string& smaller = b;
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
				if (*it1 != *it2)
				{
					if (carry)
					{
						*it1 = '0';
						carry = 1;
					}
					else
						*it1 = '1';
				}
				else
				{
					if (*it1 == '1')
					{
						*it1 = carry ? '1' : '0';
						carry = 1;
					}
					else
					{
						*it1 = carry ? '1' : '0';
						carry = 0;
					}
				}

				++it2;
			}
			else
			{
				if (carry)
				{
					if (*it1 == '1')
					{
						*it1 = '0';
						carry = 1;
					}
					else
					{
						*it1 = '1';
						carry = 0;
					}
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

RUN_TESTCASE(AddBinary)
{
	SolutionAddBinary sln;
	TESTCASE_ASSERT(sln.addBinary("10101", "1011") == "100000");
	TESTCASE_ASSERT(sln.addBinary("1", "111") == "1000");
}