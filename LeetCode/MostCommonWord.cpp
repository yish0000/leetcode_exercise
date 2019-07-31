#include "TestCase.h"
#include <unordered_map>

using namespace std;

class SolutionMostCommonWord
{
public:
	string mostCommonWord(string paragraph, vector<string>& banned) {
		string result;
		int max_count = 0;
		string str;
		unordered_map<string, int> tokens;
		for (size_t i = 0; i < banned.size(); i++)
			tokens.emplace(banned[i], -1);
		string::const_iterator it = paragraph.begin();
		string::const_iterator end = paragraph.end();
		while (it != end)
		{
			if (!str.empty())
			{
				if (!isalpha(*it))
				{
					if (tokens[str] >= 0)
					{
						int count = ++tokens[str];
						if (count > max_count)
						{
							result = str;
							max_count = count;
						}
					}
					str.clear();
				}
				else
					str.push_back(tolower(*it));
			}
			else
			{
				if (isalpha(*it))
					str.push_back(tolower(*it));
			}

			++it;
		}

		if (str.size() > 0)
		{
			if (tokens[str] >= 0)
			{
				int count = ++tokens[str];
				if (count > max_count)
				{
					result = str;
					max_count = count;
				}
			}
		}

		return result;
	}
};

RUN_TESTCASE(MostCommonWord)
{
	SolutionMostCommonWord sln;
	TESTCASE_ASSERT(sln.mostCommonWord("Bob hit a ball, the hit BALL flew far after it was hit.", vector<string>({"hit"})) == "ball");
	TESTCASE_ASSERT(sln.mostCommonWord("Bob", vector<string>()) == "bob");
}