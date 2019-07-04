#include "TestCase.h"
#include "LinkedListCommon.h"

class SolutionRemoveLinkedList : public LinkedListCommon
{
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* pCur = head;
        ListNode* pPrev = NULL;
        while(pCur)
        {
            if (pCur->val == val)
            {
                ListNode* next = pCur->next;
                if (pPrev)
                    pPrev->next = next;
                else
                    head = next;
                delete pCur;
                pCur = next;
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

RUN_TESTCASE(RemoveLinkedList)
{
    SolutionRemoveLinkedList sln;
    std::vector<int> arr = {6,1,2,6,3,4,5,6};
    ListNode* list = sln.BuildList(arr);
    ListNode* list2 = sln.removeElements(list, 6);
    std::vector<int> result = {1,2,3,4,5};
    TESTCASE_ASSERT(sln.ListEqual(list2, result));
    sln.FreeList(list2);
}
