#include "TestCase.h"
#include <vector>

class SolutionInsertSort
{
public:
	void InsertSort(std::vector<int>& arr)
	{
		for (int i = 1; i < (int)arr.size(); i++)
		{
			int key = arr[i];
			int j = i - 1;
			for (; j >= 0 && arr[j] > key; j--)
			{
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = key;
		}
	}
};

RUN_TESTCASE(InsertSort)
{
	SolutionInsertSort sln;
	std::vector<int> arr = { 4,1,88,-23,45,9,-4,13,45,76 };
	sln.InsertSort(arr);
	std::vector<int> cmp = { -23, -4, 1, 4, 9, 13, 45, 45, 76, 88 };
	TESTCASE_ASSERT(arr == cmp);
}