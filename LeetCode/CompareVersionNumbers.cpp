#include "TestCase.h"

using namespace std;

class SolutionCompareVersionNumbers
{
public:
	int compareVersion(string version1, string version2) {
		vector<int> v1;
		vector<int> v2;
		parseVersion(version1, v1);
		parseVersion(version2, v2);
		int size = (int)std::max(v1.size(), v2.size());
		for (int i = 0; i < size; i++)
		{
			if (i < (int)v1.size() && i < (int)v2.size())
			{
				if (v1[i] != v2[i])
					return v1[i] < v2[i] ? -1 : 1;
			}
			else if (i < (int)v1.size())
			{
				if (v1[i] != 0)
					return 1;
			}
			else
			{
				if (v2[i] != 0)
					return -1;
			}
		}
		return 0;
	}

	void parseVersion(string& version, vector<int>& v)
	{
		string::const_iterator l = version.begin();
		string::const_iterator r = l;
		while (r != version.end())
		{
			if (*r == '.')
			{
				v.push_back(atoi(string(l, r).c_str()));
				++r;
				l = r;
			}
			else
				++r;
		}
		if (r != l)
			v.push_back(atoi(string(l, r).c_str()));
	}
};

RUN_TESTCASE(CompareVersionNumbers)
{
	SolutionCompareVersionNumbers sln;

	TESTCASE_ASSERT(sln.compareVersion("0.1", "1.1") == -1);
	TESTCASE_ASSERT(sln.compareVersion("1.0.1", "1") == 1);
	TESTCASE_ASSERT(sln.compareVersion("7.5.2.4", "7.5.3") == -1);
	TESTCASE_ASSERT(sln.compareVersion("1.01", "1.001") == 0);
	TESTCASE_ASSERT(sln.compareVersion("1.0", "1.0.0") == 0);
}