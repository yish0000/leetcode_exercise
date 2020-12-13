//
//  ReconstructItinerary.cpp
//  leetcode_exercise
//
//  Created by zhouchu hou on 2020/12/13.
//  Copyright © 2020 侯周楚. All rights reserved.
//

#include "TestCase.h"
#include <map>
#include <queue>

using namespace std;

class SolutionReconstructItinerary
{
public:
    map<string, priority_queue<string, vector<string>, greater<string>>> m;
    vector<string> itinerary;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        m.clear();
        itinerary.clear();
        for (auto& ticket : tickets)
        {
            m[ticket[0]].push(ticket[1]);
        }
        dfs("JFK");
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
    
    void dfs(string from)
    {
        auto it = m.find(from);
        if (it != m.end())
        {
            while (it->second.size() > 0)
            {
                string to = it->second.top();
                it->second.pop();
                dfs(to);
            }
        }
        itinerary.push_back(from);
    }
};

RUN_TESTCASE(ReconstructItinerary)
{
    SolutionReconstructItinerary sln;
    vector<vector<string>> arr1 = {
        {"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}
    };
    vector<string> ret1 = {"JFK", "MUC", "LHR", "SFO", "SJC"};
    TESTCASE_ASSERT(sln.findItinerary(arr1) == ret1);
    
    vector<vector<string>> arr2 = {
        {"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}
    };
    vector<string> ret2 = {"JFK","ATL","JFK","SFO","ATL","SFO"};
    TESTCASE_ASSERT(sln.findItinerary(arr2) == ret2);
}
