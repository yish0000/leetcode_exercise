#include "TestCase.h"

using namespace std;

class SolutionWordSearchII
{
public:
	struct TrieNode
	{
		string word;
		TrieNode* children[26];

		TrieNode()
		{
			memset(children, 0, sizeof(children));
		}

		~TrieNode()
		{
			for (int i = 0; i < 26; i++)
			{
				if (children[i])
					delete children[i];
			}
		}
	};

	void insertWord(TrieNode* root, const string& word)
	{
		TrieNode* cur = root;
		for (string::const_iterator it = word.begin(); it != word.end(); ++it)
		{
			if (!cur->children[*it - 'a'])
				cur->children[*it - 'a'] = new TrieNode();
			cur = cur->children[*it - 'a'];
		}
		cur->word = word;
	}

	const int dx[4] = { -1,1,0,0 };
	const int dy[4] = { 0,0,-1,1 };
	int w, h;

	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		vector<string> res;
		TrieNode root;

		if (!board.size() || !board[0].size() || !words.size())
			return res;

		// build trie.
		for (size_t i = 0; i < words.size(); i++)
		{
			insertWord(&root, words[i]);
		}

		h = (int)board.size();
		w = (int)board[0].size();
		vector<vector<bool>> visited(h, vector<bool>(w, false));
		for (int j = 0; j < h; j++)
		{
			for (int i = 0; i < w; i++)
			{
				dfs(res, board, visited, i, j, &root);
			}
		}

		std::sort(res.begin(), res.end());
		for (size_t i = 0; i < res.size(); i++)
		{
			if (i > 0 && res[i] == res[i - 1])
			{
				res.erase(res.begin() + i);
				i--;
			}
		}

		return res;
	}

	void dfs(vector<string>& res, vector<vector<char>>& board, vector<vector<bool>>& visited, int x, int y, TrieNode* root)
	{
		if (!root->word.empty())
			res.push_back(root->word);

		if (x < 0 || x >= w || y < 0 || y >= h || visited[y][x] || !root->children[board[y][x] - 'a'])
			return;

		for (int i = 0; i < 4; i++)
		{
			visited[y][x] = true;
			dfs(res, board, visited, x+dx[i], y+dy[i], root->children[board[y][x]-'a']);
			visited[y][x] = false;
		}
	}
};

RUN_TESTCASE(WordSearchII)
{
	SolutionWordSearchII sln;

	vector<vector<char>> board = {
		{'o','a','a','n' },
		{'e','t','a','e' },
		{'i','h','k','r' },
		{'i','f','l','v' },
	};
	vector<string> words = { "oath","pea","eat","rain" };
	vector<string> ans = { "eat","oath" };
	TESTCASE_ASSERT(sln.findWords(board, words) == ans);
}