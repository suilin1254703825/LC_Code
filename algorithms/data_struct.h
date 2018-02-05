#include "stdafx.h"

/*
 * val      the Node value
 * next     the next Node
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

