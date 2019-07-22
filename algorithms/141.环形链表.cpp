/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // 判断是否有环
    // 利用快慢指针的特性，如果有环则一定存在 fast == slow 的情况，否则当快指针为无法移动时，即为到了边界
    // 简单的通过尾链接是无法做出判断的
    bool hasCycle(ListNode *head) {
        ListNode* fast, *slow;
        fast = head;
        slow = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) {
                return true;
            }
        }

        return false;
    }

};

