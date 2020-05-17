#include "TestCase.h"

using namespace std;

class SolutionUTF8Validation
{
public:
	bool validUtf8(vector<int>& data) {
		for (int i = 0; i < data.size(); i++)
		{
			if (data[i] & 0x80)
			{
				int count = 0;
				if ((data[i] >> 5) == 0x6) count = 1;
				else if ((data[i] >> 4) == 0xe) count = 2;
				else if ((data[i] >> 3) == 0x1e) count = 3;
				else return false;
				for (int j = 1; j <= count; j++)
				{
					if (i + j >= (int)data.size() || (data[i + j] >> 6) != 2)
						return false;
				}
				i += count;
			}
		}

		return true;
	}
};

RUN_TESTCASE(UTF8Validation)
{
	SolutionUTF8Validation sln;

	vector<int> arr1 = { 197, 130, 1 };
	TESTCASE_ASSERT(sln.validUtf8(arr1));

	vector<int> arr2 = { 235, 140, 4 };
	TESTCASE_ASSERT(!sln.validUtf8(arr2));

	vector<int> arr3 = { 237 };
	TESTCASE_ASSERT(!sln.validUtf8(arr3));
}