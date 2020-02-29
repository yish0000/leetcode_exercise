#include "TestCase.h"
#include <set>

using namespace std;

class SolutionHappyNumber
{
public:
	bool isHappy(int n)
	{
		if (n == 1) return true;

		set<int> visited;
		vector<int> arr;
		
		while (n != 1 && visited.find(n) == visited.end())
		{
			visited.insert(n);

			arr.clear();
			while (n > 0)
			{
				arr.push_back(n % 10);
				n /= 10;
			}

			n = 0;
			for (int i : arr)
				n += i * i;

			if (n == 1)
				return true;
		}
		
		return false;
	}
};

RUN_TESTCASE(HappyNumber)
{
	SolutionHappyNumber sln;
	TESTCASE_ASSERT(sln.isHappy(19));
	TESTCASE_ASSERT(sln.isHappy(1));
}