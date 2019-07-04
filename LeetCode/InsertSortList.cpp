#include "TestCase.h"
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class SolutionInsertSortList
{
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* pCur = head;
        ListNode* pPrev = NULL;
        while(pCur)
        {
            if (pCur == head)
            {
                pPrev = pCur;
                pCur = pCur->next;
            }
            else
            {
                bool swap = false;
                ListNode* key = pCur;
                ListNode* pCur2 = head;
                ListNode* pPrev2 = NULL;
                while(pCur2 && pCur2 != key)
                {
                    if (key->val < pCur2->val)
                    {
                        pPrev->next = key->next;
                        
                        if (pPrev2)
                        {
                            key->next = pPrev2->next;
                            pPrev2->next = key;
                        }
                        else
                        {
                            key->next = head;
                            head = key;
                        }
                        
                        swap = true;
                        break;
                    }
                    
                    pPrev2 = pCur2;
                    pCur2 = pCur2->next;
                }
                
                if (swap)
                {
                    pCur = pPrev->next;
                }
                else
                {
                    pPrev = pCur;
                    pCur = pCur->next;
                }
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
            if (idx >= (int)arr.size())
                return false;
            if (pCur->val != arr[idx])
                return false;
            pCur = pCur->next;
            idx++;
        }
        return idx == arr.size();
    }
};

RUN_TESTCASE(InsertSortList)
{
    SolutionInsertSortList sln;
    std::vector<int> arr = {-1, 5, 3, 4, 0};
    ListNode* list = sln.BuildList(arr);
    ListNode* listSorted = sln.insertionSortList(list);
    std::vector<int> arrSorted = {-1, 0, 3, 4, 5};
    TESTCASE_ASSERT(sln.ListEqual(listSorted, arrSorted));
    sln.FreeList(listSorted);

    std::vector<int> test2 = { 82, 97, 34, 14, 15, 80, 5, 35, 19, 73 };
    std::vector<int> cmp2 = { 5, 14, 15, 19, 34, 35, 73, 80, 82, 97 };
    ListNode* list2 = sln.BuildList(test2);
    ListNode* listSorted2 = sln.insertionSortList(list2);
    TESTCASE_ASSERT(sln.ListEqual(listSorted2, cmp2));
    sln.FreeList(listSorted2);
}
