#include "TestCase.h"

using namespace std;

class SolutionInterleavingString
{
public:
	// 暴力
	bool isInterleave_Force(string s1, int i, string s2, int j, string cur, string s3) {
		if (cur == s3 && i == s1.length() && j == s2.length())
			return true;
		if (i < s1.length())
		{
			if (isInterleave_Force(s1, i + 1, s2, j, cur + s1[i], s3))
				return true;
		}
		if (j < s2.length())
		{
			if (isInterleave_Force(s1, i, s2, j + 1, cur + s2[j], s3))
				return true;
		}
		return false;
	}

	// 记录结果
	bool isInterleave_MTable(string s1, int i, string s2, int j, string cur, string s3, vector<vector<int>>& mt) {
		if (cur == s3 && i == s1.length() && j == s2.length())
			return true;
		if (i < s1.length() && j < s2.length() && mt[i][j] > 0)
			return mt[i][j] == 1;
		if (i < s1.length())
		{
			if (isInterleave_MTable(s1, i + 1, s2, j, cur + s1[i], s3, mt))
			{
				if (i < s1.length() && j < s2.length())
					mt[i][j] = 1;
				return true;
			}
		}
		if (j < s2.length())
		{
			if (isInterleave_MTable(s1, i, s2, j + 1, cur + s2[j], s3, mt))
			{
				if (i < s1.length() && j < s2.length())
					mt[i][j] = 1;
				return true;
			}
		}
		return false;
	}

	bool isInterleave_DP(string s1, string s2, string s3)
	{
		vector<vector<bool>> dp(s1.length() + 1, vector<bool>(s2.length() + 1, false));
		for (int i = 0; i <= s1.length(); i++)
		{
			for (int j = 0; j <= s2.length(); j++)
			{
				if (i == 0 && j == 0)
					dp[i][j] = true;
				else if (i == 0)
					dp[i][j] = dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];
				else if (j == 0)
					dp[i][j] = dp[i - 1][j] && s1[i - 1] == s3[i + j - 1];
				else
					dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
			}
		}
		return dp.back().back();
	}

	bool isInterleave(string s1, string s2, string s3) {
		if (s1.length() + s2.length() != s3.length())
			return false;
		
		return isInterleave_DP(s1, s2, s3);
	}
};

RUN_TESTCASE(InterleavingString)
{
	SolutionInterleavingString sln;
	TESTCASE_ASSERT(sln.isInterleave("aabcc", "dbbca", "aadbbcbcac"));
	TESTCASE_ASSERT(!sln.isInterleave("aabcc", "dbbca", "aadbbbaccc"));
	TESTCASE_ASSERT(sln.isInterleave("", "", ""));
	TESTCASE_ASSERT(!sln.isInterleave("abaaacbacaab", "bcccababccc", "bcccabaaaaabccaccbacabb"));
}