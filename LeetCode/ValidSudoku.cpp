#include "TestCase.h"

using namespace std;

class SolutionValidSudoku
{
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		bool ss[9] = { false };

		// Horizontal
		for (size_t i = 0; i < 9; i++)
		{
			memset(ss, 0, sizeof(ss));
			for (size_t j = 0; j < 9; j++)
			{
				if (board[i][j] == '.') continue;
				int idx = (board[i][j] - '1');
				if (ss[idx])
					return false;
				ss[idx] = true;
			}
		}

		// Vertical
		for (size_t j = 0; j < 9; j++)
		{
			memset(ss, 0, sizeof(ss));
			for (size_t i = 0; i < 9; i++)
			{
				if (board[i][j] == '.') continue;
				int idx = (board[i][j] - '1');
				if (ss[idx])
					return false;
				ss[idx] = true;
			}
		}

		// Nine
		for (size_t i = 0; i < 9; i++)
		{
			memset(ss, 0, sizeof(ss));
			for (size_t j = 0; j < 9; j++)
			{
				int x = (i % 3) * 3 + (j % 3);
				int y = (i / 3) * 3 + (j / 3);
				if (board[x][y] == '.') continue;
				int idx = (board[x][y] - '1');
				if (ss[idx])
					return false;
				ss[idx] = true;
			}
		}

		return true;
	}
};

RUN_TESTCASE(ValidSudoku)
{
	vector<vector<char>> g1 = {
		{'5','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'},
	};

	vector<vector<char>> g2 = {
		{'8','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'},
	};

	SolutionValidSudoku sln;
	TESTCASE_ASSERT(sln.isValidSudoku(g1));
	TESTCASE_ASSERT(!sln.isValidSudoku(g2));
}