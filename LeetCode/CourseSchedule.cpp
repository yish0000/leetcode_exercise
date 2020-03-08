#include "TestCase.h"
#include <queue>
#include <unordered_set>

using namespace std;

class SolutionCourseSchedule
{
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int>> g(numCourses);
		for (auto p : prerequisites)
			g[p[0]].push_back(p[1]);

		vector<int> indegree(numCourses, 0);
		for (int i = 0; i < g.size(); i++)
		{
			for (int j = 0; j < g[i].size(); j++)
				++indegree[g[i][j]];
		}

		queue<int> q;
		for (int i=0; i<indegree.size();i++)
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

			for (int i = 0; i < g[cur].size(); i++)
			{
				--indegree[g[cur][i]];

				if (indegree[g[cur][i]] == 0)
					q.push(g[cur][i]);
			}
		}

		return visited_vertices >= numCourses;
	}
};

RUN_TESTCASE(CourseSchedule)
{
	SolutionCourseSchedule sln;

	vector<vector<int>> arr1 = {
		{0,1},{1,2},{2,4},{4,3},
	};
	TESTCASE_ASSERT(sln.canFinish(5, arr1));

	vector<vector<int>> arr2 = {
		{0,1},{1,2},{2,4},{4,3},{3,1}
	};
	TESTCASE_ASSERT(!sln.canFinish(5, arr2));

	vector<vector<int>> arr3 = {
		{2,0},{2,1}
	};
	TESTCASE_ASSERT(sln.canFinish(3, arr3));

	vector<vector<int>> arr4 = {
		{0,1},{0,2},{1,2}
	};
	TESTCASE_ASSERT(sln.canFinish(3, arr4));

	vector<vector<int>> arr5 = {
		{1,0},{2,6},{1,7},{6,4},{7,0},{0,5}
	};
	TESTCASE_ASSERT(sln.canFinish(8, arr5));
}