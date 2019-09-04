#include "TestCase.h"

using namespace std;

class SolutionWordBreak
{
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		vector<bool> dp(s.size()+1);
		dp[0] = true;
		for (int i = 1; i <= (int)s.size(); i++)
		{
			for (auto& word : wordDict)
			{
				dp[i] = dp[i] || (i >= (int)word.size() ? (s.substr(i-(int)word.size(), word.size()) == word && dp[i-(int)word.size()]) : false);
			}
		}
		return dp[s.size()];
	}
};

RUN_TESTCASE(WordBreak)
{
	SolutionWordBreak sln;
    vector<string> arr1({"leet", "code"});
	TESTCASE_ASSERT(sln.wordBreak("leetcode", arr1));
    vector<string> arr2({"apple", "pen"});
	TESTCASE_ASSERT(sln.wordBreak("applepenapple", arr2));
    vector<string> arr3({"cats", "dog", "sand", "and", "cat"});
	TESTCASE_ASSERT(!sln.wordBreak("catsandog", arr3));
}
