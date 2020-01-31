#include "TestCase.h"
#include "BinaryTreeCommon.h"
#include <stack>
#include <queue>

using namespace std;

class SolutionSymmetricTree : public BinaryTreeCommmon
{
public:
	bool isSymmetricIterative(TreeNode* root) {
		if (!root)
			return true;

		if (!root->left && !root->right)
			return true;
		
		queue<TreeNode*> q;
		stack<TreeNode*> s;
		q.push(root);
		s.push(root);
		while (q.size() > 0)
		{
			TreeNode* curNode = q.front();
			q.pop();

			if (s.size() && (s.top() == curNode || (s.top() && curNode && s.top()->val == curNode->val)))
				s.pop();
			else
				s.push(curNode);

			if (curNode)
			{
				if (!curNode->left && !curNode->right)
					q.push(nullptr);
				else
				{
					q.push(curNode->left);
					q.push(curNode->right);
				}
			}
		}

		return s.empty();
	}

	bool isSymmetric(TreeNode* root) {
		if (!root)
			return true;
		return isMirror(root->left, root->right);
	}

	bool isMirror(TreeNode* l, TreeNode* r)
	{
		if (!l && !r)
			return true;
		else if (l && r)
		{
			if (l->val != r->val)
				return false;
			return isMirror(l->right, r->left) && isMirror(l->left, r->right);
		}
		else
			return false;
	}
};

RUN_TESTCASE(SymmetricTree)
{
	SolutionSymmetricTree sln;

	vector<string> arr1 = { "1","2","2","3","4","4","3" };
	TreeNode* tr1 = sln.MakeTree(arr1);
	TESTCASE_ASSERT(sln.isSymmetric(tr1));
	sln.FreeTree(tr1);

	vector<string> arr2 = { "1","2","2","null","3","null","3" };
	TreeNode* tr2 = sln.MakeTree(arr2);
	TESTCASE_ASSERT(!sln.isSymmetric(tr2));
	sln.FreeTree(tr2);

	vector<string> arr3 = { "2","3","3","4","5","5","4","null","null","8","9","null","null","9","8" };
	TreeNode* tr3 = sln.MakeTree(arr3);
	TESTCASE_ASSERT(!sln.isSymmetric(tr3));
	sln.FreeTree(tr3);

	vector<string> arr4 = { "1" };
	TreeNode* tr4 = sln.MakeTree(arr4);
	TESTCASE_ASSERT(sln.isSymmetric(tr4));
	sln.FreeTree(tr4);
}