#include "TestCase.h"

using namespace std;

class SolutionWordSubsets
{
public:
	vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
		int cntsB[26] = { 0 };
		for (auto& b : B)
		{
			int cntsb[26] = { 0 };
			count(b, cntsb);
			for (int i = 0; i < 26; i++)
				cntsB[i] = std::max(cntsB[i], cntsb[i]);
		}

		vector<string> res;
		for (auto& a : A)
		{
			int cntsa[26] = { 0 };
			count(a, cntsa);

			bool bInvalid = false;
			for (int i = 0; i < 26; i++)
			{
				if (cntsa[i] < cntsB[i])
				{
					bInvalid = true;
					break;
				}
			}
			if (!bInvalid)
				res.push_back(a);
		}
		return res;
	}

	void count(string& s, int cnts[])
	{
		for (string::const_iterator it = s.begin(); it != s.end(); ++it)
			cnts[*it - 'a']++;
	}
};

RUN_TESTCASE(WordSubsets)
{
	SolutionWordSubsets sln;

	vector<string> a1 = { "amazon","apple","facebook","google","leetcode" };
	vector<string> b1 = { "e","o" };
	vector<string> ans1 = { "facebook","google","leetcode" };
	TESTCASE_ASSERT(sln.wordSubsets(a1, b1) == ans1);

	vector<string> a2 = { "amazon","apple","facebook","google","leetcode" };
	vector<string> b2 = { "l","e" };
	vector<string> ans2 = { "apple","google","leetcode" };
	TESTCASE_ASSERT(sln.wordSubsets(a2, b2) == ans2);

	vector<string> a3 = { "amazon","apple","facebook","google","leetcode" };
	vector<string> b3 = { "e","oo" };
	vector<string> ans3 = { "facebook","google" };
	TESTCASE_ASSERT(sln.wordSubsets(a3, b3) == ans3);

	vector<string> a4 = { "amazon","apple","facebook","google","leetcode" };
	vector<string> b4 = { "lo","eo" };
	vector<string> ans4 = { "google","leetcode" };
	TESTCASE_ASSERT(sln.wordSubsets(a4, b4) == ans4);

	vector<string> a5 = { "amazon","apple","facebook","google","leetcode" };
	vector<string> b5 = { "ec","oc","ceo" };
	vector<string> ans5 = { "facebook","leetcode" };
	TESTCASE_ASSERT(sln.wordSubsets(a5, b5) == ans5);
}