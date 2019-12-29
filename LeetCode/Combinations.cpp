#include "TestCase.h"

using namespace std;

class SolutionCombinations
{
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> ret;
		vector<int> temp;
		combine_helper(ret, n, k, 1, temp);
		return ret;
	}

	void combine_helper(vector<vector<int>>& arr, int n, int k, int i, vector<int>& v)
	{
		if (k == 0)
		{
			arr.push_back(v);
			return;
		}

		for (int j = 0; j <= n - k; j++)
		{
			v.push_back(j + i);
			combine_helper(arr, n - j - 1, k - 1, i + j + 1, v);
			v.pop_back();
		}
	}
};

RUN_TESTCASE(Combinations)
{
	SolutionCombinations sln;

	vector<vector<int>> arr1 = {
		{1,2},{1,3},{1,4},{2,3},{2,4},{3,4}
	};
	TESTCASE_ASSERT(sln.combine(4, 2) == arr1);
}