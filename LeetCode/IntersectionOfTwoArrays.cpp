//
//  IntersectionOfTwoArrays.cpp
//  leetcode_exercise
//
//  Created by zhouchu hou on 2020/12/24.
//  Copyright © 2020 侯周楚. All rights reserved.
//

#include "TestCase.h"
#include <unordered_map>

using namespace std;

class SolutionIntersectionOfTwoArrays
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> h;
        for (int i : nums1)
            h[i] = 1;
        vector<int> ret;
        for (int i : nums2)
        {
            if (h.find(i) != h.end())
                h[i]++;
        }
        for (auto& p : h)
        {
            if (p.second > 1)
                ret.push_back(p.first);
        }
        return ret;
    }
};

RUN_TESTCASE(IntersectionOfTwoArrays)
{
    SolutionIntersectionOfTwoArrays sln;
    vector<int> arr1 = {1,2,2,1};
    vector<int> arr2 = {2,2};
    vector<int> ret1 = {2};
    TESTCASE_ASSERT(sln.intersection(arr1, arr2) == ret1);
}
