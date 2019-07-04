#include "TestCase.h"
#include <iostream>
#include <algorithm>
#include <list>
#include <map>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class SolutionSortLinkedList
{
public:
	ListNode* sortList(ListNode* head) {
		int count = 0;
		ListNode* end = head;
		while (end)
		{
			count++;
			end = end->next;
		}

		return sortList(NULL, head, end, count);
	}

	ListNode* sortList(ListNode* prev, ListNode* beg, ListNode* end, int count)
	{
		if (count < 2)
			return beg;

		ListNode* mid = next(beg, count / 2);
		beg = sortList(prev, beg, mid, count / 2);
		ListNode* midPrev = next(beg, count / 2 - 1);
		mid = sortList(midPrev, mid, end, count - count / 2);

		ListNode* newBeg = beg;
		for (bool initLoop = true; ; initLoop = false)
		{
			if (mid->val < beg->val)
			{
				if (initLoop)
					newBeg = mid;
				ListNode* thisMid = mid;
				mid = mid->next;
				thisMid->next = beg;
				if (prev)
					prev->next = thisMid;
				prev = thisMid;
				midPrev->next = mid;
				if (mid == end)
					return newBeg;
			}
			else
			{
				prev = beg;
				beg = beg->next;
				if (beg == mid)
					return newBeg;
			}
		}

		return newBeg;
	}

	ListNode* next(ListNode* node, int count)
	{
		while (node && count > 0)
		{
			node = node->next;
			count--;
		}

		return node;
	}

	ListNode* BuildList(const std::vector<int>& arr)
	{
		ListNode* pHead = NULL;
		ListNode* pCur = NULL;
		for (int i = 0; i < (int)arr.size(); i++)
		{
			if (!pHead)
			{
				pHead = new ListNode(arr[i]);
				pCur = pHead;
			}
			else
			{
				pCur->next = new ListNode(arr[i]);
				pCur = pCur->next;
			}
		}
		return pHead;
	}

	void FreeList(ListNode* pHead)
	{
		ListNode* pCur = pHead;
		while (pCur)
		{
			ListNode* pNext = pCur->next;
			delete pCur;
			pCur = pNext;
		}
	}

	bool ListEqual(ListNode* pHead, const std::vector<int>& arr)
	{
		size_t idx = 0;
		ListNode* pCur = pHead;
		while (pCur)
		{
			if (idx >= arr.size())
				return false;

			if (pCur->val != arr[idx])
				return false;
			pCur = pCur->next;
			idx++;
		}
		return idx == arr.size();
	}
};

RUN_TESTCASE(SortLinkedList)
{
	SolutionSortLinkedList sln;
	std::vector<int> arr = { -1, 5, 3, 4, 0 };
	ListNode* list = sln.BuildList(arr);
	ListNode* listSorted = sln.sortList(list);
	std::vector<int> arrSorted = { -1, 0, 3, 4, 5 };
	TESTCASE_ASSERT(sln.ListEqual(listSorted, arrSorted));
	sln.FreeList(listSorted);

	std::vector<int> test2 = { 82, 97, 34, 14, 15, 80, 5, 35, 19, 73 };
	std::vector<int> cmp2 = { 5, 14, 15, 19, 34, 35, 73, 80, 82, 97 };
	ListNode* list2 = sln.BuildList(test2);
	ListNode* listSorted2 = sln.sortList(list2);
	TESTCASE_ASSERT(sln.ListEqual(listSorted2, cmp2));
	sln.FreeList(listSorted2);
}