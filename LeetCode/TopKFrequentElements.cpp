#include "TestCase.h"
#include <map>

using namespace std;

class SolutionTopKFrequentElements
{
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		map<int, int> m1;
		for (int n : nums)
			m1[n]++;
		map<int, vector<int>, greater<int>> m2;
		for (auto& p : m1)
			m2[p.second].push_back(p.first);
		vector<int> ret;
		map<int, vector<int>, greater<int>>::iterator it = m2.begin();
		while (it != m2.end() && k > 0)
		{
			for (auto n : it->second)
			{
				if (k-- > 0)
					ret.push_back(n);
				else
					break;
			}
			if (k == 0) break;
			++it;
		}
		return ret;
	}
};

RUN_TESTCASE(TopKFrequentElements)
{
	SolutionTopKFrequentElements sln;

	vector<int> arr1 = { 4,1,-1,2,-1,2,3 };
	vector<int> ret1 = { -1,2 };
	TESTCASE_ASSERT(sln.topKFrequent(arr1, 2) == ret1);

	vector<int> arr2 = { 1,1,1,2,2,3 };
	vector<int> ret2 = { 1,2 };
	TESTCASE_ASSERT(sln.topKFrequent(arr2, 2) == ret2);
}