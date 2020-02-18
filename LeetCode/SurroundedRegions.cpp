#include "TestCase.h"
#include <queue>

using namespace std;

class SolutionSurroundedRegions
{
public:
	const int dir[4][2] =
	{
		{0,1},
		{-1,0},
		{0,-1},
		{1,0},
	};

	void solve(vector<vector<char>>& board) {
		if (board.empty() || board[0].empty())
			return;

		vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[i].size(); j++)
			{
				if (visited[i][j])
					continue;
				if (board[i][j] != 'O')
					continue;
				bfs(board, visited, i, j);
			}
		}
	}

	void bfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int x, int y)
	{
		bool isDead = true;
		vector<char*> active;
		queue<pair<int, int>> q;
		q.push(make_pair(x, y));
		visited[x][y] = true;
		while (q.size() > 0)
		{
			pair<int, int> item = q.front();
			active.push_back(&board[item.first][item.second]);
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int new_x = item.first + dir[i][0];
				int new_y = item.second + dir[i][1];

				if (new_x < 0 || new_x >= board.size() || new_y < 0 || new_y >= board[0].size())
				{
					isDead = false;
					continue;
				}

				if (visited[new_x][new_y])
					continue;

				if (board[new_x][new_y] == 'X')
					continue;

				q.push(make_pair(new_x, new_y));
				visited[new_x][new_y] = true;
			}
		}

		if (isDead)
		{
			for (auto ptr : active)
				*ptr = 'X';
		}
	}
};

RUN_TESTCASE(SurroundedRegions)
{
	SolutionSurroundedRegions sln;

	vector<vector<char>> arr1 = {
		{'X','X','X','X'},
		{'X','O','O','X'},
		{'X','X','O','X'},
		{'X','O','X','X'},
	};
	vector<vector<char>> ret1 = {
		{'X','X','X','X'},
		{'X','X','X','X'},
		{'X','X','X','X'},
		{'X','O','X','X'},
	};
	sln.solve(arr1);
	TESTCASE_ASSERT(arr1 == ret1);

	vector<vector<char>> arr2 = {
		{'O','O','O','O','X','X'},
		{'O','O','O','O','O','O'},
		{'O','X','O','X','O','O'},
		{'O','X','O','O','X','O'},
		{'O','X','O','X','O','O'},
		{'O','X','O','O','O','O'},
	};
	vector<vector<char>> ret2 = {
		{'O','O','O','O','X','X'},
		{'O','O','O','O','O','O'},
		{'O','X','O','X','O','O'},
		{'O','X','O','O','X','O'},
		{'O','X','O','X','O','O'},
		{'O','X','O','O','O','O'},
	};
	sln.solve(arr2);
	TESTCASE_ASSERT(arr2 == ret2);

	vector<vector<char>> arr3 = {
		{'O','O','O','O','O','O','O','O','X','O','O','O','O','O','X','O','O','O','O','O'},
		{'O','O','O','O','O','O','O','X','O','O','O','O','O','O','O','O','O','O','O','O'},
		{'X','O','O','X','O','X','O','O','O','O','X','O','O','X','O','O','O','O','O','O'},
		{'O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','X','X','O'},
		{'O','X','X','O','O','O','O','O','O','X','O','O','O','O','O','O','O','O','O','O'},
		{'O','O','O','O','X','O','O','O','O','O','O','X','O','O','O','O','O','X','X','O'},
		{'O','O','O','O','O','O','O','X','O','O','O','O','O','O','O','O','O','O','O','O'},
		{'O','O','O','O','O','O','O','O','O','O','O','O','O','X','O','O','O','O','O','O'},
		{'O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','X','O'},
		{'O','O','O','O','O','X','O','O','O','O','O','O','O','O','O','O','O','O','O','O'},
		{'O','O','O','O','O','O','O','O','X','O','O','O','O','O','O','O','O','O','O','O'},
		{'O','O','O','O','X','O','O','O','O','X','O','O','O','O','O','O','O','O','O','O'},
		{'O','O','O','O','O','O','O','O','X','O','O','O','O','O','O','O','O','O','O','O'},
		{'X','O','O','O','O','O','O','O','O','X','X','O','O','O','O','O','O','O','O','O'},
		{'O','O','O','O','O','O','O','O','O','O','O','X','O','O','O','O','O','O','O','O'},
		{'O','O','O','O','X','O','O','O','O','O','O','O','O','X','O','O','O','O','O','X'},
		{'O','O','O','O','O','X','O','O','O','O','O','O','O','O','O','X','O','X','O','O'},
		{'O','X','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O'},
		{'O','O','O','O','O','O','O','O','X','X','O','O','O','X','O','O','X','O','O','X'},
		{'O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O'},
	};
	vector<vector<char>> ret3 = {
		{'O','O','O','O','O','O','O','O','X','O','O','O','O','O','X','O','O','O','O','O'},
		{'O','O','O','O','O','O','O','X','O','O','O','O','O','O','O','O','O','O','O','O'},
		{'X','O','O','X','O','X','O','O','O','O','X','O','O','X','O','O','O','O','O','O'},
		{'O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','X','X','O'},
		{'O','X','X','O','O','O','O','O','O','X','O','O','O','O','O','O','O','O','O','O'},
		{'O','O','O','O','X','O','O','O','O','O','O','X','O','O','O','O','O','X','X','O'},
		{'O','O','O','O','O','O','O','X','O','O','O','O','O','O','O','O','O','O','O','O'},
		{'O','O','O','O','O','O','O','O','O','O','O','O','O','X','O','O','O','O','O','O'},
		{'O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','X','O'},
		{'O','O','O','O','O','X','O','O','O','O','O','O','O','O','O','O','O','O','O','O'},
		{'O','O','O','O','O','O','O','O','X','O','O','O','O','O','O','O','O','O','O','O'},
		{'O','O','O','O','X','O','O','O','O','X','O','O','O','O','O','O','O','O','O','O'},
		{'O','O','O','O','O','O','O','O','X','O','O','O','O','O','O','O','O','O','O','O'},
		{'X','O','O','O','O','O','O','O','O','X','X','O','O','O','O','O','O','O','O','O'},
		{'O','O','O','O','O','O','O','O','O','O','O','X','O','O','O','O','O','O','O','O'},
		{'O','O','O','O','X','O','O','O','O','O','O','O','O','X','O','O','O','O','O','X'},
		{'O','O','O','O','O','X','O','O','O','O','O','O','O','O','O','X','O','X','O','O'},
		{'O','X','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O'},
		{'O','O','O','O','O','O','O','O','X','X','O','O','O','X','O','O','X','O','O','X'},
		{'O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O'},
	};
	sln.solve(arr3);
	TESTCASE_ASSERT(arr3 == ret3);
}