#include "TestCase.h"
#include <stack>

using namespace std;

class SolutionSimplifyPath
{
public:
	string simplifyPath(string path) {
		vector<string> s;
		string::const_iterator beg = path.begin();
		string::const_iterator cur = beg;
		while (cur != path.end())
		{
			bool isLast = cur + 1 == path.end();
			if (*cur == '/' || isLast)
			{
				if (cur > beg || isLast)
				{
					string curPath(beg, (isLast && *cur != '/') ? path.end() : cur);
					if (curPath.size() > 0)
					{
						if (curPath == "..")
						{
							if (s.size() > 0)
								s.pop_back();
						}
						else if (curPath != "." && curPath != "/")
						{
							s.push_back(curPath);
						}
					}
				}

				beg = cur + 1;
				cur = beg;
			}
			else
				++cur;
		}

		string realPath("/");
		for (size_t i=0; i<s.size(); i++)
		{
			realPath += s[i];
			if (i < s.size() - 1)
				realPath += "/";
		}

		return realPath;
	}
};

RUN_TESTCASE(SimplifyPath)
{
	SolutionSimplifyPath sln;
	TESTCASE_ASSERT(sln.simplifyPath("/home/") == "/home");
	TESTCASE_ASSERT(sln.simplifyPath("/../") == "/");
	TESTCASE_ASSERT(sln.simplifyPath("/home//foo/") == "/home/foo");
	TESTCASE_ASSERT(sln.simplifyPath("/a/./b/../../c/") == "/c");
	TESTCASE_ASSERT(sln.simplifyPath("/a/../../b/../c//.//") == "/c");
	TESTCASE_ASSERT(sln.simplifyPath("/a//b////c/d//././/..") == "/a/b/c");
	TESTCASE_ASSERT(sln.simplifyPath("/.././GVzvE/./xBjU///../..///././//////T/../../.././zu/q/e") == "/zu/q/e");
}