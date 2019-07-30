#include "TestCase.h"

using namespace std;

class SolutionReverseString
{
public:
	void reverseString(vector<char>& s) {
		if (s.empty()) return;
		vector<char>::iterator l = s.begin();
		vector<char>::iterator r = s.end() - 1;
		while (l < r)
		{
			std::swap(*l, *r);
			++l; --r;
		}
	}
};

RUN_TESTCASE(ReverseString)
{
	SolutionReverseString sln;
	vector<char> arr1 = { 'h','e','l','l','o' };
	sln.reverseString(arr1);
	TESTCASE_ASSERT(arr1 == vector<char>({ 'o','l','l','e','h' }));
	vector<char> arr2 = { 'H','a','n','n','a','h' };
	sln.reverseString(arr2);
	TESTCASE_ASSERT(arr2 == vector<char>({ 'h','a','n','n','a','H' }));
}