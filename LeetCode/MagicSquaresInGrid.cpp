#include "TestCase.h"

using namespace std;

class SolutionSquaresInGrid
{
public:
	int numMagicSquaresInside(vector<vector<int>>& grid) {
		if (grid.size() < 3 || grid[0].size() < 3)
			return 0;

		int count = 0;
		vector<int> arr(9, 0);
		for (int i = 0; i < (int)grid.size() - 2; i++)
		{
			for (int j = 0; j < (int)grid[0].size() - 2; j++)
			{
				arr[0] = grid[i][j];
				arr[1] = grid[i][j + 1];
				arr[2] = grid[i][j + 2];
				arr[3] = grid[i + 1][j];
				arr[4] = grid[i + 1][j + 1];
				arr[5] = grid[i + 1][j + 2];
				arr[6] = grid[i + 2][j];
				arr[7] = grid[i + 2][j + 1];
				arr[8] = grid[i + 2][j + 2];
				if (is_magic(arr))
					++count;
			}
		}

		return count;
	}

	bool is_magic(vector<int>& sub_grid)
	{
		if (sub_grid[4] != 5) return false;

		bool existed[9] = { false };
		for (auto v : sub_grid)
		{
			if (v < 1 || v > 9) return false;
			if (existed[v - 1]) return false;
			existed[v - 1] = true;
		}

		return (
			(sub_grid[0] + sub_grid[1] + sub_grid[2]) == 15 &&
			(sub_grid[3] + sub_grid[4] + sub_grid[5]) == 15 &&
			(sub_grid[6] + sub_grid[7] + sub_grid[8]) == 15 &&
			(sub_grid[0] + sub_grid[3] + sub_grid[6]) == 15 &&
			(sub_grid[1] + sub_grid[4] + sub_grid[7]) == 15 &&
			(sub_grid[2] + sub_grid[5] + sub_grid[8]) == 15 &&
			(sub_grid[0] + sub_grid[4] + sub_grid[8]) == 15 &&
			(sub_grid[2] + sub_grid[4] + sub_grid[6]) == 15
			);
	}
};

RUN_TESTCASE(SquaresInGrid)
{
	SolutionSquaresInGrid sln;

	vector<vector<int>> m1 = {
		{4,3,8,4},
		{9,5,1,9},
		{2,7,6,2},
	};
	TESTCASE_ASSERT(sln.numMagicSquaresInside(m1) == 1);
}