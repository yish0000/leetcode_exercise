#include "TestCase.h"

using namespace std;

class SolutionGameOfLife
{
public:
#define GETL(n) ((n) & 0xffff)
#define SETH(n, v) ((n) |= ((v) << 16))

	void gameOfLife(vector<vector<int>>& board) {
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[i].size(); j++)
			{
				SETH(board[i][j], checkDead(board, i, j) ? 1 : 0);
			}
		}
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[i].size(); j++)
			{
				board[i][j] >>= 16;
			}
		}
	}

	const int dir[8][2] = {
		{-1,0},
		{1,0},
		{0,1},
		{0,-1},
		{-1,-1},
		{1,-1},
		{1,1},
		{-1,1}
	};
	bool checkDead(vector<vector<int>>& board, int x, int y)
	{
		if (x < 0 || x >= board.size() || y < 0 || y >= board[x].size())
			return false;

		int count = 0;
		for (int i = 0; i < 8; i++)
		{
			int new_x = x + dir[i][0];
			int new_y = y + dir[i][1];
			if (new_x < 0 || new_x >= board.size() || new_y < 0 || new_y >= board[new_x].size())
				continue;
			if (GETL(board[new_x][new_y]) == 1)
				++count;
		}
		if (GETL(board[x][y]) == 1)
		{
			if (count < 2)
				return false;
			else if (count == 2 || count == 3)
				return true;
			else
				return false;
		}
		else
		{
			return count == 3;
		}
	}
};

RUN_TESTCASE(GameOfLife)
{
	SolutionGameOfLife sln;

	vector<vector<int>> arr1 = {
		{0,1,0},
		{0,0,1},
		{1,1,1},
		{0,0,0},
	};
	vector<vector<int>> ret1 = {
		{0,0,0},
		{1,0,1},
		{0,1,1},
		{0,1,0},
	};
	sln.gameOfLife(arr1);
	TESTCASE_ASSERT(arr1 == ret1);
}