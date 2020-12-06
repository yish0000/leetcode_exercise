//
//  RemoveDuplicateLetters.cpp
//  leetcode_exercise
//
//  Created by zhouchu hou on 2020/12/6.
//  Copyright © 2020 侯周楚. All rights reserved.
//

#include "TestCase.h"
#include <stack>

using namespace std;

class SolutionRemoveDuplicateLetters
{
public:
    string removeDuplicateLetters(string s) {
        int last_index[26] = {0};
        bool mask[26] = {false};
        stack<char> st;
        
        for (int i=0; i<s.length(); i++)
        {
            last_index[s[i] - 'a'] = i;
        }
        
        for (int i=0; i<s.length(); i++)
        {
            int c = s[i] - 'a';
            if (mask[c]) continue;
            while (!st.empty() && st.top() > c && i < last_index[st.top()])
            {
                mask[st.top()] = false;
                st.pop();
            }
            st.push(c);
            mask[c] = true;
        }
        
        string ret;
        while (st.size() > 0)
        {
            ret = (char)(st.top() + 'a') + ret;
            st.pop();
        }
        
        return ret;
    }
};

RUN_TESTCASE(RemoveDuplicateLetters)
{
    SolutionRemoveDuplicateLetters sln;
    TESTCASE_ASSERT(sln.removeDuplicateLetters("bcabc") == "abc");
    TESTCASE_ASSERT(sln.removeDuplicateLetters("cbacdcbc") == "acdb");
    TESTCASE_ASSERT(sln.removeDuplicateLetters("bccbab") == "bca");
}
