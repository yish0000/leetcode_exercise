#include "TestCase.h"

using namespace std;

class SolutionReverseVowelsString
{
public:
	string reverseVowels(string s) {
		int cnt = 0;
		string::iterator it1 = s.begin();
		string::iterator it2 = s.end() - 1;
		while (it1 < it2)
		{
			if (is_vowel(*it1) && is_vowel(*it2))
			{
				std::swap(*it1, *it2);
				++it1;
				--it2;
			}
			else if (is_vowel(*it1))
				--it2;
			else if (is_vowel(*it2))
				++it1;
			else
			{
				++it1;
				--it2;
			}
		}
		return s;
	}

	bool is_vowel(char ch)
	{
		return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
			ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
	}
};

RUN_TESTCASE(ReverseVowelsString)
{
	SolutionReverseVowelsString sln;
	TESTCASE_ASSERT(sln.reverseVowels("hello") == "holle");
	TESTCASE_ASSERT(sln.reverseVowels("leetcode") == "leotcede");
}