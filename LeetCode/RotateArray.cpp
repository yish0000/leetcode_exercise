#include "TestCase.h"
#include <vector>

using namespace std;

class SolutionRotateArray
{
public:
	void rotate(vector<int>& nums, int k) {
		k = k % (int)nums.size();
		if (k == 0) return;
		int count = 0;
		for (int start = 0; count < (int)nums.size(); start++)
		{
			int current = start;
			int prev = nums[start];
			do
			{
				int next = (current + k) % (int)nums.size();
				int temp = nums[next];
				nums[next] = prev;
				prev = temp;
				current = next;
				count++;
			} while (current != start);
		}
	}
};

RUN_TESTCASE(RotateArray)
{
	SolutionRotateArray sln;

	vector<int> arr1 = { 1,2,3,4,5,6,7 };
	vector<int> res1 = { 5,6,7,1,2,3,4 };
	sln.rotate(arr1, 3);
	TESTCASE_ASSERT(arr1 == res1);

	vector<int> arr2 = { -1,-100,3,99 };
	vector<int> res2 = { 3,99,-1,-100 };
	sln.rotate(arr2, 2);
	TESTCASE_ASSERT(arr2 == res2);
}