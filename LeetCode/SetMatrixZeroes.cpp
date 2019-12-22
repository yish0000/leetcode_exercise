#include "TestCase.h"

using namespace std;

class SolutionSetMatrixZeroes
{
public:
	void setZeroes(vector<vector<int>>& matrix) {
		bool colZero = false;
		int R = (int)matrix.size();
		int C = (int)matrix[0].size();
		for (int i = 0; i < R; i++)
		{
			if (matrix[i][0] == 0)
				colZero = true;
			for (int j = 1; j < C; j++)
			{
				if (matrix[i][j] == 0)
				{
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}
		for (int i = 1; i < R; i++)
		{
			for (int j = 1; j < C; j++)
			{
				if (matrix[i][0] == 0 || matrix[0][j] == 0)
					matrix[i][j] = 0;
			}
		}
		if (matrix[0][0] == 0)
		{
			for (int j = 0; j < C; j++)
				matrix[0][j] = 0;
		}
		if (colZero)
		{
			for (int i = 0; i < R; i++)
				matrix[i][0] = 0;
		}
	}
};

RUN_TESTCASE(SetMatrixZeroes)
{
	SolutionSetMatrixZeroes sln;
	vector<vector<int>> arr1 = {
		{1,2,3,0,5},
		{2,2,4,4,4},
		{3,3,0,3,3},
		{0,4,2,2,3},
		{1,2,3,3,3},
	};
	vector<vector<int>> ret1 = {
		{0,0,0,0,0},
		{0,2,0,0,4},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,2,0,0,3},
	};
	sln.setZeroes(arr1);
	TESTCASE_ASSERT(arr1 == ret1);
}