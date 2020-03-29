#include "TestCase.h"
#include <sstream>

using namespace std;

class SolutionSummaryRanges
{
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> out;
		if (nums.empty()) return out;
		int beg = 0;
		for (int i = 1; i < nums.size(); i++)
		{
			if ((int64_t)nums[i] - (int64_t)nums[beg] != i - beg)
			{
				stringstream ss;
				if (i - 1 > beg)
					ss << nums[beg] << "->" << nums[i - 1];
				else
					ss << nums[beg];
				out.push_back(ss.str());
				beg = i;
			}
		}
		stringstream ss;
		if (beg < (int)nums.size() - 1)
			ss << nums[beg] << "->" << nums[(int)nums.size() - 1];
		else
			ss << nums[beg];
		out.push_back(ss.str());
		return out;
	}
};

RUN_TESTCASE(SummaryRanges)
{
	SolutionSummaryRanges sln;

	vector<int> arr1 = { 0,1,2,4,5,7 };
	vector<string> ret1 = { "0->2", "4->5", "7" };
	TESTCASE_ASSERT(sln.summaryRanges(arr1) == ret1);

	vector<int> arr2 = { 0,2,3,4,6,8,9 };
	vector<string> ret2 = { "0", "2->4", "6", "8->9" };
	TESTCASE_ASSERT(sln.summaryRanges(arr2) == ret2);
}