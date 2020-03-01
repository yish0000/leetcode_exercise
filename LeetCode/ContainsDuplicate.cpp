#include "TestCase.h"
#include <unordered_set>

using namespace std;

class SolutionContainsDuplicate
{
public:
	bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> s;
		for (int n : nums)
		{
			if (s.find(n) != s.end())
				return true;
			s.insert(n);
		}
		return false;
	}
};

RUN_TESTCASE(ContainsDuplicate)
{
	SolutionContainsDuplicate sln;

	vector<int> arr1 = { 1,2,3,1 };
	TESTCASE_ASSERT(sln.containsDuplicate(arr1));

	vector<int> arr2 = { 1,2,3,4 };
	TESTCASE_ASSERT(!sln.containsDuplicate(arr2));

	vector<int> arr3 = { 1,1,1,3,3,4,3,2,4,2 };
	TESTCASE_ASSERT(sln.containsDuplicate(arr3));
}