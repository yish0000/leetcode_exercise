//
//  BullsAndCows.cpp
//  leetcode_exercise
//
//  Created by zhouchu hou on 2020/5/10.
//  Copyright © 2020 侯周楚. All rights reserved.
//

#include "TestCase.h"
#include <sstream>

using namespace std;

class SolutionBullsAndCows
{
public:
    string getHint(string secret, string guess) {
        int A = 0;
        int B = 0;
        int cows[10] = {0};
        vector<bool> bulls(secret.size(), false);
        for (size_t i=0; i<secret.size(); i++)
        {
            if (secret[i] == guess[i])
            {
                bulls[i] = true;
                ++A;
            }
            else
                cows[secret[i] - '0']++;
        }
        for (size_t i=0; i<secret.size(); i++)
        {
            if (!bulls[i] && cows[guess[i] - '0'] > 0)
            {
                cows[guess[i] - '0']--;
                ++B;
            }
        }

        stringstream ss;
        ss << A << "A" << B << "B";
        return ss.str();
    }
};

RUN_TESTCASE(BullsAndCows)
{
    SolutionBullsAndCows sln;
    TESTCASE_ASSERT(sln.getHint("1807", "7810") == "1A3B");
    TESTCASE_ASSERT(sln.getHint("1123", "0111") == "1A1B");
    TESTCASE_ASSERT(sln.getHint("1122", "2211") == "0A4B");
    TESTCASE_ASSERT(sln.getHint("1122", "1222") == "3A0B");
}
