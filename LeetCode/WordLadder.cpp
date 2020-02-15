#include "TestCase.h"
#include <unordered_map>
#include <queue>

using namespace std;

class SolutionWordLadder
{
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		int shortest = std::numeric_limits<int>::max();

		vector<string> wildcards;
		unordered_map<string, vector<string>> all_combo_dic;
		for (auto& word : wordList)
		{
			getWordWildcard(word, wildcards);

			for (auto& wildcard : wildcards)
				all_combo_dic[wildcard].push_back(word);
		}

		unordered_map<string, bool> visited;
		queue<pair<string, int>> q;
		q.push(make_pair(beginWord, 1));
		while (q.size() > 0)
		{
			pair<string, int> item = q.front();
			q.pop();

			visited[item.first] = true;

			if (item.first == endWord)
				shortest = std::min(shortest, item.second);
			
			getWordWildcard(item.first, wildcards);
			for (auto& wildcard : wildcards)
			{
				for (auto& s : all_combo_dic[wildcard])
				{
					if (!visited[s])
						q.push(make_pair(s, item.second + 1));
				}
			}
		}

		return shortest == numeric_limits<int>::max() ? 0 : shortest;
	}

	void getWordWildcard(string& word, vector<string>& wildcards)
	{
		wildcards.clear();
		for (int i=0; i<word.size(); i++)
		{
			string wildcard = word;
			wildcard[i] = '*';
			wildcards.push_back(wildcard);
		}
	}
};

RUN_TESTCASE(WordLadder)
{
	SolutionWordLadder sln;

	vector<string> arr1 = { "hot", "dot", "dog", "lot", "log", "cog" };
	TESTCASE_ASSERT(sln.ladderLength("hit", "cog", arr1) == 5);

	vector<string> arr2 = { "hot", "dot", "dog", "lot", "log" };
	TESTCASE_ASSERT(sln.ladderLength("hit", "cog", arr2) == 0);

	vector<string> arr3 = {
		"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av",
		"sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr",
		"po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as",
		"fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz",
		"no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st",
		"er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr",
		"pa","he","lr","sq","ye" };
	TESTCASE_ASSERT(sln.ladderLength("qa", "sq", arr3));
}