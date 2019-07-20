#include "TestCase.h"

using namespace std;

class SolutionRemoveDuplicates
{
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int last = nums[0];
        int count = 1;
        for (int i=1; i<(int)nums.size(); i++)
        {
            if (nums[i] > last)
            {
                last = nums[i];
                std::swap(nums[i], nums[count]);
                count++;
            }
            else
                last = nums[i];
        }
        return count;
    }
};

RUN_TESTCASE(RemoveDuplicates)
{
    SolutionRemoveDuplicates sln;
    
    vector<int> arr1 = {1,1,2};
    vector<int> res1 = {1,2,1};
    TESTCASE_ASSERT(sln.removeDuplicates(arr1) == 2);
    TESTCASE_ASSERT(arr1 == res1);
    
    vector<int> arr2 = {0,0,1,1,1,2,2,3,3,4};
    vector<int> res2 = {0,1,2,3,4,0,2,1,3,1};
    TESTCASE_ASSERT(sln.removeDuplicates(arr2) == 5);
    TESTCASE_ASSERT(arr2 == res2);
}
