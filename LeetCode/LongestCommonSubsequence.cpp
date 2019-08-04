#include "TestCase.h"

using namespace std;

class SolutionLongestCommonSubsequence
{
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> c(text1.size(), vector<int>(text2.size(), -1));
        return longestCommonSubsequenceHelper(text1, text2, (int)text1.size()-1, (int)text2.size()-1, c);
    }
    
    int longestCommonSubsequenceHelper(string& text1, string& text2, int i, int j, vector<vector<int>>& c)
    {
        if (i < 0 || j < 0)
            return 0;
        if (c[i][j] != -1)
            return c[i][j];
        if (text1[i] == text2[j])
        {
            c[i][j] = longestCommonSubsequenceHelper(text1, text2, i-1, j-1, c) + 1;
        }
        else
            c[i][j] = std::max(longestCommonSubsequenceHelper(text1, text2, i-1, j, c),
                               longestCommonSubsequenceHelper(text1, text2, i, j-1, c));
        return c[i][j];
    }
};

RUN_TESTCASE(LongestCommonSubsequence)
{
    SolutionLongestCommonSubsequence sln;
    TESTCASE_ASSERT(sln.longestCommonSubsequence("abcde", "ace") == 3);
    TESTCASE_ASSERT(sln.longestCommonSubsequence("abc", "abc") == 3);
    TESTCASE_ASSERT(sln.longestCommonSubsequence("abc", "def") == 0);
}
