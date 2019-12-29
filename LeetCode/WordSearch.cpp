#include "TestCase.h"

using namespace std;

class SolutionWordSearch
{
public:
	const int dx[4] = { -1,1,0,0 };
	const int dy[4] = { 0,0,-1,1 };
	int w, h;
	string searchWord;

	bool exist(vector<vector<char>>& board, string word) {
		if (!board.size() || !board[0].size() || word.empty())
			return false;

		h = (int)board.size();
		w = (int)board[0].size();
		vector<vector<bool>> visited(h, vector<bool>(w, false));
		searchWord = word;

		for (int j = 0; j < h; j++)
		{
			for (int i = 0; i < w; i++)
			{
				string found;
				if (dfs(found, board, visited, i, j, 0))
					return true;
			}
		}

		return false;
	}

	bool dfs(string& found, vector<vector<char>>& board, vector<vector<bool>>& visited, int x, int y, int depth)
	{
		if (x < 0 || x >= w || y < 0 || y >= h || visited[y][x])
			return false;

		found.push_back(board[y][x]);
		if (searchWord == found)
			return true;
		if (searchWord[depth] == found.back())
		{
			for (int i = 0; i < 4; i++)
			{
				visited[y][x] = true;
				if (dfs(found, board, visited, x + dx[i], y + dy[i], depth + 1))
					return true;
				visited[y][x] = false;
			}
		}

		found.pop_back();
		return false;
	}
};

RUN_TESTCASE(WordSearch)
{
	SolutionWordSearch sln;

	vector<vector<char>> arr = {
		{'A','B','C','E'},
		{'S','F','C','S'},
		{'A','D','E','E'}
	};
	TESTCASE_ASSERT(sln.exist(arr, "ABCCED"));
	TESTCASE_ASSERT(sln.exist(arr, "SEE"));
	TESTCASE_ASSERT(!sln.exist(arr, "ABCB"));

	vector<vector<char>> arr2 = {
		{'F','Y','C','E','N','R','D'},
		{'K','L','N','F','I','N','U'},
		{'A','A','A','R','A','H','R'},
		{'N','D','K','L','P','N','E'},
		{'A','L','A','N','S','A','P'},
		{'O','O','G','O','T','P','N'},
		{'H','P','O','L','A','N','O'},
	};
	TESTCASE_ASSERT(!sln.exist(arr2, "poland"));
}