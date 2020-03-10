#include "TestCase.h"
#include "LinkedListCommon.h"

using namespace std;

class SolutionDeleteNodeInLinkedList : public LinkedListCommon
{
public:
	void deleteNode(ListNode* node) {
		ListNode* next = node->next;
		node->val = next->val;
		node->next = next->next;
		delete next;
	}
};

RUN_TESTCASE(DeleteNodeInLinkedList)
{
	SolutionDeleteNodeInLinkedList sln;

	vector<int> arr1 = { 4,5,1,9 };
	vector<int> ret1 = { 4,1,9 };
	ListNode* l1 = sln.BuildList(arr1);
	sln.deleteNode(l1->next);
	TESTCASE_ASSERT(sln.ListEqual(l1, ret1));
	sln.FreeList(l1);
}