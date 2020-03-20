#include "TestCase.h"

using namespace std;

class SolutionTrappingRainWater
{
public:
	int trap(vector<int>& height) {
		vector<int> dp1(height.size(), 0);
		vector<int> dp2(height.size(), 0);

		// Left.
		int left_max = numeric_limits<int>::min();
		for (int i = 0; i < height.size(); i++)
		{
			if (left_max > height[i])
				dp1[i] = left_max - height[i];
			left_max = std::max(left_max, height[i]);
		}

		// Right.
		int right_max = numeric_limits<int>::min();
		for (int i = height.size() - 1; i >= 0; i--)
		{
			if (right_max > height[i])
				dp2[i] = right_max - height[i];
			right_max = std::max(right_max, height[i]);
		}

		int ret = 0;
		for (int i = 0; i < height.size(); i++)
			ret += std::min(dp1[i], dp2[i]);
		return ret;
	}
};

RUN_TESTCASE(TrappingRainWater)
{
	SolutionTrappingRainWater sln;

	vector<int> arr1 = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	TESTCASE_ASSERT(sln.trap(arr1) == 6);
}