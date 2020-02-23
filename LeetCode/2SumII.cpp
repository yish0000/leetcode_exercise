#include "TestCase.h"
#include <unordered_map>

using namespace std;

class SolutionTwoSumII
{
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		vector<int> ret;
		for (int i = 0; i < (int)numbers.size(); i++)
		{
			if (numbers[i] > target)
				break;

			int n = target - numbers[i];
			int l = i + 1, r = (int)numbers.size() - 1;
			while (l <= r)
			{
				int mid = l + (r - l) / 2;
				if (numbers[mid] == n)
				{
					ret.push_back(i + 1);
					ret.push_back(mid + 1);
					return ret;
				}
				else if (numbers[mid] < n)
					l = mid + 1;
				else
					r = mid - 1;
			}
		}
		return ret;
	}
};

RUN_TESTCASE(TwoSumII)
{
	SolutionTwoSumII sln;

	vector<int> arr1 = { 2,7,11,15 };
	vector<int> ret1 = { 1,2 };
	TESTCASE_ASSERT(sln.twoSum(arr1, 9) == ret1);

	vector<int> arr2 = { 2,3,4 };
	vector<int> ret2 = { 1,3 };
	TESTCASE_ASSERT(sln.twoSum(arr2, 6) == ret2);
}