#include "TestCase.h"
#include "LinkedListCommon.h"

class SolutionRemoveNthFromEnd : public LinkedListCommon
{
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		int count = 0;
		ListNode* cur = head;
		while (cur)
		{
			count++;
			cur = cur->next;
		}
		
		int idx = count - n;
		cur = head;
		ListNode* prev = NULL;
		while (cur)
		{
			if (idx-- <= 0)
			{
				if (!prev)
				{
					head = cur->next;
					delete cur;
				}
				else
				{
					prev->next = cur->next;
					delete cur;
				}
				break;
			}

			prev = cur;
			cur = cur->next;
		}

		return head;
	}
};

RUN_TESTCASE(RemoveNthFromEnd)
{
	SolutionRemoveNthFromEnd sln;

	std::vector<int> arr = { 1,2,3,4,5 };
	std::vector<int> res = { 1,2,3,5 };
	ListNode* lst1 = sln.BuildList(arr);
	ListNode* res1 = sln.removeNthFromEnd(lst1, 2);
	TESTCASE_ASSERT(sln.ListEqual(res1, res));
	sln.FreeList(res1);
}