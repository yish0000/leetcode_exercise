#include "TestCase.h"

using namespace std;

class SolutionValidAnagram
{
public:
	bool isAnagram(string s, string t) {
		if (s.size() != t.size())
			return false;

		int cnt[26] = {0};
		for (int i = 0; i < s.size(); i++)
		{
			++cnt[s[i] - 'a'];
			--cnt[t[i] - 'a'];
		}

		for (int i = 0; i < 26; i++)
		{
			if (cnt[i] != 0)
				return false;
		}

		return true;
	}
};

RUN_TESTCASE(ValidAnagram)
{
	SolutionValidAnagram sln;
	TESTCASE_ASSERT(sln.isAnagram("anagram", "nagaram"));
	TESTCASE_ASSERT(!sln.isAnagram("rat", "car"));
}