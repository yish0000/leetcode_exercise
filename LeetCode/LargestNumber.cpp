#include "TestCase.h"

using namespace std;

class SolutionLargestNumber
{
public:
	string largestNumber(vector<int>& nums) {
		vector<string> arr;
		for (auto n : nums)
		{
			string s;
			if (n == 0)
				s = "0";
			else
			{
				while (n > 0)
				{
					s.push_back(n % 10 + '0');
					n /= 10;
				}

				std::reverse(s.begin(), s.end());
			}
			arr.push_back(s);
		}

		std::sort(arr.begin(), arr.end(), [](string& s1, string& s2) {
			string a1 = s1 + s2;
			string a2 = s2 + s1;
			return a1 < a2;
		});

		if (arr.back() == "0")
			return "0";

		string str;
		vector<string>::const_reverse_iterator it = arr.rbegin();
		while (it != arr.rend())
			str += *it++;

		return str;
	}
};

RUN_TESTCASE(LargestNumber)
{
	SolutionLargestNumber sln;

	vector<int> arr1 = { 10,2 };
	TESTCASE_ASSERT(sln.largestNumber(arr1) == "210");

	vector<int> arr2 = { 3,30,34,5,9 };
	TESTCASE_ASSERT(sln.largestNumber(arr2) == "9534330");
}