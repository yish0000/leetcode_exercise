#include "TestCase.h"

using namespace std;

class SolutionSolveSudoku
{
public:
	void solveSudoku(vector<vector<char>>& board)
	{
		foundOneResult = false;
		solveSudokuBacktrack(board, 1, 0);
	}

protected:
	bool foundOneResult = false;
	bool solveSudokuBacktrack(vector<vector<char>>& board, int num, int g) {
		if (foundOneResult)
			return true;

		if (num > 9)
		{
			foundOneResult = true;
			printResult(board);
			return true;
		}

		bool isOK = false;
		for (int i = 0; i < 9; i++)
		{
			int x = (g % 3) * 3 + (i % 3);
			int y = (g / 3) * 3 + (i / 3);

			if (board[y][x] == ('0' + num))
				return (g + 1 > 8) ? solveSudokuBacktrack(board, num + 1, 0) : solveSudokuBacktrack(board, num, g + 1);
			else if (board[y][x] == '.')
			{
				if (checkValid(board, x, y, num))
				{
					board[y][x] = '0' + num;
					bool ok = (g + 1 > 8) ? solveSudokuBacktrack(board, num + 1, 0) : solveSudokuBacktrack(board, num, g + 1);
					if (!ok)
						board[y][x] = '.';
					else
					{
						isOK = true;
						break;
					}
				}
			}
		}

		return isOK;
	}

	bool checkValid(vector<vector<char>>& board, int x, int y, int num)
	{
		for (int i = 0; i < 9; i++)
		{
			// Horizontal
			if (board[y][i] == ('0' + num) && i != x)
				return false;

			// Vertical
			if (board[i][x] == ('0' + num) && i != y)
				return false;
		}

		return true;
	}

	void printResult(vector<vector<char>>& board)
	{
		for (size_t i = 0; i < board.size(); i++)
		{
			for (size_t j = 0; j < board.size(); j++)
			{
				std::cout << board[i][j] << ' ';
			}

			std::cout << std::endl;
		}

		std::cout << std::endl;
	}

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

RUN_TESTCASE(SolveSudoku)
{
	vector<vector<char>> chess = {
		{ '5', '3', '.', '.', '7', '.', '.', '.', '.' },
		{ '6', '.', '.', '1', '9', '5', '.', '.', '.' },
		{ '.', '9', '8', '.', '.', '.', '.', '6', '.' },
		{ '8', '.', '.', '.', '6', '.', '.', '.', '3' },
		{ '4', '.', '.', '8', '.', '3', '.', '.', '1' },
		{ '7', '.', '.', '.', '2', '.', '.', '.', '6' },
		{ '.', '6', '.', '.', '.', '.', '2', '8', '.' },
		{ '.', '.', '.', '4', '1', '9', '.', '.', '5' },
		{ '.', '.', '.', '.', '8', '.', '.', '7', '9' },
	};

	SolutionSolveSudoku sln;
	sln.solveSudoku(chess);

	vector<vector<char>> chess_empty = {
		{ '.', '.', '.', '.', '.', '.', '.', '.', '.' },
		{ '.', '.', '.', '.', '.', '.', '.', '.', '.' },
		{ '.', '.', '.', '.', '.', '.', '.', '.', '.' },
		{ '.', '.', '.', '.', '.', '.', '.', '.', '.' },
		{ '.', '.', '.', '.', '.', '.', '.', '.', '.' },
		{ '.', '.', '.', '.', '.', '.', '.', '.', '.' },
		{ '.', '.', '.', '.', '.', '.', '.', '.', '.' },
		{ '.', '.', '.', '.', '.', '.', '.', '.', '.' },
		{ '.', '.', '.', '.', '.', '.', '.', '.', '.' },
	};
	sln.solveSudoku(chess_empty);

	TESTCASE_ASSERT(sln.isValidSudoku(chess_empty));
	TESTCASE_ASSERT(sln.isValidSudoku(chess));
}