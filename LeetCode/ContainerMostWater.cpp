#include "TestCase.h"

using namespace std;

class SolutionContainerMostWater {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        for (int l=0, r=(int)height.size()-1; l<r;)
        {
            result = std::max(result, std::min(height[l], height[r]) * (r-l));
            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        
        return result;
    }
};

RUN_TESTCASE(ContainerMostWater)
{
    SolutionContainerMostWater sln;
    vector<int> arr = {1,8,6,2,5,4,8,3,7};
    TESTCASE_ASSERT(sln.maxArea(arr) == 49);
}
