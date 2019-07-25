#include "TestCase.h"

using namespace std;

class Solution8Queens
{
public:
    int eightQueens()
    {
        int totalCount = 0;
        vector<vector<char>> chess(8, vector<char>(8, '*'));
        findResult(chess, totalCount, 0);
        return totalCount;
    }
    
    void findResult(vector<vector<char>>& chess, int& count, int row)
    {
        if (row > 7)
        {
            //printResult(chess);
            count++;
            return;
        }
        
        for (int i=0; i<8; i++)
        {
            if (check(chess, row, i))
            {
                chess[row][i] = 'q';
                findResult(chess, count, row+1);
                chess[row][i] = '*';
            }
        }
    }
    
    bool check(vector<vector<char>>& chess, int row, int col)
    {
        int x1 = row, x2 = row;
        int y1 = col, y2 = col;
        for (int i=0; i<8; i++)
        {
            if (chess[row][i] == 'q' && i != col)
                return false;
            if (chess[i][col] == 'q' && i != row)
                return false;
            
            --x1; --y1; ++x2; ++y2;
            if (x1 >= 0 && y1 >= 0 && chess[x1][y1] == 'q')
                return false;
            if (x2 < 8 && y2 < 8 && chess[x2][y2] == 'q')
                return false;
            if (x1 >= 0 && y2 < 8 && chess[x1][y2] == 'q')
                return false;
            if (x2 < 8 && y1 >= 0 && chess[x2][y1] == 'q')
                return false;
        }
        return true;
    }
    
    void printResult(vector<vector<char>>& result)
    {
        for (int i=0; i<8; i++)
        {
            for (int j=0; j<8; j++)
            {
                std::cout << result[i][j] << " ";
            }
            
            std::cout << std::endl;
        }
        
        std::cout << std::endl;
    }
};

RUN_TESTCASE(8Queens)
{
    Solution8Queens sln;
    TESTCASE_ASSERT(sln.eightQueens() == 92);
}
