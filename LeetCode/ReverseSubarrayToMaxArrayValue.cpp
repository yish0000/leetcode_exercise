#include "TestCase.h"

using namespace std;

class SolutionReverseSubarrayToMaxArrayValue
{
public:
	int maxValueAfterReverse(vector<int>& nums) {
		int oldScore = 0;
		for (int i = 0; i < nums.size() - 1; i++)
		{
			oldScore += abs(nums[i] - nums[i + 1]);
		}

		int preScore = oldScore;
		for (int r = 1; r < nums.size() - 1; r++)
			preScore = std::max(preScore, oldScore + abs(nums[r + 1] - nums[0]) - abs(nums[r + 1] - nums[r]));

		int postScore = oldScore;
		for (int l = 1; l < nums.size() - 1; l++)
			postScore = std::max(postScore, oldScore + abs(nums.back() - nums[l - 1]) - abs(nums[l] - nums[l - 1]));

		int x1 = INT_MIN, y1 = INT_MIN;
		int x2 = INT_MIN, y2 = INT_MIN;
		int x3 = INT_MIN, y3 = INT_MIN;
		int x4 = INT_MIN, y4 = INT_MIN;
		for (int i = 1; i < nums.size() - 1; i++)
		{
			x1 = std::max(x1, nums[i] - nums[i - 1] - abs(nums[i] - nums[i - 1]));
			y1 = std::max(y1, nums[i] - nums[i + 1] - abs(nums[i + 1] - nums[i]));
			x2 = std::max(x2, nums[i - 1] + nums[i] - abs(nums[i] - nums[i - 1]));
			y2 = std::max(y2, -nums[i] - nums[i + 1] - abs(nums[i + 1] - nums[i]));
			x3 = std::max(x3, -nums[i - 1] - nums[i] - abs(nums[i] - nums[i - 1]));
			y3 = std::max(y3, nums[i + 1] + nums[i] - abs(nums[i + 1] - nums[i]));
			x4 = std::max(x4, -nums[i] + nums[i - 1] - abs(nums[i] - nums[i - 1]));
			y4 = std::max(y4, nums[i + 1] - nums[i] - abs(nums[i + 1] - nums[i]));
		}

		int midScore = oldScore;
		midScore = std::max(midScore, oldScore + x1 + y1);
		midScore = std::max(midScore, oldScore + x2 + y2);
		midScore = std::max(midScore, oldScore + x3 + y3);
		midScore = std::max(midScore, oldScore + x4 + y4);
		return std::max({ preScore, midScore, postScore });
	}
};

RUN_TESTCASE(ReverseSubarrayToMaxArrayValue)
{
	SolutionReverseSubarrayToMaxArrayValue sln;

	vector<int> arr1 = { 2,3,1,5,4 };
	TESTCASE_ASSERT(sln.maxValueAfterReverse(arr1) == 10);

	vector<int> arr2 = { 2,4,9,24,2,1,10 };
	TESTCASE_ASSERT(sln.maxValueAfterReverse(arr2) == 68);
}