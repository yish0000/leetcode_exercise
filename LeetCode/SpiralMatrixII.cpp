#include "TestCase.h"

using namespace std;

class SolutionSpiralMatrixII
{
public:
    const int dirs[4][2] = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1},
    };
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> m(n, vector<int>(n, 0));
        int p_x = 0, p_y = 0;
        int dir = 0;
        int dir_x = dirs[dir][0];
        int dir_y = dirs[dir][1];
        for (int i=1; i<=n*n; i++)
        {
            m[p_y][p_x] = i;
            
            if (p_x + dir_x >= n || p_x + dir_x < 0 || p_y + dir_y >= n || p_y + dir_y < 0 || m[p_y + dir_y][p_x + dir_x] != 0)
            {
                ++dir;
                if (dir >= 4)
                    dir = 0;
                dir_x = dirs[dir][0];
                dir_y = dirs[dir][1];
            }
            
            p_x += dir_x;
            p_y += dir_y;
        }
        return m;
    }
};

RUN_TESTCASE(SpiralMatrixII)
{
    SolutionSpiralMatrixII sln;

    vector<vector<int>> ret1 = {
        {1, 2, 3},
        {8, 9, 4},
        {7, 6, 5}
    };
    TESTCASE_ASSERT(sln.generateMatrix(3) == ret1);
}
