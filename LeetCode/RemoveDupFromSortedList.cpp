#include "TestCase.h"
#include "LinkedListCommon.h"

using namespace std;

class SolutionRemoveDupFromSortedList : public LinkedListCommon
{
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* pCur = head;
		ListNode* pPrev = NULL;
		while (pCur)
		{
			if (pPrev && pPrev->val == pCur->val)
			{
				pPrev->next = pCur->next;
				delete pCur;
				pCur = pPrev->next;
			}
			else
			{
				pPrev = pCur;
				pCur = pCur->next;
			}
		}
		return head;
	}
};

RUN_TESTCASE(RemoveDupFromSortedList)
{
	SolutionRemoveDupFromSortedList sln;

	vector<int> arr1 = { 1,1,2,3,3 };
	vector<int> arr2 = { 1,2,3 };
	ListNode* l1 = sln.BuildList(arr1);
	ListNode* ret1 = sln.deleteDuplicates(l1);
	TESTCASE_ASSERT(sln.ListEqual(ret1, arr2));
	sln.FreeList(ret1);
}