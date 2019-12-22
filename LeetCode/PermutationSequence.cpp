#include "TestCase.h"

using namespace std;

class SolutionPermutationSequence
{
public:
	string getPermutation(int n, int k) {
		string str;
		for (int i = 1; i <= n; i++)
			str.push_back('0' + i);
		while (--k > 0)
			std::next_permutation(str.begin(), str.end());
		return str;
	}
};

RUN_TESTCASE(PermutationSequence)
{
	SolutionPermutationSequence sln;
	TESTCASE_ASSERT(sln.getPermutation(4, 9) == "2314");
}