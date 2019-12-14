#include "TestCase.h"

using namespace std;

class SolutionPascalTriangle
{
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> arr;
		if (numRows <= 0) return arr;
		arr.push_back(vector<int>({ 1 }));
		if (numRows == 1) return arr;
		arr.push_back(vector<int>({ 1,1 }));
		if (numRows == 2) return arr;
		for (int i = 2; i < numRows; i++)
		{
			vector<int> line;
			line.push_back(1);
			for (int j = 0; j < i - 1; j++)
				line.push_back(arr[i - 1][j] + arr[i - 1][j + 1]);
			line.push_back(1);
			arr.push_back(line);
		}
		return arr;
	}
};

RUN_TESTCASE(PascalTriangle)
{
	SolutionPascalTriangle sln;

	vector<vector<int>> ret = {
		{1},
		{1,1},
		{1,2,1},
		{1,3,3,1},
		{1,4,6,4,1},
		{1,5,10,10,5,1},
	};
	TESTCASE_ASSERT(sln.generate(6) == ret);
}