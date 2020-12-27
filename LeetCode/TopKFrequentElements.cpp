#include "TestCase.h"
#include <unordered_map>

using namespace std;

class SolutionTopKFrequentElements
{
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> m1;
		for (int n : nums)
			m1[n]++;

		auto func = [&m1](int a, int b)->bool {
			return m1[a] > m1[b];
		};

		vector<int> h;
		for (auto& p : m1)
		{
			h.push_back(p.first);
			std::push_heap(h.begin(), h.end(), func);

			if (h.size() > k)
			{
				std::pop_heap(h.begin(), h.end(), func);
				h.pop_back();
			}
		}

		vector<int> ret;
		while (k-- > 0)
		{
			std::pop_heap(h.begin(), h.end(), func);
			ret.push_back(h.back());
			h.pop_back();
		}

		return ret;
	}
};

RUN_TESTCASE(TopKFrequentElements)
{
	SolutionTopKFrequentElements sln;

	vector<int> arr1 = { 4,1,-1,2,-1,2,3 };
	vector<int> ret1 = { -1,2 };
    vector<int> ans1 = sln.topKFrequent(arr1, 2);
	TESTCASE_ASSERT(vectorComboEqual(ans1, ret1));

	vector<int> arr2 = { 1,1,1,2,2,3 };
	vector<int> ret2 = { 1,2 };
    vector<int> ans2 = sln.topKFrequent(arr2, 2);
	TESTCASE_ASSERT(vectorComboEqual(ans2, ret2));
}
