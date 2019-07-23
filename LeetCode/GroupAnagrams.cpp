#include "TestCase.h"
#include <unordered_map>

using namespace std;

class SolutionGroupAnagrams {
public:
	const int primes[26] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101 };
	uint32_t calc_hash(const string& str)
	{
		uint32_t hash = 1;
		for (string::const_iterator it = str.begin(); it != str.end(); ++it)
			hash *= primes[((*it) - 'a')];
		return hash;
	}

	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<uint32_t, vector<string>> res;
		vector<string>::const_iterator it = strs.begin();
		for (; it != strs.end(); ++it)
		{
			uint32_t hash = calc_hash(*it);
			unordered_map<uint32_t, vector<string>>::iterator it3 = res.find(hash);
			if (it3 != res.end())
				it3->second.push_back(*it);
			else
			{
				res[hash] = vector<string>();
				res[hash].push_back(*it);
			}
		}
		vector<vector<string>> ret;
		for (unordered_map<uint32_t, vector<string>>::iterator it3 = res.begin(); it3 != res.end(); ++it3)
			ret.emplace_back(it3->second);
		return ret;
	}
};

RUN_TESTCASE(GroupAnagrams)
{
	vector<string> arr = { "eat", "tea", "tan", "ate", "nat", "bat" };
	vector<vector<string>> res = 
	{
        {"bat"},
        {"tan", "nat"},
        {"eat", "tea", "ate"},
	};

	SolutionGroupAnagrams sln;
	TESTCASE_ASSERT(sln.groupAnagrams(arr) == res);
}
