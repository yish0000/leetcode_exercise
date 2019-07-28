#include "TestCase.h"

using namespace std;

class SolutionSearchRotatedSortedArray
{
public:
    int search(vector<int>& nums, int target) {
        int pilot = -1;
        int l = 0;
        int r = (int)nums.size() - 1;
        while(l < r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[mid+1])
            {
                pilot = mid;
                break;
            }
            if (nums[mid] > nums.back())
                l = mid + 1;
            else if (nums[mid] < nums.front())
                r = mid - 1;
            else
                break;
        }

        if (pilot < 0)
        {
            pilot = l;
            if (pilot >= (int)nums.size())
                pilot = (int)nums.size() - 1;
        }
        
        int idx = searchRecurse(nums, target, 0, pilot);
        if (idx != -1)
            return idx;
        idx = searchRecurse(nums, target, pilot+1, (int)nums.size()-1);
        return idx;
    }
    
    int searchRecurse(vector<int>& nums, int target, int beg, int end)
    {
        if (beg > end)
            return -1;

        int mid = beg + (end - beg) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            return searchRecurse(nums, target, beg, mid-1);
        else
            return searchRecurse(nums, target, mid+1, end);
    }
};

RUN_TESTCASE(SearchRotatedSortedArray)
{
    SolutionSearchRotatedSortedArray sln;
    
    vector<int> arr = {4,5,6,7,0,1,2};
    TESTCASE_ASSERT(sln.search(arr, 0) == 4);
    TESTCASE_ASSERT(sln.search(arr, 3) == -1);
    
    vector<int> arr2 = {9,10,13,14,17,22,23,25,77,88,99,100,111,112,200,300,0,1,2,3,4,5,6,7,8,9,10};
    TESTCASE_ASSERT(sln.search(arr2, 0) == 16);
    TESTCASE_ASSERT(sln.search(arr2, 22) == 5);
    
    vector<int> arr3 = {1,2,3,4,5,6,7,8,9};
    TESTCASE_ASSERT(sln.search(arr3, 7) == 6);
    
    vector<int> arr4 = {};
    TESTCASE_ASSERT(sln.search(arr4, 5) == -1);
}
