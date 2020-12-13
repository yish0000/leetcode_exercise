//
//  IntegerBreak.cpp
//  leetcode_exercise
//
//  Created by zhouchu hou on 2020/12/13.
//  Copyright © 2020 侯周楚. All rights reserved.
//

#include "TestCase.h"

using namespace std;

class SolutionIntegerBreak
{
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        
        vector<int> dp(n, 0);
        dp[0] = 4;
        dp[1] = 6;
        dp[2] = 9;

        int i = 3;
        while (i <= n - 4)
        {
            dp[i] = dp[i - 3] * 3;
            i++;
        }
        
        return dp[n - 4];
    }
};

RUN_TESTCASE(IntegerBreak)
{
    SolutionIntegerBreak sln;
    TESTCASE_ASSERT(sln.integerBreak(2) == 1);
    TESTCASE_ASSERT(sln.integerBreak(10) == 36);
}
