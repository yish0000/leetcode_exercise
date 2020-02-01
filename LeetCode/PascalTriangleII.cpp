#include "TestCase.h"

using namespace std;

class SolutionPascalTriangleII
{
public:
	vector<int> getRow(int rowIndex) {
		vector<int> arr;
		getRow2(arr, rowIndex);
		return arr;
	}

	void getRow2(vector<int>& arr, int rowIndex)
	{
		if (rowIndex == 0)
			arr = vector<int>({ 1 });
		else if (rowIndex == 1)
			arr = vector<int>({ 1,1 });
		else
		{
			getRow2(arr, rowIndex - 1);

			arr.push_back(1);
			for (int i = (int)arr.size() - 2; i >= 1; --i)
				arr[i] += arr[i - 1];
		}
	}
};

RUN_TESTCASE(PascalTriangleII)
{
	SolutionPascalTriangleII sln;

	vector<int> arr1 = { 1,3,3,1 };
	TESTCASE_ASSERT(sln.getRow(3) == arr1);
	vector<int> arr2 = { 1,7,21,35,35,21,7,1 };
	TESTCASE_ASSERT(sln.getRow(7) == arr2);
}