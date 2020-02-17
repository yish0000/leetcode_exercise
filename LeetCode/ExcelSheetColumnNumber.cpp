#include "TestCase.h"

using namespace std;

class SolutionExcelSheetColumnNumber
{
public:
	int titleToNumber(string s) {
		int number = 0;
		int n = 1;
		for (int i = (int)s.length() - 1; i >= 0; i--)
		{
			number += (s[i] - 'A' + 1) * n;
			if (i > 0) n *= 26;
		}
		return number;
	}
};

RUN_TESTCASE(ExcelSheetColumnNumber)
{
	SolutionExcelSheetColumnNumber sln;

	TESTCASE_ASSERT(sln.titleToNumber("A") == 1);
	TESTCASE_ASSERT(sln.titleToNumber("AB") == 28);
	TESTCASE_ASSERT(sln.titleToNumber("ZY") == 701);
}