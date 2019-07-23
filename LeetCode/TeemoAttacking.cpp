#include "TestCase.h"

using namespace std;

class SolutionTeemoAttacking
{
public:
	int findPoisonedDuration(vector<int>& timeSeries, int duration) {
		int cur_end = 0;
		int last = 0;
		for (size_t i = 0; i < timeSeries.size(); i++)
		{
			if (timeSeries[i] < cur_end)
			{
				last += (timeSeries[i] + duration - cur_end);
				cur_end = timeSeries[i] + duration;
			}
			else
			{
				last += duration;
				cur_end = timeSeries[i] + duration;
			}
		}
		return last;
	}
};

RUN_TESTCASE(TeemoAttacking)
{
	SolutionTeemoAttacking sln;
	vector<int> arr1 = {1,4};
	TESTCASE_ASSERT(sln.findPoisonedDuration(arr1, 2) == 4);
	vector<int> arr2 = {1,2};
	TESTCASE_ASSERT(sln.findPoisonedDuration(arr2, 2) == 3);
}