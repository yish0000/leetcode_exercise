#include "TestCase.h"

using namespace std;

class SolutionMaximumProductOfWordLengths
{
public:
	int maxProduct(vector<string>& words) {
		int max_p = 0;
		
		vector<int> bits(words.size(), 0);
		for (size_t i = 0; i < words.size(); i++)
		{
			for (auto c : words[i])
				bits[i] |= 1 << (c - 'a');
		}

		for (int i = 0; i < words.size(); i++)
		{
			for (int j = i + 1; j < words.size(); j++)
			{
				if ((bits[i] & bits[j]) == 0)
					max_p = std::max(max_p, (int)words[i].size()*(int)words[j].size());
			}
		}
		return max_p;
	}
};

RUN_TESTCASE(MaximumProductOfWordLengths)
{
	SolutionMaximumProductOfWordLengths sln;

	vector<string> arr1 = { "abcw","baz","foo","bar","xtfn","abcdef" };
	TESTCASE_ASSERT(sln.maxProduct(arr1) == 16);

	vector<string> arr2 = { "a","ab","abc","d","cd","bcd","abcd" };
	TESTCASE_ASSERT(sln.maxProduct(arr2) == 4);

	vector<string> arr3 = { "a","aa","aaa","aaaa" };
	TESTCASE_ASSERT(sln.maxProduct(arr3) == 0);
}