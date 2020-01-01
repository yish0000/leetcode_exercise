#include "TestCase.h"

using namespace std;

class SolutionGrayCode
{
public:
	vector<int> grayCode(int n) {
		vector<int> ret;
		grayCodeHelper(ret, n);
		return ret;
	}

	void grayCodeHelper(vector<int>& arr, int n)
	{
		if (n == 0)
			arr.push_back(0);
		else if (n == 1)
		{
			arr.push_back(0);
			arr.push_back(1);
		}
		else
		{
			grayCodeHelper(arr, n - 1);

			int start = (int)arr.size() - 1;
			for (int i = start; i >= 0; i--)
			{
				int value = arr[i];
				arr.push_back(value | (1 << (n - 1)));
			}
		}
	}
};

RUN_TESTCASE(GrayCode)
{
	SolutionGrayCode sln;

	vector<int> arr1 = { 0,1,3,2 };
	TESTCASE_ASSERT(sln.grayCode(2) == arr1);

	vector<int> arr2 = { 0 };
	TESTCASE_ASSERT(sln.grayCode(0) == arr2);

	vector<int> arr3 = { 0,1,3,2,6,7,5,4 };
	TESTCASE_ASSERT(sln.grayCode(3) == arr3);

	vector<int> arr4 = { 0,1,3,2,6,7,5,4,12,13,15,14,10,11,9,8 };
	TESTCASE_ASSERT(sln.grayCode(4) == arr4);
}