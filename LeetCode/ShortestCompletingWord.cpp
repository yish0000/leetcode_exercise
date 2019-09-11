#include "TestCase.h"

using namespace std;

class SolutionShortestCompletingWord
{
public:
	string shortestCompletingWord(string licensePlate, vector<string>& words) {
		vector<int> p(26, 0);
		count(licensePlate, p);

		int min_len = 16;
		string ans;
		for (auto& word : words)
		{
			vector<int> w(26, 0);
			count(word, w);

			bool bValid = true;
			for (int i = 0; i < 26; i++)
			{
				if (p[i] > 0 && w[i] < p[i])
				{
					bValid = false;
					break;
				}
			}

			if (bValid)
			{
				if ((int)word.length() < min_len)
				{
					ans = word;
					min_len = (int)word.length();
				}
			}
		}

		return ans;
	}

	void count(string& s, vector<int>& cnts)
	{
		for (auto c : s)
		{
			if (isalpha(c))
				cnts[tolower(c) - 'a']++;
		}
	}
};

RUN_TESTCASE(ShortestCompletingWord)
{
	SolutionShortestCompletingWord sln;
	
	vector<string> w1 = { "step", "steps", "stripe", "stepple" };
	TESTCASE_ASSERT(sln.shortestCompletingWord("1s3 PSt", w1) == "steps");

	vector<string> w2 = { "looks", "pest", "stew", "show" };
	TESTCASE_ASSERT(sln.shortestCompletingWord("1s3 456", w2) == "pest");

	vector<string> w3 = { "suggest", "letter", "of", "husband", "easy", "education", "drug", "prevent", "writer", "old" };
	TESTCASE_ASSERT(sln.shortestCompletingWord("Ah71752", w3) == "husband");

	vector<string> w4 = { "measure", "other", "every", "base", "according", "level", "meeting", "none", "marriage", "rest" };
	TESTCASE_ASSERT(sln.shortestCompletingWord("GrC8950", w4) == "according");
}