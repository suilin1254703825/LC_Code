#include "stdafx.h"
#include <vector>
#include "data_struct"
using namespace std;

/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
Example:
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/
ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2)
{
    ListNode* head = new ListNode(0);
    ListNode* listRet = head;

    while (NULL != l1 && NULL != l2)
    {
        if (l1->val > l2->val)
        {
            listRet->next = l2;
            l2 = l2->next;
        }
        else
        {
            listRet->next = l1;
            l1 = l1->next;
        }
        listRet = listRet->next;
    }

    if (NULL == l1)
    {
        listRet->next = l2;
    }
    else if (NULL == l2)
    {
        listRet->next = l1;
    }

    return head->next;
}

istNode* mergeTwoLists2(ListNode* l1, ListNode* l2) {
    if (!l1)
        return l2;
    if (!l2)
        return l1;
    //ensure l1.value < l2.value
    if (l1->val > l2->val)
        swap(l1, l2);
    ListNode* pos = l1;
    ListNode* temp;
    while(pos->next != nullptr && l2 != nullptr) {
        if (pos->next->val > l2->val) {
            temp = l2;
            l2 = temp->next;
            temp->next = pos->next;
            pos->next = temp;
            pos = pos->next;
        }
        else
            pos = pos->next;
    }
    if(pos->next == nullptr)
    	pos->next = l2;
    return l1;
}