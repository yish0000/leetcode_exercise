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

class SolutionPopNextRPtrsInEachNode
{
public:
	Node* Prev = nullptr;

	Node* connect(Node* root) {
		if (!root)
			return root;
		queue<Node*> q;
		q.push(root);
		int n = 0;
		while (q.size() > 0)
		{
			Node* node = q.front();
			q.pop();

			if (Prev)
				Prev->next = node;
			n++;

			Prev = ((n + 1) & n) == 0 ? nullptr : node;

			if (node->left)
				q.push(node->left);
			if (node->right)
				q.push(node->right);
		}
		return root;
	}

	/*
	void connectHelper(Node* node, int depth)
	{
		if (!node)
			return;

		if (Prev)
			Prev->next = node;

		Prev = ((n + 1) & n) == 0 ? nullptr : node;

		connectHelper(node->left, ++n);
		connectHelper(node->right, ++n);
	}
	*/

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

RUN_TESTCASE(PopNextRPtrsInEachNode)
{
	SolutionPopNextRPtrsInEachNode sln;

	vector<string> arr1 = { "1","2","3","4","5","6","7" };
	Node* root1 = sln.MakeTree(arr1);
	sln.connect(root1);
	TESTCASE_ASSERT(root1->next == nullptr);
	TESTCASE_ASSERT(root1->left->next == root1->right && root1->right->next == nullptr);
	TESTCASE_ASSERT(root1->left->left->next == root1->left->right);
	TESTCASE_ASSERT(root1->left->right->next == root1->right->left);
	TESTCASE_ASSERT(root1->right->left->next == root1->right->right);
	TESTCASE_ASSERT(root1->right->right->next == nullptr);
	sln.FreeTree(root1);
}