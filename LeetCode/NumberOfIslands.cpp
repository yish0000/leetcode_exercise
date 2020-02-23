#include "TestCase.h"
#include <queue>

using namespace std;

class SolutionNumberOfIslands
{
public:
	const int dir[4][2] =
	{
		{0,1},
		{-1,0},
		{0,-1},
		{1,0},
	};

	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty() || grid[0].empty())
			return 0;

		int count = 0;
		vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[i].size(); j++)
			{
				if (visited[i][j])
					continue;
				if (grid[i][j] == '0')
					continue;
				bfs(grid, visited, i, j);
				count++;
			}
		}

		return count;
	}

	void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y)
	{
		queue<pair<int, int>> q;
		q.push(make_pair(x, y));
		visited[x][y] = true;
		while (q.size() > 0)
		{
			pair<int, int> item = q.front();
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int new_x = item.first + dir[i][0];
				int new_y = item.second + dir[i][1];
				if (new_x < 0 || new_x >= grid.size() || new_y < 0 || new_y >= grid[0].size())
					continue;
				if (visited[new_x][new_y])
					continue;
				if (grid[new_x][new_y] == '0')
					continue;
				q.push(make_pair(new_x, new_y));
				visited[new_x][new_y] = true;
			}
		}
	}
};

RUN_TESTCASE(NumberOfIslands)
{
	SolutionNumberOfIslands sln;

	vector<vector<char>> arr1 = {
		{'1','1','1','1','0'},
		{'1','1','0','1','0'},
		{'1','1','0','0','0'},
		{'0','0','0','0','0'},
	};
	TESTCASE_ASSERT(sln.numIslands(arr1) == 1);

	vector<vector<char>> arr2 = {
		{'1','1','0','0','0'},
		{'1','1','0','0','0'},
		{'0','0','1','0','0'},
		{'0','0','0','1','1'},
	};
	TESTCASE_ASSERT(sln.numIslands(arr2) == 3);

	vector<vector<char>> arr3 = {
		{'1','0','1','1','0','1','1'},
	};
	TESTCASE_ASSERT(sln.numIslands(arr3) == 3);
}