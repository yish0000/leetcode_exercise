#include "TestCase.h"

using namespace std;

class SolutionFirstBadVersion
{
public:
	int firstBadVersion(int n) {
		int l = 1, r = n;
		while (l < r)
		{
			int mid = l + (r - l) / 2;
			if (!isBadVersion(mid))
				l = mid + 1;
			else
			{
				if (!isBadVersion(mid - 1))
					return mid;
				r = mid - 1;
			}
		}
		return l;
	}

	int bad_version = 0;
	bool isBadVersion(int version)
	{
		return version >= bad_version;
	}
};

RUN_TESTCASE(FirstBadVersion)
{
	SolutionFirstBadVersion sln;

	sln.bad_version = 4;
	TESTCASE_ASSERT(sln.firstBadVersion(5) == 4);
	TESTCASE_ASSERT(sln.firstBadVersion(15) == 4);
}