// LC_ClimbStair.cpp : 定义控制台应用程序的入口点。
//


#include <iostream>
#include <stack>
#include <vector>
#include "data_struct.h"

using namespace std;

/*
234. Palindrome Linked List
请判断一个链表是否为回文链表。
示例 2:
输入: 1->2->2->1
输出: true

时间复杂度：O(n)
空间复杂度：O(1)
*/
bool isPalindrome(ListNode* head) {
    ListNode* p = head;
    int val = 0;
    vector<int> st_value;
    while (NULL != p)
    {
        st_value.push_back(p->val);
        p = p->next;
    }

    for (int i = 0; i < st_value.size() / 2; ++i)
    {
        if (st_value[i] != st_value[st_value.size() - 1 - i])
        {
            return false;
        }
    }

    return true;
}


static const auto __ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

ListNode* vec2ListNode(vector<int> vecValue)
{
    ListNode* p = new ListNode(0);
    ListNode* head = p;

    for (int i = 0; i < vecValue.size(); ++i)
    {
        p->next = new ListNode(vecValue[i]);
        p = p->next;
    }

    return head->next;
}

int main()
{
    ListNode* l = vec2ListNode({ 1,2,3,4,3,2,1 });
    Solution sl;
    int a = isPalindrome(l);
    printf("isPalindrome = %d\n", a);
}