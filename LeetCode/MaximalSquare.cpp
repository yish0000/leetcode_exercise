#include "TestCase.h"

using namespace std;

class SolutionMaximalSquare
{
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		if (matrix.empty() || matrix[0].empty())
			return 0;

		int max_edge = 0;
		vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[i].size(); j++)
			{
				if (i == 0 || j == 0)
					dp[i][j] = matrix[i][j] == '1' ? 1 : 0;
				else
				{
					if (matrix[i][j] == '1')
					{
						if (matrix[i - 1][j] == '1' && matrix[i][j - 1] == '1' && matrix[i - 1][j - 1] == '1')
							dp[i][j] = std::min({ dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j] }) + 1;
						else
							dp[i][j] = 1;
					}
					else
						dp[i][j] = 0;
				}

				max_edge = std::max(dp[i][j], max_edge);
			}
		}

		return max_edge * max_edge;
	}
};

RUN_TESTCASE(MaximalSquare)
{
	SolutionMaximalSquare sln;

	vector<vector<char>> arr1 = {
		{'1','0','1','0','0'},
		{'1','0','1','1','1'},
		{'1','1','1','1','1'},
		{'1','0','0','1','0'},
	};
	TESTCASE_ASSERT(sln.maximalSquare(arr1) == 4);

	vector<vector<char>> arr2 = {
		{'0','0','0','1'},
		{'1','1','0','1'},
		{'1','1','1','1'},
		{'0','1','1','1'},
		{'0','1','1','1'},
	};
	TESTCASE_ASSERT(sln.maximalSquare(arr2) == 9);
}