#include "TestCase.h"
#include <queue>

using namespace std;

class SolutionCourseScheduleII
{
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int>> g(numCourses);
		for (auto& preq : prerequisites)
			g[preq[0]].push_back(preq[1]);

		vector<int> indegree(numCourses);
		for (int i = 0; i < g.size(); i++)
		{
			for (int j = 0; j < g[i].size(); j++)
			{
				++indegree[g[i][j]];
			}
		}

		vector<int> order;

		queue<int> q;
		for (int i = 0; i < indegree.size(); i++)
		{
			if (indegree[i] == 0)
				q.push(i);
		}

		int visited_vertices = 0;
		while (q.size() > 0)
		{
			int cur = q.front();
			q.pop();
			++visited_vertices;

			order.push_back(cur);

			for (int i = 0; i < g[cur].size(); i++)
			{
				--indegree[g[cur][i]];

				if (indegree[g[cur][i]] == 0)
					q.push(g[cur][i]);
			}
		}

		if (visited_vertices < numCourses)
			order.clear();
		else
			std::reverse(order.begin(), order.end());
		return order;
	}

	/*
	void dfs(vector<vector<int>>& g, vector<int>& indegree, int u, vector<int>& order)
	{

	}
	*/
};

RUN_TESTCASE(CourseScheduleII)
{
	SolutionCourseScheduleII sln;

	vector<vector<int>> arr1 = {
		{1,0}
	};
	vector<int> ret1 = { 0,1 };
	TESTCASE_ASSERT(sln.findOrder(2, arr1) == ret1);

	vector<vector<int>> arr2 = {
		{1,0},{2,0},{3,1},{3,2}
	};
	vector<int> ret2 = { 0,2,1,3 };
	TESTCASE_ASSERT(sln.findOrder(4, arr2) == ret2);
}