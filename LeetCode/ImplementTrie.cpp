#include "TestCase.h"

using namespace std;

class Trie {

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
			for (auto child : children)
				delete child;
		}
	};

public:
	/** Initialize your data structure here. */
	Trie() {

	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		TrieNode* cur = &root;
		for (char ch : word)
		{
			if (!cur->children[ch - 'a'])
				cur->children[ch - 'a'] = new TrieNode();
			cur = cur->children[ch - 'a'];
		}
		cur->word = word;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		TrieNode* cur = &root;
		for (char ch : word)
		{
			if (!cur->children[ch - 'a'])
				return false;
			cur = cur->children[ch - 'a'];
		}
		return cur->word == word;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		TrieNode* cur = &root;
		for (char ch : prefix)
		{
			if (!cur->children[ch - 'a'])
				return false;
			cur = cur->children[ch - 'a'];
		}
		return true;
	}

protected:
	TrieNode root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
RUN_TESTCASE(ImplementTrie)
{
	Trie trie;
	trie.insert("apple");
	TESTCASE_ASSERT(trie.search("apple"));   // returns true
	TESTCASE_ASSERT(!trie.search("app"));     // returns false
	TESTCASE_ASSERT(trie.startsWith("app")); // returns true
	trie.insert("app");
	TESTCASE_ASSERT(trie.search("app"));     // returns true
}