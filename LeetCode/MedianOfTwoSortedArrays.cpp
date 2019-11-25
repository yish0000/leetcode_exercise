#include "TestCase.h"

using namespace std;

class SolutionMedianOfTwoSortedArrays
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = (int)nums1.size();
        int n = (int)nums2.size();
        if (m > n)
        {
            std::swap(nums1, nums2);
            std::swap(m, n);
        }
        int iMin = 0;
        int iMax = m;
        int halfLen = (m + n + 1) / 2;
        while(iMin <= iMax)
        {
            int i = (iMin + iMax) / 2;
            int j = halfLen - i;
            if (i < iMax && nums2[j-1] > nums1[i])
                iMin = i + 1;
            else if (i > iMin && nums1[i-1] > nums2[j])
                iMax = i - 1;
            else
            {
                int maxLeft = 0;
                if (i == 0)
                    maxLeft = nums2[j - 1];
                else if (j == 0)
                    maxLeft = nums1[i - 1];
                else
                    maxLeft = std::max(nums1[i-1], nums2[j-1]);
                if ((m + n) % 2 == 1)
                    return maxLeft;
                
                int minRight = 0;
                if (i == m)
                    minRight = nums2[j];
                else if (j == n)
                    minRight = nums1[i];
                else
                    minRight = std::min(nums1[i], nums2[j]);
                return (maxLeft + minRight) / 2.0f;
            }
        }
        return 0.0;
    }
};

RUN_TESTCASE(MedianOfTwoSortedArrays)
{
    SolutionMedianOfTwoSortedArrays sln;
    
    std::vector<int> arr1 = {1,2,4,6,7,9,10};
    std::vector<int> arr2 = {3,5};
    TESTCASE_ASSERT(sln.findMedianSortedArrays(arr1, arr2) == 5.0);
    
    std::vector<int> arr3;
    std::vector<int> arr4 = {1};
    TESTCASE_ASSERT(sln.findMedianSortedArrays(arr3, arr4) == 1.0);
    
    TESTCASE_ASSERT(false);
}
