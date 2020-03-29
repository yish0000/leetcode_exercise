#include "TestCase.h"
#include <unordered_map>

using namespace std;

class SolutionWordPattern
{
public:
	bool wordPattern(string pattern, string str) {
		if (pattern.empty() && str.empty())
			return true;
		if (pattern.empty() != str.empty())
			return false;

		unordered_map<char, string> h1;
		unordered_map<string, char> h2;
		string::const_iterator pit = pattern.begin();
		string::const_iterator beg = str.begin();
		string::const_iterator end = beg;
		while (end != str.end())
		{
			if (++end == str.end() || *end == ' ')
			{
				string word(beg, end);
				if (h1.find(*pit) == h1.end() && h2.find(word) == h2.end())
				{
					h1[*pit] = word;
					h2[word] = *pit;
				}
				else
				{
					if (h1[*pit] != word || h2[word] != *pit)
						return false;
				}
				++pit;

				if (end != str.end())
					beg = end + 1;
			}
		}
		return pit == pattern.end();
	}
};

RUN_TESTCASE(WordPattern)
{
	SolutionWordPattern sln;
	TESTCASE_ASSERT(sln.wordPattern("abba", "dog cat cat dog"));
	TESTCASE_ASSERT(!sln.wordPattern("abba", "dog cat cat fish"));
	TESTCASE_ASSERT(!sln.wordPattern("aaaa", "dog cat cat dog"));
	TESTCASE_ASSERT(!sln.wordPattern("abba", "dog dog dog dog"));
	TESTCASE_ASSERT(!sln.wordPattern("ab", "dog dog"));
}