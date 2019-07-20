#include "TestCase.h"

using namespace std;

class SolutionLongestCommonPrefix {
public:
    string longestCommonPrefixBinary(vector<string>& strs) {
        if (strs.empty()) return "";
        return longestCommonPrefixHelper(strs, 0, (int)strs.size()-1);
    }
    
    string twoStringCommonPrefix(string& str1, string& str2)
    {
        string res;
        for (size_t i=0; i<str1.size(); i++)
        {
            char ch = str1[i];
            if (str2.size() >= i + 1 && str2[i] == ch)
                res.push_back(ch);
            else
                break;
        }
        return res;
    }
    
    string longestCommonPrefixHelper(vector<string>& strs, int beg, int end) {
        if (end - beg <= 1)
        {
            if (beg == end)
                return strs[beg];
            else
                return twoStringCommonPrefix(strs[beg], strs[end]);
        }
        else
        {
            int mid = beg + (end - beg) / 2;
            string res1 = longestCommonPrefixHelper(strs, beg, mid);
            string res2 = longestCommonPrefixHelper(strs, mid+1, end);
            return twoStringCommonPrefix(res1, res2);
        }
    }

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
