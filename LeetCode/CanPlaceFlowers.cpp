#include "TestCase.h"

using namespace std;

class SolutionCanPlaceFlowers
{
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		if (n == 0) return true;
		for (int i = 0; i < flowerbed.size(); i++)
		{
			if (flowerbed[i] == 0)
			{
				if ((i == flowerbed.size() - 1 || flowerbed[i + 1] == 0) &&
					(i == 0 || flowerbed[i - 1] == 0))
				{
					if (--n == 0) break;
					i++;
				}
			}
			else i++;
		}
		return n == 0;
	}
};

RUN_TESTCASE(CanPlaceFlowers)
{
	SolutionCanPlaceFlowers sln;

	vector<int> arr1 = { 1,0,0,0,1 };
	TESTCASE_ASSERT(sln.canPlaceFlowers(arr1, 1));

	vector<int> arr2 = { 1,0,0,0,1 };
	TESTCASE_ASSERT(!sln.canPlaceFlowers(arr2, 2));

	vector<int> arr3 = { 1,0,0,0,0,1 };
	TESTCASE_ASSERT(!sln.canPlaceFlowers(arr3, 2));

	vector<int> arr4 = { 0,1,0 };
	TESTCASE_ASSERT(!sln.canPlaceFlowers(arr4, 1));

	vector<int> arr5 = { 0,0,0,0,0,1,0,0 };
	TESTCASE_ASSERT(sln.canPlaceFlowers(arr5, 0));

	vector<int> arr6 = { 0,1,0,1,0,1,0,0 };
	TESTCASE_ASSERT(sln.canPlaceFlowers(arr6, 1));
}