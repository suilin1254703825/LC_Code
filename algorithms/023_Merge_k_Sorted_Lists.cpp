#include "stdafx.h"
#include <vector>
#include <data_struct.h>
using namespace std;

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
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
    else
    {
        listRet->next = l1;
    }

    return head->next;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    int nNum = lists.size() - 1;
    if (lists.empty())
    {
        return NULL;
    }

    while (0 != nNum)
    {
        int nLeft = 0;
        int nRight = nNum;
        int nIndex = 0;
        while (nLeft < nRight)
        {
            lists[nIndex++] = mergeTwoLists(lists[nLeft++], lists[nRight--]);
        }

        nNum = nRight;
    }

    return lists[0];
}
