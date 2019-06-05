#include <iostream>
#include <vector>
#include "TestCase.h"

using namespace std;

class Solution
{
public:
	void GenArray(int min, int max, int n, vector<int>& arr)
	{
		arr.clear();

		for (int i = 0; i < n; i++)
		{
			int val = rand() % (max - min) + min;
			arr.push_back(val);
		}
	}

	void GetMinMax(const vector<int>& arr, int& max, int& min)
	{
		max = std::numeric_limits<int>::min();
		min = std::numeric_limits<int>::max();
		PartionGet(arr, 0, (int)arr.size() - 1, max, min);
	}

	void PartionGet(const vector<int>& arr, int s, int e, int& max, int& min)
	{
		if (e - s <= 1)
		{
			if (arr[s] < arr[e])
			{
				if (arr[s] < min)
					min = arr[s];
				if (arr[e] > max)
					max = arr[e];
			}
			else
			{
				if (arr[e] < min)
					min = arr[e];
				if (arr[s] > max)
					max = arr[s];
			}
			return;
		}

		int mid = s + (e - s) / 2;
		PartionGet(arr, s, mid, max, min);
		PartionGet(arr, mid+1, e, max, min);
	}
};

RUN_TESTCASE(PartionGet)
{
	Solution sln;
	vector<int> arr = { -59,-33,34,0,69,24,-22,58,62,-36,5,45,-19,-73,61,-9,95,42,-73,-64 };
	int min, max;
	sln.GetMinMax(arr, max, min);
	TESTCASE_ASSERT(min == -73 && max == 95);
}
