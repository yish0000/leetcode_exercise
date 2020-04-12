#include "TestCase.h"
#include <unordered_set>
#include <queue>

using namespace std;

class SolutionMinimumHeightTrees
{
public:
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		vector<vector<int>> nb;
		nb.resize(n);
		for (auto& edge : edges)
		{
			nb[edge[0]].push_back(edge[1]);
			nb[edge[1]].push_back(edge[0]);
		}

		queue<int> q;
		vector<int> d;
		for (int i = 0; i < n; i++)
		{
			d.push_back((int)nb[i].size());
			if (nb[i].size() == 1)
				q.push(i);
		}

		while (n > 2)
		{
			int layer_size = (int)q.size();
			n -= layer_size;
			for (int i = 0; i < layer_size; i++)
			{
				int cur = q.front();
				q.pop();
				for (auto k : nb[i])
				{
					if (--d[k] == 1)
						q.push(k);
				}
			}
		}

		vector<int> res;
		while (q.size() > 0)
		{
			res.push_back(q.front());
			q.pop();
		}
		return res;
	}
};

RUN_TESTCASE(MinimumHeightTrees)
{
	SolutionMinimumHeightTrees sln;

	vector<vector<int>> arr1 = { {1,0},{1,2},{1,3} };
	vector<int> ret1 = { 1 };
	TESTCASE_ASSERT(sln.findMinHeightTrees(4, arr1) == ret1);

	vector<vector<int>> arr2 = { {0,3},{1,3},{2,3},{4,3},{5,4} };
	vector<int> ret2 = { 3,4 };
	TESTCASE_ASSERT(sln.findMinHeightTrees(6, arr2) == ret2);
}