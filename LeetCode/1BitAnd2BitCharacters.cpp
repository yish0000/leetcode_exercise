#include "TestCase.h"

using namespace std;

class Solution1BitAnd2BitCharacters
{
public:
	bool isOneBitCharacter(vector<int>& bits) {
		vector<int>::const_iterator it = bits.begin();
		while (it != bits.end())
		{
			if (it == bits.end() - 1 && *it == 0)
				return true;
			else
			{
				if (*it == 0)
					++it;
				else
					it += 2;
			}
		}
		return false;
	}
};

RUN_TESTCASE(1BitAnd2BitCharacters)
{
	Solution1BitAnd2BitCharacters sln;

	vector<int> arr1 = { 1,0,0 };
	TESTCASE_ASSERT(sln.isOneBitCharacter(arr1));

	vector<int> arr2 = { 1,1,1,0 };
	TESTCASE_ASSERT(!sln.isOneBitCharacter(arr2));

	vector<int> arr3 = { 1,1,0,1,1,0 };
	TESTCASE_ASSERT(sln.isOneBitCharacter(arr3));

	vector<int> arr4 = { 1,1,1,0,0,1,0 };
	TESTCASE_ASSERT(!sln.isOneBitCharacter(arr4));
}