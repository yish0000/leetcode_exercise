#include "TestCase.h"

using namespace std;

class SolutionShiftingLetters
{
public:
	string shiftingLetters(string S, vector<int>& shifts) {
		for (int i = (int)shifts.size() - 1; i >= 0; i--)
		{
			shifts[i] += (i < (int)shifts.size() - 1) ? shifts[i + 1] : 0;
			shifts[i] %= 26;
			unsigned char ch = S[i];
			ch += shifts[i];
			if (ch > 'z') ch = ch - 'z' + 'a' - 1;
			S[i] = (char)ch;
		}
		return S;
	}
};

RUN_TESTCASE(ShiftingLetters)
{
	SolutionShiftingLetters sln;
	TESTCASE_ASSERT(sln.shiftingLetters("abc", vector<int>{3, 5, 9}) == "rpl");
	TESTCASE_ASSERT(sln.shiftingLetters("ruu", vector<int>{26, 9, 17}) == "rul");
}