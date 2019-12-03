#include "TestCase.h"
#include "LinkedListCommon.h"

using namespace std;

class SolutionRemoveDupFromSortedListII : public LinkedListCommon
{
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head) return head;
		ListNode* pDupPrev = NULL;
		ListNode* pDupStart = head;
		ListNode* pDupEnd = NULL;
		ListNode* pPrev = head;
		ListNode* pCur = head->next;
		while (pCur || pDupEnd)
		{
			if (pCur && pCur->val == pDupStart->val)
			{
				pDupEnd = pCur;
			}
			else
			{
				if (pDupEnd)
				{
					ListNode* pEnd = pDupEnd->next;
					while (pDupStart != pEnd)
					{
						ListNode* pNext = pDupStart->next;
						delete pDupStart;
						pDupStart = pNext;
					}

					if (pDupPrev)
						pDupPrev->next = pDupStart;
					else
					{
						head = pDupStart;
					}

					pDupEnd = NULL;
				}
				else
				{
					pDupPrev = pPrev;
					pDupStart = pCur;
				}
			}

			pPrev = pCur;
			if (pCur)
				pCur = pCur->next;
		}

		return head;
	}
};

RUN_TESTCASE(RemoveDupFromSortedListII)
{
	SolutionRemoveDupFromSortedListII sln;

	vector<int> arr1 = { 1,2,3,3,4,4,5 };
	vector<int> res1 = { 1,2,5 };
	ListNode* l1 = sln.BuildList(arr1);
	l1 = sln.deleteDuplicates(l1);
	TESTCASE_ASSERT(sln.ListEqual(l1, res1));
	sln.FreeList(l1);

	vector<int> arr2 = { 1,1,1,2,3 };
	vector<int> res2 = { 2,3 };
	ListNode* l2 = sln.BuildList(arr2);
	l2 = sln.deleteDuplicates(l2);
	TESTCASE_ASSERT(sln.ListEqual(l2, res2));
	sln.FreeList(l2);

	vector<int> arr3 = { 1,1,1 };
	ListNode* l3 = sln.BuildList(arr3);
	l3 = sln.deleteDuplicates(l3);
	TESTCASE_ASSERT(l3 == NULL);

	vector<int> arr4 = { 2,3,1,1,1 };
	vector<int> res4 = { 2,3 };
	ListNode* l4 = sln.BuildList(arr4);
	l4 = sln.deleteDuplicates(l4);
	TESTCASE_ASSERT(sln.ListEqual(l4, res4));
	sln.FreeList(l4);
}