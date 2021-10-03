//
//  IslandPerimeter.cpp
//  leetcode_exercise
//
//  Created by zhouchu hou on 2021/10/3.
//  Copyright © 2021 侯周楚. All rights reserved.
//

#include "TestCase.h"
#include <queue>

using namespace std;

class SolutionIslandPerimeter
{
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;

        int permiter = 0;
        vector<vector<bool>> s(grid.size(), vector<bool>(grid[0].size(), false));
        dfs(grid,s, permiter, 0, 0);
        return permiter;
    }
    
    bool is_island(vector<vector<int>>& grid, int x, int y)
    {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size())
            return false;
        
        return grid[x][y] == 1;
    }
    
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& s, int& perimeter, int x, int y)
    {
        if (s[x][y])
            return;
        s[x][y] = true;
        if (grid[x][y] == 1)
        {
            if (!is_island(grid, x-1, y))
                perimeter += 1;
            if (!is_island(grid, x, y-1))
                perimeter += 1;
            if (!is_island(grid, x+1, y))
                perimeter += 1;
            if (!is_island(grid, x, y+1))
                perimeter += 1;
        }
        if (x-1 >= 0)
            dfs(grid, s, perimeter, x-1, y);
        if (x+1 < grid.size())
            dfs(grid, s, perimeter, x+1, y);
        if (y-1 >= 0)
            dfs(grid, s, perimeter, x, y-1);
        if (y+1 < grid[0].size())
            dfs(grid, s, perimeter, x, y+1);
    }
};

RUN_TESTCASE(IslandPerimeter)
{
    SolutionIslandPerimeter sln;
    
    vector<vector<int>> arr1 = {
        {0,1,0,0},
        {1,1,1,0},
        {0,1,0,0},
        {1,1,0,0},
    };
    TESTCASE_ASSERT(sln.islandPerimeter(arr1) == 16);
    
    vector<vector<int>> arr2 = {{1}};
    TESTCASE_ASSERT(sln.islandPerimeter(arr2) == 4);
    
    vector<vector<int>> arr3 = {{1,0}};
    TESTCASE_ASSERT(sln.islandPerimeter(arr3) == 4);
}
