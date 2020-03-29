#include "TestCase.h"

using namespace std;

class SolutionHIndex
{
public:
	int hIndex(vector<int>& citations) {
		std::sort(citations.begin(), citations.end());

		int res = 0;
		for (int i = (int)citations.size() - 1; i >= 0; i--)
		{
			if (citations[i] > res)
				res++;
			else
				break;
		}
		return res;
	}
};

RUN_TESTCASE(HIndex)
{
	SolutionHIndex sln;

	vector<int> arr1 = { 3,0,6,1,5 };
	TESTCASE_ASSERT(sln.hIndex(arr1) == 3);
}