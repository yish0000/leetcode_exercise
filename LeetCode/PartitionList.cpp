#include "TestCase.h"
#include "LinkedListCommon.h"

using namespace std;

class SolutionPartitionList : public LinkedListCommon
{
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode* cur = head;
		ListNode* prev = NULL;
		ListNode* rightBeg = NULL;
		ListNode* rightLast = NULL;
		while (cur)
		{
			if (cur->val < x)
			{
				if (!rightBeg)
				{
					rightBeg = cur;
					rightLast = cur;
				}
				else
				{
					rightLast->next = cur;
					rightLast = cur;
				}

				if (prev)
					prev->next = cur->next;
				else
					head = cur->next;
			}
			else
				prev = cur;

			cur = cur->next;
		}

		if (rightBeg)
		{
			if (head)
			{
				cur = head;
				prev = NULL;
				while (cur)
				{
					if (cur->val > rightBeg->val)
					{
						if (!prev)
						{
							head = rightBeg;
							rightLast->next = cur;
						}
						else
						{
							prev->next = rightBeg;
							rightLast->next = cur;
						}
						break;
					}

					prev = cur;
					cur = cur->next;
				}
			}
			else
				head = rightBeg;
		}

		return head;
	}
};

RUN_TESTCASE(PartitionList)
{
	SolutionPartitionList sln;

	vector<int> arr1 = { 1,4,3,2,5,2 };
	vector<int> ret1 = { 1,2,2,4,3,5 };
	ListNode* l1 = sln.BuildList(arr1);
	l1 = sln.partition(l1, 3);
	TESTCASE_ASSERT(sln.ListEqual(l1, ret1));
	sln.FreeList(l1);

	vector<int> arr2 = { 3,1 };
	vector<int> ret2 = { 1,3 };
	ListNode* l2 = sln.BuildList(arr2);
	l2 = sln.partition(l2, 3);
	TESTCASE_ASSERT(sln.ListEqual(l2, ret2));
	sln.FreeList(l2);

	vector<int> arr3 = { 1 };
	ListNode* l3 = sln.BuildList(arr3);
	l3 = sln.partition(l3, 2);
	TESTCASE_ASSERT(sln.ListEqual(l3, arr3));
	sln.FreeList(l3);
}