#include "TestCase.h"
#include <unordered_map>

using namespace std;

class SolutionCopyListWithRandomPointer
{
public:
	struct Node {
		int val;
		Node* next;
		Node* random;

		Node(int _val) {
			val = _val;
			next = NULL;
			random = NULL;
		}
	};

public:
	Node* copyRandomList(Node* head) {
		Node* cur = head;

		Node* retHead = nullptr;
		Node* pLast = nullptr;
		unordered_map<Node*, int> h1;
		unordered_map<int, Node*> h2;
		int idx = 0;
		while (cur)
		{
			Node* newNode = new Node(cur->val);
			if (pLast)
				pLast->next = newNode;
			if (!retHead)
				retHead = newNode;
			pLast = newNode;
			h1[cur] = idx;
			h2[idx] = newNode;
			cur = cur->next;
			idx++;
		}

		cur = head;
		pLast = retHead;
		while (cur)
		{
			unordered_map<Node*, int>::iterator it = h1.find(cur->random);
			if (it != h1.end())
				pLast->random = h2[it->second];
			else
				pLast->random = nullptr;
			pLast = pLast->next;
			cur = cur->next;
		}

		return retHead;
	}

public:
	Node* BuildList(const vector<pair<int, int>>& arr)
	{
		Node* pHead = NULL;
		Node* pCur = NULL;
		for (int i = 0; i < (int)arr.size(); i++)
		{
			if (!pHead)
			{
				pHead = new Node(arr[i].first);
				pCur = pHead;
			}
			else
			{
				pCur->next = new Node(arr[i].first);
				pCur = pCur->next;
			}
		}
		pCur = pHead;
		for (int i = 0; i < (int)arr.size(); i++)
		{
			pCur->random = (arr[i].second >= 0) ? next(pHead, arr[i].second) : nullptr;
			pCur = pCur->next;
		}
		return pHead;
	}

	Node* next(Node* head, int n)
	{
		while (head && n > 0)
		{
			head = head->next;
			n--;
		}
		return head;
	}

	int getIndex(Node* head, Node* node)
	{
		int n = 0;
		while (head)
		{
			if (head == node)
				return n;
			head = head->next;
			n++;
		}
		return -1;
	}

	void FreeList(Node* pHead)
	{
		Node* pCur = pHead;
		while (pCur)
		{
			Node* pNext = pCur->next;
			delete pCur;
			pCur = pNext;
		}
	}

	bool ListEqual(Node* pHead, const vector<pair<int, int>>& arr)
	{
		size_t idx = 0;
		Node* pCur = pHead;
		while (pCur)
		{
			if (idx >= arr.size())
				return false;

			if (pCur->val != arr[idx].first)
				return false;

			pCur = pCur->next;
			idx++;
		}

		if (idx != arr.size())
			return false;

		idx = 0;
		pCur = pHead;
		while (pCur)
		{
			if (getIndex(pHead, pCur->random) != arr[idx].second)
				return false;

			pCur = pCur->next;
			idx++;
		}

		return true;
	}
};

RUN_TESTCASE(CopyListWithRandomPointer)
{
	SolutionCopyListWithRandomPointer sln;

	vector<pair<int, int>> arr1 = {
		{7,-1}, {13,0}, {11,4},{10,2},{1,0}
	};
	SolutionCopyListWithRandomPointer::Node* l1 = sln.BuildList(arr1);
	SolutionCopyListWithRandomPointer::Node* l2 = sln.copyRandomList(l1);
	TESTCASE_ASSERT(sln.ListEqual(l2, arr1));
	sln.FreeList(l1);
	sln.FreeList(l2);
}