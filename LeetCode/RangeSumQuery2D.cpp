//
//  RangeSumQuery2D.cpp
//  leetcode_exercise
//
//  Created by zhouchu hou on 2020/6/7.
//  Copyright © 2020 侯周楚. All rights reserved.
//

#include "TestCase.h"

using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        sums.resize(matrix.size() + 1);
        sums[0].resize(matrix[0].size() + 1);
        for (int i=0; i<matrix.size(); i++)
        {
            sums[i+1].resize(matrix[i].size() + 1);
            for (int j=0; j<matrix[i].size(); j++)
            {
                if (j == 0 && i == 0)
                    sums[i+1][j+1] = sums[i][j];
                else if (i == 0)
                    sums[i+1][j+1] = sums[i+1][j] + matrix[i][j];
                else if (j == 0)
                    sums[i+1][j+1] = sums[i][j+1] + matrix[i][j];
                else
                    sums[i+1][j+1] = sums[i][j+1] + sums[i+1][j] - sums[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2+1][col2+1] - sums[row1][col2+1] - sums[row2+1][col1] + sums[row1][col1];
    }
    
protected:
    vector<vector<int>> sums;
};

/**
* Your NumMatrix object will be instantiated and called as such:
* NumMatrix* obj = new NumMatrix(matrix);
* int param_1 = obj->sumRegion(row1,col1,row2,col2);
*/
RUN_TESTCASE(RangeSumQuery2D)
{
    vector<vector<int>> arr1 = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5},
    };
    
    NumMatrix sln(arr1);
    int val = sln.sumRegion(2, 1, 4, 3);
    TESTCASE_ASSERT(val == 8);
    val = sln.sumRegion(1, 1, 2, 2);
    TESTCASE_ASSERT(val == 11);
    val = sln.sumRegion(1, 2, 2, 4);
    TESTCASE_ASSERT(val == 12);
}
