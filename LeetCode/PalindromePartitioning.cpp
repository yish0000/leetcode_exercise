#include "TestCase.h"

using namespace std;

class SolutionPalindromePartitioning
{
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> arr;
		vector<string> cur;
		partitionHelper(arr, s, cur, 0);
		return arr;
	}

	void partitionHelper(vector<vector<string>>& out, string& str, vector<string>& cur, int s)
	{
		if (s == str.length())
		{
			out.push_back(cur);
			return;
		}

		int remainLen = (int)str.length() - s;
		for (int i = 1; i <= remainLen; i++)
		{
			if (isPalindromeString(str, s, s + i - 1))
			{
				cur.push_back(str.substr(s, i));
				partitionHelper(out, str, cur, s + i);
				cur.pop_back();
			}
		}
	}

	bool isPalindromeString(string& str, int beg, int end)
	{
		if (str.empty())
			return false;

		string::const_iterator l = str.begin() + beg;
		string::const_iterator r = str.begin() + end;
		while (l < r)
		{
			if (*l != *r)
				return false;

			l++;
			r--;
		}

		return true;
	}
};

RUN_TESTCASE(PalindromePartitioning)
{
	SolutionPalindromePartitioning sln;

	vector<vector<string>> ret1 = {
		{"aba","cc"},
		{"aba","c","c"},
		{"a","b","a","cc"},
		{"a","b","a","c","c"},
	};
	TESTCASE_ASSERT(vectorComboEqual(sln.partition("abacc"), ret1));
}