#include "TestCase.h"
#include "LinkedListCommon.h"

class SolutionPalindromeList : public LinkedListCommon
{
public:
	bool isPalindrome(ListNode* head) {
		if (!head) return false;
		ListNode* pMiddle = head;
		ListNode* pCur = head;
		while (pCur && pCur->next)
		{
			pCur = pCur->next->next;
			if (!pCur) break;
			pMiddle = pMiddle->next;
		}

		ListNode* ptr1 = pMiddle->next, *ptr2 = pMiddle;
		ptr2->next = NULL;
		while (ptr1)
		{
			ListNode* next = ptr1->next;
			ptr1->next = ptr2;
			ptr2 = ptr1;
			ptr1 = next;
		}

		ptr1 = head;
		while (ptr1)
		{
			if (ptr1->val != ptr2->val)
				return false;
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}

		return true;
	}

	bool isPalindromeNormal(ListNode* head) {
		std::vector<int> arr;
		ListNode* pCur = head;
		while (pCur)
		{
			arr.push_back(pCur->val);
			pCur = pCur->next;
		}
		int s = 0, e = (int)arr.size() - 1;
		while (s < e)
		{
			if (arr[s] != arr[e])
				return false;
			s++;
			e--;
		}
		return true;
	}
};

RUN_TESTCASE(PalindromeList)
{
	SolutionPalindromeList sln;
	ListNode* pList1 = sln.BuildList({ 8,6,7,1,1,7,6,8 });
	TESTCASE_ASSERT(sln.isPalindrome(pList1));
	sln.FreeList(pList1);
	ListNode* pList2 = sln.BuildList({ 8,8,6,6,9,8,3 });
	TESTCASE_ASSERT(!sln.isPalindrome(pList2));
	sln.FreeList(pList2);
	ListNode* pList3 = sln.BuildList({ 8 });
	TESTCASE_ASSERT(sln.isPalindrome(pList3));
	sln.FreeList(pList3);
}
