#include "TestCase.h"
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class SolutionRemoveLinkedList
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
    
    ListNode* BuildList(const std::vector<int>& arr)
    {
        ListNode* pHead = NULL;
        ListNode* pCur = NULL;
        for (int i = 0; i < (int)arr.size(); i++)
        {
            if (!pHead)
            {
                pHead = new ListNode(arr[i]);
                pCur = pHead;
            }
            else
            {
                pCur->next = new ListNode(arr[i]);
                pCur = pCur->next;
            }
        }
        return pHead;
    }
    
    void FreeList(ListNode* pHead)
    {
        ListNode* pCur = pHead;
        while (pCur)
        {
            ListNode* pNext = pCur->next;
            delete pCur;
            pCur = pNext;
        }
    }
    
    bool ListEqual(ListNode* head, const std::vector<int>& arr)
    {
        int idx = 0;
        ListNode* pCur = head;
        while(pCur)
        {
            if (idx >= arr.size())
                return false;
            if (pCur->val != arr[idx])
                return false;
            pCur = pCur->next;
            idx++;
        }
        return idx == arr.size();
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
