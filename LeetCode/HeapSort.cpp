#include <iostream>
#include <vector>
#include "TestCase.h"

class Solution
{
public:
	void HeapSort(std::vector<int>& arr)
	{
		int len = arr.size() - 1;
		int beginIndex = (len - 1) >> 1;
		for (int i = beginIndex; i >= 0; i--)
		{
			MaxHeapify(arr, i, len);
		}

		while (len > 0)
		{
			std::swap(arr[0], arr[len]);
			MaxHeapify(arr, 0, len - 1);
			len--;
		}
	}

private:
	void MaxHeapify(std::vector<int>& arr, int index, int len)
	{
		int leftChild = index * 2 + 1;
		int rightChild = index * 2 + 2;
		int maxChild = leftChild;
		if (leftChild > len) return;
		if (rightChild <= len && arr[rightChild] > arr[leftChild])
			maxChild = rightChild;
		if (arr[maxChild] > arr[index])
		{
			std::swap(arr[index], arr[maxChild]);
			MaxHeapify(arr, maxChild, len);
		}
	}
};

RUN_TESTCASE(HeapSort)
{
	std::vector<int> test = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
	std::vector<int> cmp = { 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9 };

	Solution sln;
	sln.HeapSort(test);
	TESTCASE_ASSERT(test == cmp);

	std::vector<int> test2 = { 82, 97, 34, 14, 15, 80, 5, 35, 19, 73 };
	std::vector<int> cmp2 = { 5, 14, 15, 19, 34, 35, 73, 80, 82, 97 };
	sln.HeapSort(test2);
	TESTCASE_ASSERT(test2 == cmp2);
}