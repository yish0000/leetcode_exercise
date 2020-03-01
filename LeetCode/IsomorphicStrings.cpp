#include "TestCase.h"
#include <unordered_map>

using namespace std;

class SolutionIsomorphicString
{
public:
	bool isIsomorphic(string s, string t) {
		return helper(s, t) && helper(t, s);
	}

	bool helper(string& s, string& t)
	{
		unordered_map<char, char> h;
		for (size_t i = 0; i < s.size(); i++)
		{
			unordered_map<char, char>::const_iterator it = h.find(s[i]);
			if (it != h.end())
			{
				if (it->second != t[i])
					return false;
			}
			else
			{
				h[s[i]] = t[i];
			}
		}
		return true;
	}
};

RUN_TESTCASE(IsomorphicString)
{
	SolutionIsomorphicString sln;
	TESTCASE_ASSERT(sln.isIsomorphic("egg", "add"));
	TESTCASE_ASSERT(!sln.isIsomorphic("foo", "bar"));
	TESTCASE_ASSERT(sln.isIsomorphic("paper", "title"));
	TESTCASE_ASSERT(!sln.isIsomorphic("ab", "aa"));
}