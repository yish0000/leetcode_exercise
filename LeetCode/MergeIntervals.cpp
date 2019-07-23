#include "TestCase.h"

using namespace std;

class SolutionMergeIntervals
{
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		std::sort(intervals.begin(), intervals.end(), [] (const vector<int>& a, const vector<int>& b)
		{
			return a[0] < b[0];
		});

		vector<vector<int>> res;
		vector<vector<int>>::iterator it = intervals.begin();
		for (; it != intervals.end(); ++it)
		{
			if (res.empty())
				res.emplace_back(*it);
			else
			{
				vector<int>& last = res.back();
				if ((*it)[0] > last[1])
					res.emplace_back(*it);
				else
				{
					if ((*it)[1] > last[1])
						last[1] = (*it)[1];
				}
			}
		}

		return res;
	}
};

RUN_TESTCASE(MergeIntervals)
{
	SolutionMergeIntervals sln;

	vector<vector<int>> arr1 = {
		{1, 3}, { 2, 6}, { 8, 10 }, { 15, 18 }
	};
	vector<vector<int>> res1 = {
		{1,6}, {8,10}, {15,18},
	};
	TESTCASE_ASSERT(sln.merge(arr1) == res1);

	vector<vector<int>> arr2 = { {1,4}, {4,5} };
	vector<vector<int>> res2 = { {1,5} };
	TESTCASE_ASSERT(sln.merge(arr2) == res2);
}