#include "TestCase.h"

using namespace std;

class SolutionExcelSheetColumnTitle
{
public:
	string convertToTitle(int n) {
		string ret;
		while (n > 0)
		{
			if (n % 26 == 0)
			{
				ret.push_back('Z');
				n = n / 26 - 1;
			}
			else
			{
				if (n > 26)
				{
					ret.push_back((n % 26) - 1 + 'A');
					n /= 26;
				}
				else
				{
					ret.push_back(n - 1 + 'A');
					break;
				}
			}
		}
		std::reverse(ret.begin(), ret.end());
		return ret;
	}
};

RUN_TESTCASE(ExcelSheetColumnTitle)
{
	SolutionExcelSheetColumnTitle sln;
	TESTCASE_ASSERT(sln.convertToTitle(1) == "A");
	TESTCASE_ASSERT(sln.convertToTitle(28) == "AB");
	TESTCASE_ASSERT(sln.convertToTitle(52) == "AZ");
	TESTCASE_ASSERT(sln.convertToTitle(701) == "ZY");
	TESTCASE_ASSERT(sln.convertToTitle(702) == "ZZ");
}