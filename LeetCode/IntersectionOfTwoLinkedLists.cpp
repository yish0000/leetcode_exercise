#include "TestCase.h"
#include "LinkedListCommon.h"

using namespace std;

class SolutionIntersectionOfTwoLinkedList : public LinkedListCommon
{
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int swap = 2;
		ListNode* curA = headA;
		ListNode* curB = headB;
		while (curA && curB)
		{
			if (curA == curB)
				return curA;
			curA = curA->next;
			if (!curA && swap > 0)
			{
				curA = headB;
				swap--;
			}
			curB = curB->next;
			if (!curB && swap > 0)
			{
				curB = headA;
				swap--;
			}
		}
		return nullptr;
	}
};

RUN_TESTCASE(IntersectionOfTwoLinkedList)
{
	SolutionIntersectionOfTwoLinkedList sln;

	vector<int> arrA = { 4,1 };
	vector<int> arrB = { 5,0,1 };
	vector<int> arrC = { 8,4,5 };
	ListNode* lA = sln.BuildList(arrA);
	ListNode* lB = sln.BuildList(arrB);
	ListNode* lC = sln.BuildList(arrC);
	lA->next->next = lC;
	lB->next->next->next = lC;
	TESTCASE_ASSERT(sln.getIntersectionNode(lA, lB) == lC);
	lA->next->next = nullptr;
	lB->next->next->next = nullptr;
	TESTCASE_ASSERT(sln.getIntersectionNode(lA, lB) == nullptr);
	sln.FreeList(lA);
	sln.FreeList(lB);
	sln.FreeList(lC);
}