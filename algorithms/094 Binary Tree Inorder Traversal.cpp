// LC_ClimbStair.cpp : 定义控制台应用程序的入口点。
//


#include <iostream>
#include <stack>
#include <vector>
#include "data_struct.h"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 * param[in] : root 二叉树根节点
 * param[out]: vecRet 存储数组
 */
void inorderTraversalDFS(TreeNode* root, vector<int>& vecRet)
{
    if (NULL != root)
    {
        inorderTraversalDFS(root->left, vecRet);
        cout << root->val << " -> ";
        vecRet.push_back(root->val);
        inorderTraversalDFS(root->right, vecRet);
    }
}

/*
 * param[in] : root 二叉树根节点
 * return 中序遍历数组
 */
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> vecRet = {};
    inorderTraversalDFS(root, vecRet);
    return vecRet;
}

vector<int> inorderTraversal2(TreeNode* root) {
    vector<int> vecRet = {};
    TreeNode* p = root;
    stack<TreeNode*> st;

    while (p != NULL || !st.empty())
    {
        while (p != NULL)
        {
            st.push(p);
            p = p->left;
        }

        if (!st.empty())
        {
            p = st.top();
            st.pop();
            cout << p->val << " -> ";
            vecRet.push_back(p->val);
            p = p->right;
        }
    }

    return vecRet;
}

int main()
{
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    n1->right = n2;
    n2->left = n3;

    vector<int> preTmp1 = inorderTraversal(n1);
    vector<int> preTmp2 = inorderTraversal2(n1);

	getchar();
    return 0;
}

