#include "TestCase.h"
#include <map>

using namespace std;

class SolutionKClosestPointsToOrigin
{
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> result;
        map<int, vector<int>> closest_map;
        for (int i=0; i<(int)points.size(); ++i)
        {
            int dist = points[i][0]*points[i][0]+points[i][1]*points[i][1];
            closest_map[dist].push_back(i);
        }
        map<int, vector<int>>::const_iterator it = closest_map.begin();
        for (; it != closest_map.end(); ++it)
        {
            for (size_t j=0; j<it->second.size(); j++)
            {
                if (K-- > 0)
                    result.emplace_back(points[it->second[j]]);
            }
        }
        return result;
    }
};

RUN_TESTCASE(KClosestPointsToOrigin)
{
    SolutionKClosestPointsToOrigin sln;
    
    vector<vector<int>> arr1 = {{1,3},{-2,2}};
    vector<vector<int>> res1 = {{-2,2}};
    TESTCASE_ASSERT(sln.kClosest(arr1, 1) == res1);
    
    vector<vector<int>> arr2 = {{3,3},{5,-1},{-2,4}};
    vector<vector<int>> res2 = {{3,3},{-2,4}};
    vector<vector<int>> ret2 = sln.kClosest(arr2, 2);
    TESTCASE_ASSERT(vectorComboEqual(ret2, res2));
}
