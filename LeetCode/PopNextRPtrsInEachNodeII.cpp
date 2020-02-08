#include "TestCase.h"
#include <queue>
#include <math.h>

using namespace std;

struct Node {
	int val;
	Node *left;
	Node *right;
	Node *next;
	Node(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class SolutionPopNextRPtrsInEachNodeII
{
public:
	Node* connect(Node* root) {
		if (!root)
			return root;

		queue<std::pair<Node*, int>> q;
		q.push(std::make_pair(root, 0));
		int cur_depth = 0;
		Node* Prev = nullptr;

		while (q.size() > 0)
		{
			std::pair<Node*, int> item = q.front();
			q.pop();

			Node* node = item.first;
			int depth = item.second;

			if (Prev)
				Prev->next = node;

			if (node->left)
				q.push(std::make_pair(node->left, depth + 1));
			if (node->right)
				q.push(std::make_pair(node->right, depth + 1));

			if (q.size() > 0 && q.front().second > depth)
			{
				Prev = nullptr;
				cur_depth = q.front().second;
			}
			else
				Prev = node;
		}
		return root;
	}

public:
	Node* MakeTree(const std::vector<std::string>& arr)
	{
		if (arr.size() <= 0) return nullptr;

		std::queue<Node*> queue;

		size_t index = 0;
		Node* root = new Node(atoi(arr[index++].c_str()));
		queue.push(root);
		while (queue.size() > 0)
		{
			Node* curNode = queue.front();
			queue.pop();

			if (index + 1 <= arr.size())
			{
				std::string curValue = arr[index++];
				if (curValue != "null")
				{
					curNode->left = new Node(atoi(curValue.c_str()));
					queue.push(curNode->left);
				}
			}

			if (index + 1 <= arr.size())
			{
				std::string curValue = arr[index++];
				if (curValue != "null")
				{
					curNode->right = new Node(atoi(curValue.c_str()));
					queue.push(curNode->right);
				}
			}
		}

		return root;
	}

	void FreeTree(Node* root)
	{
		if (!root) return;
		FreeTree(root->left);
		FreeTree(root->right);
		delete root;
	}
};

RUN_TESTCASE(PopNextRPtrsInEachNodeII)
{
	SolutionPopNextRPtrsInEachNodeII sln;

	vector<string> arr1 = { "1","2","3","4","5","null","7" };
	Node* root1 = sln.MakeTree(arr1);
	sln.connect(root1);
	TESTCASE_ASSERT(root1->next == nullptr);
	TESTCASE_ASSERT(root1->left->next == root1->right && root1->right->next == nullptr);
	TESTCASE_ASSERT(root1->left->left->next == root1->left->right);
	TESTCASE_ASSERT(root1->left->right->next == root1->right->right);
	TESTCASE_ASSERT(root1->right->right->next == nullptr);
	sln.FreeTree(root1);
}