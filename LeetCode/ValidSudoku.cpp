#include "TestCase.h"

using namespace std;

class SolutionValidSudoku
{
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		int ss[9] = { 0 };

		// Horizontal
		for (size_t i = 0; i < 9; i++)
		{
			memset(ss, 0, sizeof(ss));

			for (size_t j = 0; j < 9; j++)
			{
				// Horizontal
				if (board[i][j] != '.')
				{
					int idx = (board[i][j] - '1');
					if (ss[idx] & 0x1)
						return false;
					ss[idx] |= 0x1;
				}

				// Vertical
				if (board[j][i] != '.')
				{
					int idx = (board[j][i] - '1');
					if (ss[idx] & 0x2)
						return false;
					ss[idx] |= 0x2;
				}

				// Nine.
				int x = (i % 3) * 3 + (j % 3);
				int y = (i / 3) * 3 + (j / 3);
				if (board[x][y] != '.')
				{
					int idx = (board[x][y] - '1');
					if (ss[idx] & 0x4)
						return false;
					ss[idx] |= 0x4;
				}
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