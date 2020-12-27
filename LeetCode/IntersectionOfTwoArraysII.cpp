#include "TestCase.h"
#include <unordered_map>

using namespace std;

class SolutionIntersectionOfTwoArraysII
{
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, pair<short, short>> h;
		for (int i : nums1)
			h[i].first++;
		vector<int> ret;
		for (int i : nums2)
		{
			if (h.find(i) != h.end())
				h[i].second++;
		}
		for (auto& p : h)
		{
			short count = std::min(p.second.first, p.second.second);
			while (count-- > 0) ret.push_back(p.first);
		}
		return ret;
	}
};

RUN_TESTCASE(IntersectionOfTwoArraysII)
{
	SolutionIntersectionOfTwoArraysII sln;

	vector<int> arr1 = { 1,2,2,1 };
	vector<int> arr2 = { 2,2 };
	vector<int> ret1 = { 2,2 };
	TESTCASE_ASSERT(vectorComboEqual(sln.intersect(arr1, arr2), ret1));

	vector<int> arr3 = { 4,9,5 };
	vector<int> arr4 = { 9,4,9,8,4 };
	vector<int> ret2 = { 4,9 };
	TESTCASE_ASSERT(vectorComboEqual(sln.intersect(arr3, arr4), ret2));
}