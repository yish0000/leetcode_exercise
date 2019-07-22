#include "TestCase.h"

using namespace std;

class SolutionLetterCombinations
{
public:
	const vector<vector<char>> number_to_char = {
		{}, {},
		{'a', 'b', 'c'},
		{'d', 'e', 'f'},
		{'g', 'h', 'i'},
		{'j', 'k', 'l'},
		{'m', 'n', 'o'},
		{'p', 'q', 'r', 's'},
		{'t', 'u', 'v'},
		{'w', 'x', 'y', 'z'},
	};

	vector<string> letterCombinations(string digits) {
		vector<string> res;
		for (string::const_iterator it = digits.begin(); it != digits.end(); ++it)
		{
			const vector<char> chs = number_to_char[(*it) - '0'];
			if (res.empty())
			{
				for (vector<char>::const_iterator it2 = chs.begin(); it2 != chs.end(); ++it2)
					res.push_back(string(1, *it2));
			}
			else
			{
				size_t count = res.size();
				for (size_t i=0; i<count; i++)
				{
					string str = res[i];
					for (size_t j = 0; j < chs.size(); j++)
					{
						if (j == 0)
							res[i] += chs[j];
						else
							res.push_back(str + chs[j]);
					}
				}
			}
		}
		return res;
	}
};

RUN_TESTCASE(LetterCombinations)
{
	SolutionLetterCombinations sln;
	vector<string> res = { "ad", "bd", "cd", "ae", "af", "be", "bf", "ce", "cf" };
	TESTCASE_ASSERT(sln.letterCombinations("23") == res);
}