#include "TestCase.h"
#include <stack>

using namespace std;

class SolutionAsteroidCollision
{
public:
	vector<int> asteroidCollision(vector<int>& asteroids) {
		stack<int> s;
		for (auto asteroid : asteroids)
		{
			if (s.empty())
				s.push(asteroid);
			else
			{
				if (s.top() > 0 && asteroid < 0)
				{
					while (s.size() > 0 && s.top() > 0 && asteroid < 0)
					{
						if (abs(asteroid) > abs(s.top()))
							s.pop();
						else
						{
							if (abs(asteroid) == abs(s.top()))
								s.pop();
							asteroid = 0;
						}
					}

					if (asteroid != 0)
						s.push(asteroid);
				}
				else
					s.push(asteroid);
			}
		}

		vector<int> ret;
		while (s.size() > 0)
		{
			ret.push_back(s.top());
			s.pop();
		}
		std::reverse(ret.begin(), ret.end());
		return ret;
	}
};

RUN_TESTCASE(AsteroidCollision)
{
	SolutionAsteroidCollision sln;

	vector<int> arr1 = { 5, 10, -5 };
	vector<int> ret1 = { 5,10 };
	TESTCASE_ASSERT(sln.asteroidCollision(arr1) == ret1);

	vector<int> arr2 = { 8,-8 };
	vector<int> ret2 = {};
	TESTCASE_ASSERT(sln.asteroidCollision(arr2) == ret2);

	vector<int> arr3 = { 10,2,-5 };
	vector<int> ret3 = { 10 };
	TESTCASE_ASSERT(sln.asteroidCollision(arr3) == ret3);

	vector<int> arr4 = { -2,-1,1,2 };
	vector<int> ret4 = { -2,-1,1,2 };
	TESTCASE_ASSERT(sln.asteroidCollision(arr4) == ret4);

	vector<int> arr5 = { -2,-2,1,-2 };
	vector<int> ret5 = { -2,-2,-2 };
	TESTCASE_ASSERT(sln.asteroidCollision(arr5) == ret5);
}