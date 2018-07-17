#include "stdafx.h"
#include <vector>
using namespace std;

/*
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Example：
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *res = NULL, *ptr = NULL;
    int count = 0, sum = 0;

    while (l1 || l2) {
        sum = 0;
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        sum += count;
        count = sum / 10;
        sum %= 10;

        ListNode *tmp = new ListNode(sum);
        if (!res) {
            res = tmp;
            ptr = tmp;
        }
        else {
            ptr->next = tmp;
            ptr = ptr->next;
        }
    }

    if (count > 0) {
        ListNode *tmp = new ListNode(count);
        if (!res) {
            res = tmp;
            ptr = tmp;
        }
        else {
            ptr->next = tmp;
            ptr = ptr->next;
        }
    }
    return res;
}

ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
    ListNode* p = l1;
    ListNode* q = l2;
    ListNode* s = new ListNode(0);
    ListNode* head = s;
    int carry = 0;

    while (p != NULL || q != NULL)
    {
        int a = p ? p->val : 0;
        int b = q ? q->val : 0;
        int sum = a + b + carry;

        s->next = new ListNode(sum % 10);
        s = s->next;

        carry = sum / 10;

        if (p != NULL) p = p->next;
        if (q != NULL) q = q->next;
    }

    if (carry != 0)
    {
        s->next = new ListNode(1);
        s = s->next;
    }

    return head->next;
}

int main(int argc, char const *argv[])
{
    // NO. 002
    {
        vector<int> vecInit1 = { 2, 4, 5 };
        ListNode* l1 = vec2ListNode(vecInit1);
        vector<int> vecInit2 = { 3, 6, 1 };
        ListNode* l2 = vec2ListNode(vecInit2);

        ListNode* ret = addTwoNumbers(l1, l2);
    }
    
    return 0;
}
