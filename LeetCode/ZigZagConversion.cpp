#include "TestCase.h"

using namespace std;

class SolutionZigZagConversion
{
public:
	string convert(string s, int numRows) {
		string result;
		for (int i = 0; i < numRows; i++)
		{
			bool odd = true;
			int index = i;
			result += s[index];
			while (index < (int)s.size())
			{
				int step = 1;
				if (numRows > 1)
				{
					step = odd ? ((numRows - i - 1) * 2) : i * 2;
					odd = !odd;
				}
				int cur = index + step;
				if (cur >= (int)s.size()) break;
				if (index != cur)
				{
					index = cur;
					result += s[cur];
				}
			}
		}
		return result;
	}
};

RUN_TESTCASE(ZigZagConversion)
{
	SolutionZigZagConversion sln;
	TESTCASE_ASSERT(sln.convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
	TESTCASE_ASSERT(sln.convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI");
	TESTCASE_ASSERT(sln.convert("ABCDSD", 1) == "ABCDSD");
	TESTCASE_ASSERT(sln.convert("A", 1) == "A");
}