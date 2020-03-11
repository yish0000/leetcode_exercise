#include "TestCase.h"
#include <unordered_map>

using namespace std;

class SolutionContainsDuplicateII
{
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_map<int, vector<int>> h;
		for (int i = 0; i < nums.size(); i++)
			h[nums[i]].push_back(i);
		for (auto& p : h)
		{
			if (p.second.size() < 2)
				continue;
			int min = k;
			for (int i = 1; i < p.second.size(); i++)
			{
				if (abs(p.second[i] - p.second[i - 1]) <= min)
					return true;
			}
		}
		return false;
	}
};

RUN_TESTCASE(ContainsDuplicateII)
{
	SolutionContainsDuplicateII sln;

	vector<int> arr1 = { 1,2,3,1 };
	TESTCASE_ASSERT(sln.containsNearbyDuplicate(arr1, 3));

	vector<int> arr2 = { 1,0,1,1 };
	TESTCASE_ASSERT(sln.containsNearbyDuplicate(arr2, 1));

	vector<int> arr3 = { 1,2,3,1,2,3 };
	TESTCASE_ASSERT(!sln.containsNearbyDuplicate(arr3, 2));
}