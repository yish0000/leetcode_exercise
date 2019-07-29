#include "TestCase.h"

using namespace std;

class SolutionPlusOne
{
public:
	vector<int> plusOne(vector<int>& digits) {
		int carry = 1;
		for (int i = (int)digits.size() - 1; i >= 0; --i)
		{
			if (digits[i] == 9)
			{
				digits[i] = 0;
				carry = 1;
			}
			else
			{
				digits[i] += carry;
				carry = 0;
				break;
			}
		}
		if (carry > 0)
			digits.insert(digits.begin(), carry);
		return digits;
	}
};

RUN_TESTCASE(PlusOne)
{
	SolutionPlusOne sln;
	vector<int> arr1 = { 1,2,9,9,9 };
	vector<int> res1 = { 1,3,0,0,0 };
	TESTCASE_ASSERT(sln.plusOne(arr1) == res1);

	vector<int> arr2 = { 9,9,9,9,9 };
	vector<int> res2 = { 1,0,0,0,0,0 };
	TESTCASE_ASSERT(sln.plusOne(arr2) == res2);

	vector<int> arr3 = { 4,3,2,1 };
	vector<int> res3 = { 4,3,2,2 };
	TESTCASE_ASSERT(sln.plusOne(arr3) == res3);
}