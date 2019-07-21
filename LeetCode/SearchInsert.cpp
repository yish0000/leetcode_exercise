#include "TestCase.h"

using namespace std;

class SolutionSearchInsert
{
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = (int)nums.size();
        while(l < r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
            {
                if (r == mid)
                    return r - 1;
                r = mid;
            }
            else if (nums[mid] < target)
            {
                l = mid + 1;
            }
        }
        return r;
    }
};

RUN_TESTCASE(SearchInsert)
{
    SolutionSearchInsert sln;
    vector<int> arr1 = {1,3,5,6};
    TESTCASE_ASSERT(sln.searchInsert(arr1, 5) == 2);
    TESTCASE_ASSERT(sln.searchInsert(arr1, 2) == 1);
    TESTCASE_ASSERT(sln.searchInsert(arr1, 7) == 4);
    TESTCASE_ASSERT(sln.searchInsert(arr1, 0) == 0);
    vector<int> arr2 = {1,3,4,7,8,9,10,13,14,15,16,17,19,21,99};
    TESTCASE_ASSERT(sln.searchInsert(arr2, 12) == 7);
    TESTCASE_ASSERT(sln.searchInsert(arr2, 16) == 10);
    TESTCASE_ASSERT(sln.searchInsert(arr2, 1) == 0);
    TESTCASE_ASSERT(sln.searchInsert(arr2, 0) == 0);
    TESTCASE_ASSERT(sln.searchInsert(arr2, 21) == 13);
    TESTCASE_ASSERT(sln.searchInsert(arr2, 99) == 14);
    TESTCASE_ASSERT(sln.searchInsert(arr2, 100) == 15);
}
