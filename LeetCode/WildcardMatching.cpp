#include "TestCase.h"
#include <string>
#include <iostream>

using namespace std;

#define USE_CPP 1

class SolutionWildcardMatching {
public:
	bool isMatch(string s, string p) {
#if USE_CPP == 0
		const char* Input = s.c_str();
		const char* Pattern = p.c_str();
		const char* pp = Pattern;
		const char* pinput = nullptr;

		while (*Input != '\0')
		{
			if (*Pattern == '*')
			{
				if (*(++Pattern) == '\0')
					return true;

				pp = Pattern;
				pinput = Input + 1;
			}
			else if ((*Pattern == '?') || (*Pattern == *Input))
			{
				Pattern++;
				Input++;
			}
			else if (pinput == nullptr)
				return false;
			else
			{
				Pattern = pp;
				Input = pinput++;
			}
		}

		while (*Pattern == '*')
			Pattern++;

		if (*Pattern == '\0')
			return true;

		return false;
#else
		string::const_iterator itS = s.begin();
		string::const_iterator itP = p.begin();
		string::const_iterator lastItP = p.end();
		string::const_iterator lastItS = p.end();

		while (itS != s.end())
		{
			if (itP != p.end() && *itP == '*')
			{
				if (++itP == p.end())
					return true;

				lastItP = itP;
				lastItS = itS + 1;
			}
			else if (itP != p.end() && (*itP == '?' || *itP == *itS))
			{
				itP++;
				itS++;
			}
			else if (lastItP == p.end())
				return false;
			else
			{
				itP = lastItP;
				if (lastItS == s.end())
					itS = lastItS;
				else
					itS = lastItS++;
			}
		}

		while (itP != p.end() && *itP == '*')
			++itP;

		if (itP == p.end())
			return true;

		return false;
#endif
	}
};

RUN_TESTCASE(WildcardMatching)
{
	SolutionWildcardMatching sln;
	TESTCASE_ASSERT(!sln.isMatch("aa", "a"));
	TESTCASE_ASSERT(sln.isMatch("aa", "*"));
	TESTCASE_ASSERT(!sln.isMatch("cb", "?a"));
	TESTCASE_ASSERT(sln.isMatch("adceb", "*a*b"));
	TESTCASE_ASSERT(!sln.isMatch("acdcb", "a*c?b"));
	TESTCASE_ASSERT(sln.isMatch("Hello, world!", "*o*d!"));
	TESTCASE_ASSERT(!sln.isMatch("Hello, world!", "*o*d"));
	TESTCASE_ASSERT(sln.isMatch("Hello, world!", "*o??*ld!***"));
	TESTCASE_ASSERT(sln.isMatch("Hello, asdf,o,x,asdf,world!", "*o,x*d!"));
	TESTCASE_ASSERT(sln.isMatch("Hello, world!", "**o??*?*ld!**"));
	TESTCASE_ASSERT(sln.isMatch("ccaa00aab", "*ab"));
	TESTCASE_ASSERT(sln.isMatch("sdfazxczxcvadasdd", "*d"));
	TESTCASE_ASSERT(sln.isMatch("aaaa", "*?a*"));
	TESTCASE_ASSERT(sln.isMatch("aaaa", "*??*"));
	TESTCASE_ASSERT(sln.isMatch("hasdfasdfasdf", "*??*"));
	TESTCASE_ASSERT(sln.isMatch("hasdfasdfasdf", "??*"));
	TESTCASE_ASSERT(sln.isMatch("hasdfasdfasdf", "*??"));
	TESTCASE_ASSERT(sln.isMatch("hasdfasdfasdf", "*?*d?"));
	TESTCASE_ASSERT(sln.isMatch("hasdfasdfasdf", "*?*d?asdf"));
	TESTCASE_ASSERT(sln.isMatch("cabdddab", "*ab"));
	TESTCASE_ASSERT(sln.isMatch("hasdfasdfasdf", "*as*d?asdf"));
	TESTCASE_ASSERT(sln.isMatch("aaaa", "***a"));
	TESTCASE_ASSERT(sln.isMatch("mississippi", "m*issip*"));
	TESTCASE_ASSERT(sln.isMatch("mississippi", "m*issip*i"));
	TESTCASE_ASSERT(sln.isMatch("abcd", "ab*cd"));
}
