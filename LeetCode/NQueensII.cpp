#include "TestCase.h"

using namespace std;

class SolutionNQueensII
{
public:
	int totalNQueens(int N)
	{
		vector<string> chess(N, string(N, '.'));
		int count = 0;
		findResult(chess, 0, N, count);
		return count;
	}

	void findResult(vector<string>& chess, int row, int N, int& count)
	{
		if (row > N - 1)
		{
			count++;
			return;
		}

		for (int i = 0; i < N; i++)
		{
			if (check(chess, row, i, N))
			{
				chess[row][i] = 'Q';
				findResult(chess, row + 1, N, count);
				chess[row][i] = '.';
			}
		}
	}

	bool check(vector<string>& chess, int row, int col, int N)
	{
		int x1 = row, x2 = row;
		int y1 = col, y2 = col;
		for (int i = 0; i < N; i++)
		{
			if (chess[row][i] == 'Q' && i != col)
				return false;
			if (chess[i][col] == 'Q' && i != row)
				return false;

			--x1; --y1; ++x2; ++y2;
			if (x1 >= 0 && y1 >= 0 && chess[x1][y1] == 'Q')
				return false;
			if (x2 < N && y2 < N && chess[x2][y2] == 'Q')
				return false;
			if (x1 >= 0 && y2 < N && chess[x1][y2] == 'Q')
				return false;
			if (x2 < N && y1 >= 0 && chess[x2][y1] == 'Q')
				return false;
		}
		return true;
	}
};

RUN_TESTCASE(NQueensII)
{
	SolutionNQueensII sln;
	TESTCASE_ASSERT(sln.totalNQueens(4) == 2);
	TESTCASE_ASSERT(sln.totalNQueens(8) == 92);
}
