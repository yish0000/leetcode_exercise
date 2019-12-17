#include "TestCase.h"

using namespace std;

class SolutionLengthOfLongestSubstringII
{
public:
	int lengthOfLongestSubstring(string s1, string s2, string& common) {
		if (s1.empty() || s2.empty())
			return 0;

		int curLength = 0;
		string curLong;
		vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), 0));
		dp[0][0] = (s1[0] == s2[0]) ? 1 : 0;
		for (size_t i = 0; i < s1.size(); i++)
		{
			for (size_t j = 0; j < s2.size(); j++)
			{
				if (i == 0 && j == 0)
					continue;
				if (i == 0)
				{
					dp[i][j] = (s1[i] == s2[j] || dp[i][j - 1] == 1) ? 1 : 0;
				}
				else if (j == 0)
				{
					dp[i][j] = (s1[i] == s2[j] || dp[i - 1][j] == 1) ? 1 : 0;
				}
				else
				{
					if (s1[i] == s2[j])
					{
						int h = (dp[i - 1][j - 1] & 0xffff0000) >> 16;
						int l = (dp[i - 1][j - 1] & 0xffff);
						if (h + 1 > l)
							l = h + 1;
						dp[i][j] = ((h + 1) << 16) | l;

						if (l > curLength)
						{
							curLength = l;
							curLong.clear();
							while (l > 0)
							{
								curLong.push_back(s1[i - l + 1]);
								--l;
							}
							if (curLong.size() > common.size())
								common = curLong;
						}
					}
					else
					{
						dp[i][j] = std::max(dp[i - 1][j] & 0xffff, dp[i][j - 1] & 0xffff);
					}
				}
			}
		}

		return dp[s1.size() - 1][s2.size() - 1] & 0xffff;
	}
};

RUN_TESTCASE(LengthOfLongestSubstringII)
{
	SolutionLengthOfLongestSubstringII sln;

	string common;
	TESTCASE_ASSERT(sln.lengthOfLongestSubstring("He110123", "33012777123", common) == 3);
	TESTCASE_ASSERT(common == "123" || common == "012");
	TESTCASE_ASSERT(sln.lengthOfLongestSubstring("xasdfasd44444f23", "123123asdfasdf53465453asdf", common) == 7);
	TESTCASE_ASSERT(common == "asdfasd");
}