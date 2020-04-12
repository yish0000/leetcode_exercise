#include "TestCase.h"

using namespace std;

class SolutionMaximumSwap
{
public:
	int maximumSwap(int num) {
		vector<int> arr;
		while (num > 0)
		{
			arr.push_back(num % 10);
			num /= 10;
		}

		for (int i = (int)arr.size() - 1; i >= 1; i--)
		{
			if (arr[i] == 9) continue;

			int max_index = i - 1;
			int max_val = arr[max_index];
			for (int j = i - 2; j >= 0; j--)
			{
				if (arr[j] >= max_val)
				{
					max_val = arr[j];
					max_index = j;
				}
			}

			if (max_val > arr[i])
			{
				std::swap(arr[i], arr[max_index]);
				break;
			}
		}

		for (int i = (int)arr.size() - 1; i >= 0; i--)
			num = num * 10 + arr[i];
		return num;
	}
};

RUN_TESTCASE(MaximumSwap)
{
	SolutionMaximumSwap sln;
	TESTCASE_ASSERT(sln.maximumSwap(2736) == 7236);
	TESTCASE_ASSERT(sln.maximumSwap(9973) == 9973);
	TESTCASE_ASSERT(sln.maximumSwap(9) == 9);
	TESTCASE_ASSERT(sln.maximumSwap(1993) == 9913);
}