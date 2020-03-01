#include "TestCase.h"

using namespace std;

class SolutionLetterCasePermutation
{
public:
	vector<string> letterCasePermutation(string S) {
		vector<string> arr;
		backtrack(arr, S, 0);
		return arr;
	}

	void backtrack(vector<string>& arr, string& S, int pos)
	{
		if (pos == S.length())
		{
			arr.push_back(S);
			return;
		}

		if (isalpha(S[pos]))
		{
			S[pos] = toupper(S[pos]);
			backtrack(arr, S, pos + 1);
			S[pos] = tolower(S[pos]);
			backtrack(arr, S, pos + 1);
		}
		else
		{
			backtrack(arr, S, pos + 1);
		}
	}
};

RUN_TESTCASE(LetterCasePermutation)
{
	SolutionLetterCasePermutation sln;

	vector<string> arr1 = { "a1b2", "a1B2", "A1b2", "A1B2" };
    vector<string> ret1 = sln.letterCasePermutation("a1b2");
	TESTCASE_ASSERT(vectorComboEqual(ret1, arr1));

	vector<string> arr2 = { "3z4", "3Z4" };
    vector<string> ret2 = sln.letterCasePermutation("3z4");
	TESTCASE_ASSERT(vectorComboEqual(ret2, arr2));

	vector<string> arr3 = { "12345" };
    vector<string> ret3 = sln.letterCasePermutation("12345");
	TESTCASE_ASSERT(vectorComboEqual(ret3, arr3));
}
