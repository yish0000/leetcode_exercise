#include "TestCase.h"
#include <unordered_map>

using namespace std;

class SolutionPermutationInString
{
public:
	bool checkInclusion(string s1, string s2) {
		if (s1.size() > s2.size())
			return false;
		int m1[26] = { 0 };
		int m2[26] = { 0 };
		for (int i = 0; i < s1.size(); i++)
		{
			m1[s1[i] - 'a']++;
			m2[s2[i] - 'a']++;
		}
		int sameCount = 0;
		for (int i = 0; i < 26; i++)
			sameCount += (m1[i] == m2[i]) ? 1 : 0;
		for (int i = 0; i < s2.size() - s1.size(); i++)
		{
			if (sameCount == 26)
				return true;

			m2[s2[i] - 'a']--;
			if (m2[s2[i] - 'a'] == m1[s2[i] - 'a'])
				sameCount++;
			else if (m2[s2[i] - 'a'] == m1[s2[i] - 'a'] - 1)
				sameCount--;

			m2[s2[i + s1.size()] - 'a']++;
			if (m2[s2[i + s1.size()] - 'a'] == m1[s2[i + s1.size()] - 'a'])
				sameCount++;
			else if (m2[s2[i + s1.size()] - 'a'] == m1[s2[i + s1.size()] - 'a'] + 1)
				sameCount--;
		}
		return sameCount == 26;
	}
};

RUN_TESTCASE(PermutationInString)
{
	SolutionPermutationInString sln;
	TESTCASE_ASSERT(sln.checkInclusion("ab", "eidbaooo"));
	TESTCASE_ASSERT(!sln.checkInclusion("ab", "eidboaoo"));
	TESTCASE_ASSERT(sln.checkInclusion("adc", "dcda"));
	TESTCASE_ASSERT(!sln.checkInclusion("hello", "ooolleoooleh"));
}