#include "TestCase.h"

using namespace std;

class SolutionMoveZeroes
{
public:
	void moveZeroes(vector<int>& nums) {
		int l = 0, r = 0;
		while (r < nums.size())
		{
			if (nums[r] == 0)
				r++;
			else
			{
				if (r > l)
					std::swap(nums[l], nums[r]);
				l++;
				r++;
			}
		}
	}
};

RUN_TESTCASE(MoveZeroes)
{
	SolutionMoveZeroes sln;

	vector<int> arr1 = { 0,1,0,3,12 };
	vector<int> ret1 = { 1,3,12,0,0 };
	sln.moveZeroes(arr1);
	TESTCASE_ASSERT(arr1 == ret1);

	vector<int> arr2 = { 0,1,0,3,12,0,0,7,8,33,0,5,0,0 };
	vector<int> ret2 = { 1,3,12,7,8,33,5,0,0,0,0,0,0,0 };
	sln.moveZeroes(arr2);
	TESTCASE_ASSERT(arr2 == ret2);
}