#include "TestCase.h"

using namespace std;

class StreamChecker
{
protected:
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

	void insertWord(const string& word)
	{
		TrieNode* cur = &m_root;
		for (string::const_reverse_iterator it = word.rbegin(); it != word.rend(); ++it)
		{
			if (!cur->children[*it - 'a'])
				cur->children[*it - 'a'] = new TrieNode();
			cur = cur->children[*it - 'a'];
		}
		cur->word = word;
	}

	TrieNode m_root;
	string m_history;

public:
	StreamChecker(vector<string>& words) {
		for (vector<string>::const_iterator it = words.begin(); it != words.end(); ++it)
			insertWord(*it);
	}

	bool query(char letter) {
		m_history.push_back(letter);

		TrieNode* cur = &m_root;
		for (string::const_reverse_iterator it = m_history.rbegin(); it != m_history.rend(); ++it)
		{
			TrieNode* next = cur->children[*it - 'a'];
			if (next)
			{
				if (!next->word.empty())
					return true;
				else
					cur = next;
			}
			else
				break;
		}

		return false;
	}
};

RUN_TESTCASE(StreamOfCharacters)
{
	/**
	* Your StreamChecker object will be instantiated and called as such:
	* StreamChecker* obj = new StreamChecker(words);
	* bool param_1 = obj->query(letter);
	*/

	StreamChecker streamChecker(vector<string>({ "cd", "f", "kl" }));
	TESTCASE_ASSERT(!streamChecker.query('a'));
	TESTCASE_ASSERT(!streamChecker.query('b'));
	TESTCASE_ASSERT(!streamChecker.query('c'));
	TESTCASE_ASSERT(streamChecker.query('d'));
}