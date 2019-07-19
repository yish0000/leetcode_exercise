#include "TestCase.h"

using namespace std;

class SolutionLongestCommonPrefix {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if (strs.empty()) return res;
        for (size_t i=0; i<strs[0].size(); i++)
        {
            char ch = strs[0][i];
            bool same = true;
            for(size_t j=1; j<strs.size(); j++)
            {
                if (strs[j].size() < i + 1 || strs[j][i] != ch)
                    same = false;
            }
            if (same)
                res.push_back(ch);
            else
                break;
        }
        return res;
    }
};

RUN_TESTCASE(LongestCommonPrefix)
{
    SolutionLongestCommonPrefix sln;
    vector<string> arr1 = {
        "flower","flow","flight"
    };
    TESTCASE_ASSERT(sln.longestCommonPrefix(arr1) == "fl");
    vector<string> arr2 = {
        "dog","racecar","car"
    };
    TESTCASE_ASSERT(sln.longestCommonPrefix(arr2) == "");
}
