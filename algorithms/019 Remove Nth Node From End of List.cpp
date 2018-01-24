#include "stdafx.h"
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
*@brief:
*@param[in]: head the list of nodes
*@param[in]: n the remove index
*@return:
*@Note:
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.
Solution:
遍历一遍链表获取长度，通过长度的索引来删除某一个节点。
note：
1、删除节点方式为：定位到要删除的上一节点处，nodeTmp->next = nodeTmp->next->next;
2、如果删除的是头节点，则head = head->next;
*/
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* nodeTmp = head;
    int nLen = 0;
    while (NULL != nodeTmp)
    {
        ++nLen;
        nodeTmp = nodeTmp->next;
    }
    if (n > nLen)
    {
        return NULL;
    }
    else
    {
        nodeTmp = head;
        for (int i = 0; i < nLen; ++i)
        {
            if (nLen == n)
            {
                head = head->next;
                break;
            }
            else if (i == nLen - n - 1)
            {
                if (NULL != nodeTmp->next->next)
                {
                    nodeTmp->next = nodeTmp->next->next;
                }
                else
                {
                    nodeTmp->next = NULL;
                }
                break;
            }
            nodeTmp = nodeTmp->next;
        }
    }
    return head;
}

int main()
{
    ListNode* node(1);
    ListNode* curList = node;
    for (int i = 2; i < 5; ++i)
    {
        ListNode tmp = new ListNode(i);
        curList->next = tmp;
        curList = tmp;
    }

    ListNode* ret = removeNthFromEnd(node, 2);
    curList = ret;
    while (NULL != curList)
    {
        cout << curList->val;
        curList = curList->next;
        if (NULL != curList)
        {
            cout << "->";
        }
    }
    cout << endl;

    getchar();
    return 0;
}

