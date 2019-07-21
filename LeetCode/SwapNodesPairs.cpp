#include "TestCase.h"
#include "LinkedListCommon.h"

class SolutionSwapNodesPairs : public LinkedListCommon
{
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head) return head;
        
        ListNode* newHead = nullptr;
        while(head)
        {
            ListNode* next = head->next;
            if (!next)
                break;
            
            ListNode* nextHead = next->next;
            next->next = head;
            head->next = (nextHead && nextHead->next) ? nextHead->next : nextHead;
            if (!newHead) newHead = next;
            head = nextHead;
        }
        
        return newHead ? newHead : head;
    }
};

RUN_TESTCASE(SwapNodesPairs)
{
    SolutionSwapNodesPairs sln;
    std::vector<int> arr1 = {1,3,5,3,7,3,1,8,2,8,2};
    std::vector<int> res1 = {3,1,3,5,3,7,8,1,8,2,2};
    ListNode* l1 = sln.BuildList(arr1);
    ListNode* r1 = sln.swapPairs(l1);
    TESTCASE_ASSERT(sln.ListEqual(r1, res1));
    sln.FreeList(r1);

    std::vector<int> arr2 = {4,0,0,2,8,8,7,2,6,0};
    std::vector<int> res2 = {0,4,2,0,8,8,2,7,0,6};
    ListNode* l2 = sln.BuildList(arr2);
    ListNode* r2 = sln.swapPairs(l2);
    TESTCASE_ASSERT(sln.ListEqual(r2, res2));
    sln.FreeList(r2);
    
    std::vector<int> arr3 = {0};
    std::vector<int> res3 = {0};
    ListNode* l3 = sln.BuildList(arr3);
    ListNode* r3 = sln.swapPairs(l3);
    TESTCASE_ASSERT(sln.ListEqual(r3, res3));
    sln.FreeList(r3);
    
    ListNode* l4 = sln.swapPairs(nullptr);
    TESTCASE_ASSERT(l4 == nullptr);
}
