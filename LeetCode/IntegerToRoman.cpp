#include "TestCase.h"

using namespace std;

class SolutionIntegerToRoman
{
public:
	string intToRoman(int num) {
		string result;
		while (num > 0)
		{
			if (num >= 1000)
			{
				int M = num / 1000;
				for (int i = 0; i < M; i++)
					result += "M";
				num = num % 1000;
			}
			else if (num >= 900)
			{
				result += "CM";
				num -= 900;
			}
			else if (num >= 500)
			{
				result += "D";
				num -= 500;
			}
			else if (num >= 400)
			{
				result += "CD";
				num -= 400;
			}
			else if (num >= 100)
			{
				int C = num / 100;
				for (int i = 0; i < C; i++)
					result += "C";
				num = num % 100;
			}
			else if (num >= 90)
			{
				result += "XC";
				num -= 90;
			}
			else if (num >= 50)
			{
				result += "L";
				num -= 50;
			}
			else if (num >= 40)
			{
				result += "XL";
				num -= 40;
			}
			else if (num >= 10)
			{
				int X = num / 10;
				for (int i = 0; i < X; i++)
					result += "X";
				num = num % 10;
			}
			else if (num >= 9)
			{
				result += "IX";
				num -= 9;
			}
			else if (num >= 5)
			{
				result += "V";
				num -= 5;
			}
			else if (num == 4)
			{
				result += "IV";
				num -= 4;
			}
			else
			{
				for (int i = 0; i < num; i++)
					result += "I";
				num = 0;
			}
		}
		return result;
	}
};

RUN_TESTCASE(IntegerToRoman)
{
	SolutionIntegerToRoman sln;
	TESTCASE_ASSERT(sln.intToRoman(3) == "III");
	TESTCASE_ASSERT(sln.intToRoman(4) == "IV");
	TESTCASE_ASSERT(sln.intToRoman(9) == "IX");
	TESTCASE_ASSERT(sln.intToRoman(58) == "LVIII");
	TESTCASE_ASSERT(sln.intToRoman(1994) == "MCMXCIV");
	TESTCASE_ASSERT(sln.intToRoman(2874) == "MMDCCCLXXIV");
}