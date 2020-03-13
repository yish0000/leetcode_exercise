#include "TestCase.h"
#include <queue>

using namespace std;

class WordDictionary {

	struct TrieNode
	{
		bool isWord;
		TrieNode* children[26];

		TrieNode()
		{
			isWord = false;
			memset(children, 0, sizeof(children));
		}

		~TrieNode()
		{
			for (auto child : children)
				delete child;
		}
	};

public:
	/** Initialize your data structure here. */
	WordDictionary() {

	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		TrieNode* cur = &root;
		for (auto ch : word)
		{
			if (!cur->children[ch - 'a'])
				cur->children[ch - 'a'] = new TrieNode();
			cur = cur->children[ch - 'a'];
		}
		cur->isWord = true;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		return dfs(word, 0, &root);
	}

	bool dfs(string& word, int cur, TrieNode* node)
	{
		if (cur == word.size())
			return node->isWord;

		char ch = word[cur];
		if (ch == '.')
		{
			for (int i = 0; i < 26; i++)
			{
				if (!node->children[i])
					continue;

				if (dfs(word, cur + 1, node->children[i]))
					return true;
			}

			return false;
		}
		else
		{
			if (node->children[ch - 'a'])
				return dfs(word, cur + 1, node->children[ch - 'a']);
			else
				return false;
		}
	}

protected:
	TrieNode root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
RUN_TESTCASE(AddAndSearchWord)
{
	WordDictionary dic;
	dic.addWord("bad");
	dic.addWord("dad");
	dic.addWord("mad");
	TESTCASE_ASSERT(!dic.search("pad"));	// -> false
	TESTCASE_ASSERT(dic.search("bad"));	// -> true
	TESTCASE_ASSERT(dic.search(".ad"));	// -> true
	TESTCASE_ASSERT(dic.search("b.."));	// -> true
}