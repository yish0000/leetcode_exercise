#include "TestCase.h"

using namespace std;

class SolutionCandy
{
public:
	int candy(vector<int>& ratings) {
		int down = 0;
		int cur = 1;
		int count = 1;
		for (int i = 1; i < ratings.size(); i++)
		{
			if (ratings[i] < ratings[i - 1])
			{
				cur--;
				count += cur;
				down++;
			}
			else
			{
				if (down > 0)
				{
					if (cur > 1)
						count -= (cur - 1) * down;
					else if (cur < 1)
						count += (1 - cur) * (down + 1);

					cur = 1;
					down = 0;
				}

				if (ratings[i] > ratings[i - 1])
				{
					cur++;
					count += cur;
				}
				else
				{
					cur = 1;
					count += cur;
				}
			}
		}

		if (down > 0)
		{
			if (cur > 1)
				count -= (cur - 1) * down;
			else if (cur < 1)
				count += (1 - cur) * (down + 1);
		}

		return count;
	}
};

RUN_TESTCASE(Candy)
{
	SolutionCandy sln;

	vector<int> arr1 = { 1,0,2 };
	TESTCASE_ASSERT(sln.candy(arr1) == 5);

	vector<int> arr2 = {1,2,2};
	TESTCASE_ASSERT(sln.candy(arr2) == 4);

	vector<int> arr6 = { 3,2,1 };
	TESTCASE_ASSERT(sln.candy(arr6) == 6);

	vector<int> arr3 = { 1,3,2,2,1 };
	TESTCASE_ASSERT(sln.candy(arr3) == 7);

	vector<int> arr4 = { 1,2,87,87,87,2,1 };
	TESTCASE_ASSERT(sln.candy(arr4) == 13);

	vector<int> arr5 = { 1,3,4,5,2 };
	TESTCASE_ASSERT(sln.candy(arr5) == 11);
}