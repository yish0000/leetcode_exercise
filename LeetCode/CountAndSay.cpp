#include "TestCase.h"

using namespace std;

class SolutionCountAndSay {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";

        string res;
        string pre = countAndSay(n-1);
        char last = pre[0];
        int count = 1;
        for (size_t i=1; i<pre.size(); i++)
        {
            if (pre[i] == last)
                count++;
            else
            {
                res.push_back('0' + count);
                res.push_back(last);
                last = pre[i];
                count = 1;
            }
        }
        
        res.push_back('0' + count);
        res.push_back(last);
        return res;
    }
};

RUN_TESTCASE(CountAndSay)
{
    SolutionCountAndSay sln;
    TESTCASE_ASSERT(sln.countAndSay(1) == "1");
    TESTCASE_ASSERT(sln.countAndSay(2) == "11");
    TESTCASE_ASSERT(sln.countAndSay(3) == "21");
    TESTCASE_ASSERT(sln.countAndSay(4) == "1211");
    TESTCASE_ASSERT(sln.countAndSay(5) == "111221");
    TESTCASE_ASSERT(sln.countAndSay(6) == "312211");
    TESTCASE_ASSERT(sln.countAndSay(7) == "13112221");
    TESTCASE_ASSERT(sln.countAndSay(8) == "1113213211");
}
