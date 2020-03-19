#include "TestCase.h"

using namespace std;

class SolutionSearch2DMatrixII
{
public:
	// O(M+N)
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() <= 0 || matrix[0].size() <= 0)
			return false;
		int i = (int)matrix.size() - 1;
		int j = 0;
		while (i >= 0 && i < matrix.size() && j >= 0 && j < matrix[0].size()) {
			if (matrix[i][j] == target) {
				return true;
			}
			else if (matrix[i][j] > target) {
				i--;
			}
			else if (matrix[i][j] < target) {
				j++;
			}
		}

		return false;
	}
	/*
	// O(M*logN)
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty())
			return false;
		if (target < matrix.front().front() || target > matrix.back().back())
			return false;
		for (int i = 0; i < matrix.size(); i++)
		{
			if (matrix[i].front() > target)
				return false;
			if (matrix[i].back() < target)
				continue;
			int l = 0, r = (int)matrix[i].size() - 1;
			while (l <= r)
			{
				int mid = l + (r - l) / 2;
				if (matrix[i][mid] == target)
					return true;
				else if (matrix[i][mid] < target)
					l = mid + 1;
				else
					r = mid - 1;
			}
		}
		return false;
	}*/
};

RUN_TESTCASE(Search2DMatrixII)
{
	SolutionSearch2DMatrixII sln;

	vector<vector<int>> arr1 = {
		{1,   4,  7, 11, 15},
		{2,   5,  8, 12, 19},
		{3,   6,  9, 16, 22},
		{10, 13, 14, 17, 24},
		{18, 21, 23, 26, 30}
	};
	TESTCASE_ASSERT(sln.searchMatrix(arr1, 5));
	TESTCASE_ASSERT(!sln.searchMatrix(arr1, 20));
}