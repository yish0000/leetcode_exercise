#include "TestCase.h"

using namespace std;

class SolutionAdditiveNumber
{
public:
	bool isAdditiveNumber(string num) {
		if (num.size() < 3)
			return false;
		vector<long long> path;
		return dfs(num, path, 0);
	}

	bool dfs(string& num, vector<long long>& path, int start)
	{
		int sz = (int)path.size();
		if (path.size() >= 3 && start >= num.size())
			return true;

		long long n = 0;
		int maxLen = num[start] == '0' ? 1 : 15;
		for (int i = start; i < num.size() && maxLen > 0; i++, maxLen--)
		{
			n = n * 10 + (num[i] - '0');
			if (path.size() >= 2 && path[sz - 2] + path[sz - 1] < n)
				return false;
			else if (path.size() < 2 || path[sz - 2] + path[sz - 1] == n)
			{
				path.push_back(n);
				if (dfs(num, path, i + 1))
					return true;
				path.pop_back();
			}
		}

		return false;
	}

	/*
	string addStrings(string num1, string num2) {
		string& larger = num1;
		string& smaller = num2;
		if (larger.size() < smaller.size())
		{
			std::swap(larger, smaller);
		}
		int carry = 0;
		string::reverse_iterator it1 = larger.rbegin();
		string::reverse_iterator it2 = smaller.rbegin();
		for (; it1 != larger.rend(); ++it1)
		{
			if (it2 != smaller.rend())
			{
				int num1 = *it1 - '0';
				int num2 = *it2 - '0';
				int value = num1 + num2 + carry;
				if (value >= 10)
				{
					value %= 10;
					carry = 1;
				}
				else
					carry = 0;
				*it1 = '0' + value;

				++it2;
			}
			else
			{
				if (carry)
				{
					int num1 = *it1 - '0';
					int value = num1 + carry;
					if (value >= 10)
					{
						value %= 10;
						carry = 1;
					}
					else
						carry = 0;
					*it1 = '0' + value;
				}
				else
					break;
			}
		}
		if (carry)
			larger = "1" + larger;
		return larger;
	}

	bool dfs(string& num, int a, int b, int c)
	{
		if (c >= num.size())
			return false;

		string s1 = num.substr(a, b - a);
		string s2 = num.substr(b, c - b);
		string res = addStrings(s1, s2);
		bool bDiff = false;
		if (num.size() - c < res.size())
			bDiff = true;
		else
		{
			for (int i = 0; i < res.size(); i++)
			{
				if (res[i] != num[c + i])
				{
					bDiff = true;
					break;
				}
			}
		}
		if (bDiff)
		{
			if (c + 1 - b <= num.size() - c && num[b] != '0')
			{
				if (dfs(num, a, b, c + 1))
					return true;
			}

			while (b < (int)num.size() / 2)
			{
				if (dfs(num, a, b + 1, b + 2))
					return true;
				b++;
			}
			return false;
		}
		else
		{
			if (c + (int)res.size() >= num.size())
				return true;
			else
			{
				if (dfs(num, b, c, c + (int)res.size()))
					return true;
				while (b < (int)num.size() / 2)
				{
					if (dfs(num, a, b + 1, b + 2))
						return true;
					b++;
				}
				return false;
			}
		}
	}*/
};

RUN_TESTCASE(AdditiveNumber)
{
	SolutionAdditiveNumber sln;
	TESTCASE_ASSERT(sln.isAdditiveNumber("112358"));
	TESTCASE_ASSERT(sln.isAdditiveNumber("199100199"));
	TESTCASE_ASSERT(sln.isAdditiveNumber("11998910000"));
	TESTCASE_ASSERT(sln.isAdditiveNumber("12122436"));
	TESTCASE_ASSERT(sln.isAdditiveNumber("199111992"));
	TESTCASE_ASSERT(!sln.isAdditiveNumber("199001200"));
	TESTCASE_ASSERT(sln.isAdditiveNumber("12012122436"));
	TESTCASE_ASSERT(sln.isAdditiveNumber("198019823962"));
	TESTCASE_ASSERT(sln.isAdditiveNumber("101020305080130210"));
	TESTCASE_ASSERT(sln.isAdditiveNumber("101020305080130210340"));
	TESTCASE_ASSERT(!sln.isAdditiveNumber("2461016264268110179"));
}