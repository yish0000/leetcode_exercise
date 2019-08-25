#include "TestCase.h"
#include "BinaryTreeCommon.h"

using namespace std;

class SolutionTreap
{
public:
    struct TreapNode
    {
        int x, y;
        TreapNode* left;
        TreapNode* right;
        
        TreapNode(int _x, int _y) : x(_x), y(_y), left(NULL), right(NULL)
        {
        }
    };
    
    bool isHeap(TreapNode* root)
    {
        if (!root) return true;
        if (!root->left && !root->right)
            return true;
        if ((root->left && root->left->y >= root->y) ||
            (root->right && root->right->y >= root->y))
            return false;
        else
            return isHeap(root->left) && isHeap(root->right);
    }
    
    bool isBST(TreapNode* root)
    {
        if (!root) return true;
        if (!root->left && !root->right)
            return true;
        
        int curMax = 0;
        return isBSTHelper(root, curMax);
    }
    
    bool isBSTHelper(TreapNode* root, int& curMax)
    {
        if (!root) return true;
        if (!isBSTHelper(root->left, curMax))
            return false;
        if (root->x > curMax)
            curMax = root->x;
        else
            return false;
        return isBSTHelper(root->right, curMax);
    }
    
    TreapNode* GenTreap(vector<pair<int, int>>& input)
    {
        if (input.empty()) return NULL;
        std::sort(input.begin(), input.end(), [](pair<int, int>& a, pair<int, int>& b) -> bool {
            return a.second > b.second;
        });
        TreapNode* root = new TreapNode(input[0].first, input[0].second);
        for (size_t i=1; i<input.size(); i++)
        {
            TreapNode* node = new TreapNode(input[i].first, input[i].second);
            TreapNode* cur = root;
            while(cur)
            {
                if (node->x < cur->x)
                {
                    if (cur->left)
                        cur = cur->left;
                    else
                    {
                        cur->left = node;
                        break;
                    }
                }
                else
                {
                    if (cur->right)
                        cur = cur->right;
                    else
                    {
                        cur->right = node;
                        break;
                    }
                }
            }
        }
        return root;
    }
    
    void FreeTree(TreapNode* root)
    {
        if (!root) return;
        FreeTree(root->left);
        FreeTree(root->right);
        delete root;
    }
};

RUN_TESTCASE(Treap)
{
    SolutionTreap sln;
    
    vector<pair<int, int>> arr1 = {
        {1, 4}, {8, 5}, {3, 6}, {10, -1}, {4, 7}
    };
    SolutionTreap::TreapNode* t1 = sln.GenTreap(arr1);
    TESTCASE_ASSERT(sln.isBST(t1) && sln.isHeap(t1));
    sln.FreeTree(t1);

    vector<pair<int, int>> arr2 = {
        {1, 6}, {3, 7}, {2, 4}
    };
    SolutionTreap::TreapNode* t2 = sln.GenTreap(arr2);
    TESTCASE_ASSERT(sln.isBST(t2) && sln.isHeap(t2));
    sln.FreeTree(t2);
}
