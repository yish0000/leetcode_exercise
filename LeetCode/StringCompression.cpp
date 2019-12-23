#include "TestCase.h"

using namespace std;

class SolutionStringCompression
{
public:
	int compress(vector<char>& chars) {
		if (chars.empty()) return 0;
		char last = chars.front();
		int lastIndex = 0;
		int dupCount = 0;
		vector<int> arr;
		bool bLastCompress = false;
		for (int i = 1; i < (int)chars.size() || bLastCompress; i++)
		{
			if (!bLastCompress && chars[i] == last)
			{
				dupCount++;

				if (i == (int)chars.size() - 1)
					bLastCompress = true;
			}
			else
			{
				if (bLastCompress)
				{
					i--;
					bLastCompress = false;
				}

				last = chars[i];

				if (dupCount > 0)
				{
					int num = dupCount + 1;
					arr.clear();
					while (num > 0)
					{
						int curNum = num % 10;
						arr.push_back(curNum);
						num /= 10;
					}
					for (int j = (int)arr.size() - 1; j >= 0; --j)
						chars[++lastIndex] = ('0' + arr[j]);
					if (dupCount > (int)arr.size())
						chars.erase(chars.begin() + (lastIndex + 1), chars.begin() + (lastIndex + 1 + dupCount - arr.size()));
					i -= dupCount - (int)arr.size();
					lastIndex = i;
					dupCount = 0;
				}
				else
					lastIndex = i;
			}
		}
		return (int)chars.size();
	}
};

RUN_TESTCASE(StringCompression)
{
	SolutionStringCompression sln;

	vector<char> arr1 = { 'a','b','b','b','b','b','c','d','d','d','e' };
	vector<char> ret1 = { 'a','b','5','c','d','3','e' };
	TESTCASE_ASSERT(sln.compress(arr1) == 7);
	TESTCASE_ASSERT(arr1 == ret1);

	vector<char> arr2 = { 'a','a','b','b','c','c','c' };
	vector<char> ret2 = { 'a','2','b','2','c','3' };
	TESTCASE_ASSERT(sln.compress(arr2) == 6);
	TESTCASE_ASSERT(arr2 == ret2);
}