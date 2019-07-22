/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }

    ListNode* mergeKLists_sub(vector<ListNode*>& lists, int start, int end) {
        if (start > end) return nullptr;
        if (start == end) return lists[start];

        int mid = start + (end - start) / 2;
        ListNode* left = mergeKLists_sub(lists, start, mid);
        ListNode* right = mergeKLists_sub(lists, mid + 1, end);

        return mergeTwoLists(left, right);
    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeKLists_sub(lists, 0, lists.size() - 1);
    }
};

