#include "TestCase.h"
#include "BinaryTreeCommon.h"
#include <queue>
#include <sstream>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string ret;
		queue<pair<TreeNode*, int>> q;
		if (root)
		{
			ret = "[";
			int max_depth = CalcDepth(root);
			q.push(make_pair(root, 1));
			while (q.size() > 0)
			{
				pair<TreeNode*, int> item = q.front();
				q.pop();

				stringstream ss;
				if (item.first)
					ss << item.first->val;
				else
					ss << "null";
				ret += ss.str() + ",";

				if (item.first && item.second < max_depth)
				{
					q.push(make_pair(item.first->left, item.second + 1));
					q.push(make_pair(item.first->right, item.second + 1));
				}
			}
			if (ret.back() == ',')
				ret.pop_back();
			ret += "]";
		}
		return ret;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		if (data.size() <= 2)
			return nullptr;

		vector<TreeNode*> nodes;
		string::const_iterator itL = data.begin() + 1;
		string::const_iterator itR = itL;
		while (itR < data.end())
		{
			if (*itR == ',' || *itR == ']')
			{
				string num = string(itL, itR);
				if (num == "null")
					nodes.push_back(nullptr);
				else
					nodes.push_back(new TreeNode(atoi(num.c_str())));
				itL = itR + 1;
				itR = itL;
			}
			else
			{
				++itR;
			}
		}

		if (nodes.size() > 0)
		{
			int index = 0;
			queue<TreeNode*> q;
			q.push(nodes[index++]);
			while (q.size() > 0)
			{
				TreeNode* curNode = q.front();
				q.pop();

				if (index < nodes.size())
				{
					curNode->left = nodes[index++];
					if (curNode->left)
						q.push(curNode->left);
				}

				if (index < nodes.size())
				{
					curNode->right = nodes[index++];
					if (curNode->right)
						q.push(curNode->right);
				}
			}
			return nodes[0];
		}

		return nullptr;
	}

protected:
	int CalcDepth(TreeNode* node)
	{
		if (!node) return 0;
		if (!node->left && !node->right) return 1;
		int l = node->left ? CalcDepth(node->left) + 1 : 0;
		int r = node->right ? CalcDepth(node->right) + 1 : 0;
		return std::max(l, r);
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
RUN_TESTCASE(SerializeDeserializeBinaryTree)
{
	Codec codec;
	BinaryTreeCommmon sln;

	vector<string> str1 = { "1","2","3","null","null","4","5" };
	TreeNode* tr1 = sln.MakeTree(str1);
	string ret1 = codec.serialize(tr1);
	TESTCASE_ASSERT(ret1 == "[1,2,3,null,null,4,5]");
	TreeNode* tr2 = codec.deserialize(ret1);
	TESTCASE_ASSERT(sln.TreeEqual(tr2, str1));
	sln.FreeTree(tr1);
	sln.FreeTree(tr2);
}