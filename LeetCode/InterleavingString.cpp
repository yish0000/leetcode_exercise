//
//  InterleavingString.cpp
//  leetcode_exercise
//
//  Created by zhouchu hou on 2021/4/11.
//  Copyright © 2021 侯周楚. All rights reserved.
//

#include "TestCase.h"

using namespace std;

class SolutionInterleavingString
{
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = (int)s1.length();
        int n2 = (int)s2.length();
        int n3 = (int)s3.length();
        if (n1 + n2 != n3)
            return false;
        
        vector<vector<bool>> dp(n1, vector<bool>(n2, false));
        
        
        return true;
    }
};

RUN_TESTCASE(InterleavingString)
{
    SolutionInterleavingString sln;
    TESTCASE_ASSERT(sln.isInterleave("aabcc", "dbbca", "aadbbcbcac"));
    TESTCASE_ASSERT(!sln.isInterleave("aabcc", "dbbca", "aadbbbaccc"));
    TESTCASE_ASSERT(sln.isInterleave("", "", ""));
}
