#include "TestCase.h"
#include <queue>

using namespace std;

class SolutionFindKPairsWithSmallestSums
{
public:
	struct less
	{
		constexpr bool operator()(const pair<int, int>& a, const pair<int, int>& b) const
		{
			return (a.first + a.second) > (b.first + b.second);
		}
	};
	using heap = priority_queue<pair<int, int>, vector<pair<int, int>>, less>;
	vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		heap h;
		for (auto i : nums1)
		{
			for (auto j : nums2)
			{
				h.push(std::make_pair(i, j));
			}
		}
		vector<vector<int>> ret;
		while (k-- > 0 && h.size() > 0)
		{
			const pair<int, int>& item = h.top();
			ret.push_back(vector<int>({ item.first, item.second }));
			h.pop();
		}
		return ret;
	}
};

RUN_TESTCASE(FindKPairsWithSmallestSums)
{
	SolutionFindKPairsWithSmallestSums sln;

	vector<int> nums1_a = { 1,7,11 };
	vector<int> nums1_b = { 2,4,6 };
	vector<vector<int>> ret1 = { {1,2},{1,4},{1,6} };
	TESTCASE_ASSERT(sln.kSmallestPairs(nums1_a, nums1_b, 3) == ret1);

	vector<int> nums2_a = { 1,1,2 };
	vector<int> nums2_b = { 1,2,3 };
	vector<vector<int>> ret2 = { {1,1},{1,1} };
	TESTCASE_ASSERT(sln.kSmallestPairs(nums2_a, nums2_b, 2) == ret2);

	vector<int> nums3_a = { 1,2 };
	vector<int> nums3_b = { 3 };
	vector<vector<int>> ret3 = { {1,3},{2,3} };
	TESTCASE_ASSERT(sln.kSmallestPairs(nums3_a, nums3_b, 3) == ret3);
}