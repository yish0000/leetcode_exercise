#include "TestCase.h"

using namespace std;

class SolutionAddArrayFormInteger
{
public:
	vector<int> addToArrayForm(vector<int>& A, int K) {
		int carry = 0;
		for (int i = (int)A.size() - 1; i >= 0; --i)
		{
			int curNum = K % 10;
			K /= 10;

			int value = curNum + carry + A[i];
			if (value >= 10)
			{
				value %= 10;
				carry = 1;
			}
			else
				carry = 0;
			A[i] = value;
		}

		K += carry;
		if (K > 0)
		{
			vector<int> ret;
			while (K > 0)
			{
				int curNum = K % 10;
				K /= 10;
				ret.push_back(curNum);
			}

			std::reverse(ret.begin(), ret.end());
			ret.insert(ret.end(), A.begin(), A.end());
			return ret;
		}

		return A;
	}
};

RUN_TESTCASE(AddArrayFormInteger)
{
	SolutionAddArrayFormInteger sln;

	vector<int> arr1 = { 2,7,4 };
	vector<int> res1 = { 4,5,5 };
	TESTCASE_ASSERT(sln.addToArrayForm(arr1, 181) == res1);

	vector<int> arr2 = { 2,1,5 };
	vector<int> res2 = { 1,0,2,1 };
	TESTCASE_ASSERT(sln.addToArrayForm(arr2, 806) == res2);

	vector<int> arr3 = { 1,2,3,4 };
	vector<int> res3 = { 8,8,6,8,2,1,7 };
	TESTCASE_ASSERT(sln.addToArrayForm(arr3, 8866983) == res3);
}