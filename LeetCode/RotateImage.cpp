#include "TestCase.h"

using namespace std;

class SolutionRotateImage {
public:
	void rotate(vector<vector<int>>& matrix) {
		int N = (int)matrix.size();
		for (int row = 0; row < N / 2; row++)
		{
			for (int col = row; col < N - row - 1; col++)
			{
				int& a = matrix[row][col];
				int& b = matrix[col][N - 1 - row];
				int& c = matrix[N - 1 - row][N - 1 - col];
				int& d = matrix[N - 1 - col][row];
				rotateOnce(a, b, c, d);
			}
		}
	}

	void rotateOnce(int& a, int& b, int& c, int& d)
	{
		int temp = d;
		d = c;
		c = b;
		b = a;
		a = temp;
	}
};

RUN_TESTCASE(RotateImage)
{
	SolutionRotateImage sln;

	vector<vector<int>> src_image = {
		{1,2,3},
		{4,5,6},
		{7,8,9},
	};
	vector<vector<int>> dst_image = {
		{7,4,1},
		{8,5,2},
		{9,6,3},
	};
	sln.rotate(src_image);
	TESTCASE_ASSERT(src_image == dst_image);

	vector<vector<int>> src_image2 = {
		{5, 1, 9,11},
		{2, 4, 8,10},
		{13, 3, 6, 7},
		{15,14,12,16},
	};
	vector<vector<int>> dst_image2 = {
		{15,13, 2, 5},
		{14, 3, 4, 1},
		{12, 6, 8, 9},
		{16, 7,10,11},
	};
	sln.rotate(src_image2);
	TESTCASE_ASSERT(src_image2 == dst_image2);
}