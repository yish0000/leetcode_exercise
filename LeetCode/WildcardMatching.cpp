#include "TestCase.h"
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		string::const_iterator itS = s.begin();
		string::const_iterator itP = p.begin();
		string::const_iterator lastItP = p.end();

		while (itS != s.end() && itP != p.end())
		{
			if (*itP == '*')
			{
				lastItP = itP;
				while(itP != p.end() && *itP == '*')
					itP++;

				if (itP == p.end())
					itS = s.end();
				else
				{
					if (*itP == '?')
						continue;
					else
					{
						while (itS != s.end() && *itS != *itP)
							itS++;
					}
				}
			}
			else if (*itP == '?')
			{
				itS++;
				itP++;
			}
			else
			{
				if (*itS != *itP)
				{
					if (lastItP != p.end())
					{
						// 回溯，尝试让上一个通配符*匹配掉当前的不匹配字符串
						itP = lastItP;
						lastItP = p.end();
					}
					else
						return false;
				}
				else
				{
					itS++;
					itP++;
				}
			}

			if (itP == p.end() && itS != s.end())
			{
				// 通配符结束了，字符串还没结束，尝试回溯一下
				itP = lastItP;
				lastItP = p.end();
			}
		}

		if (itS == s.end() && itP == p.end())
			return true;
		else if (itS == s.end())
		{
			// 忽略掉剩余的*
			for (; itP != p.end(); ++itP)
			{
				if (*itP != '*')
					return false;
			}

			return true;
		}
		
		return false;
	}
};

RUN_TESTCASE(WildcardMatching)
{
	Solution sln;
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
}