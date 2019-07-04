#include "TestCase.h"
#include "LinkedListCommon.h"

class SolutionMergeTwoSortedList : public LinkedListCommon
{
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (!l1 || !l2)
		{
			if (!l1 && !l2) return NULL;
			if (l1) return l1;
			if (l2) return l2;
		}
		ListNode* newBeg = l1;
		ListNode* prev = NULL;
		for (bool initLoop = true; ; initLoop = false)
		{
			if (l2->val < l1->val)
			{
				if (initLoop)
					newBeg = l2;
				ListNode* thisMid = l2;
				l2 = l2->next;
				thisMid->next = l1;
				if (prev)
					prev->next = thisMid;
				prev = thisMid;
				if (!l2)
					return newBeg;
			}
			else
			{
				prev = l1;
				if (l1->next)
					l1 = l1->next;
				else
				{
					l1->next = l2;
					return newBeg;
				}
			}
		}

		return newBeg;
	}
};

RUN_TESTCASE(MergeTwoSortedList)
{
	SolutionMergeTwoSortedList sln;
	std::vector<int> arr1 = { 1,2,4,5,7,8,12,34 };
	std::vector<int> arr2 = { -3,0,1,3,4,5,8,9,11,27,33,43,49,78,99 };
	ListNode* list1 = sln.BuildList(arr1);
	ListNode* list2 = sln.BuildList(arr2);
	ListNode* result = sln.mergeTwoLists(list1, list2);
	sln.PrintList(result);
	TESTCASE_ASSERT(sln.ListEqual(result, { -3,0,1,1,2,3,4,4,5,5,7,8,8,9,11,12,27,33,34,43,49,78,99 }));
	sln.FreeList(result);
}