#include "TestCase.h"
#include <unordered_map>

using namespace std;

class Solution4SumII
{
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> map;
        for (int i=0; i<A.size(); i++)
        {
            for (int j=0; j<B.size(); j++)
                map[A[i]+B[j]]++;
        }
        int count = 0;
        for (int i=0; i<C.size(); i++)
        {
            for (int j=0; j<D.size(); j++)
            {
                int sum = C[i] + D[j];
                unordered_map<int, int>::const_iterator it = map.find(-sum);
                if (it != map.end())
                    count += it->second;
            }
        }
        return count;
    }
};

RUN_TESTCASE(4SumII)
{
    Solution4SumII sln;
    
    vector<int> A1 = {1,2};
    vector<int> B1 = {-2,-1};
    vector<int> C1 = {-1,2};
    vector<int> D1 = {0,2};
    TESTCASE_ASSERT(sln.fourSumCount(A1, B1, C1, D1) == 2);
}
