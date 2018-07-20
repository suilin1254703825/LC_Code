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
1. 递归方式，二叉树前序遍历

时间复杂度：O()
空间复杂度：O()
*/

/*
 * param[in] : root 二叉树根节点
 * param[out]: vecRet 存储数组
 */
void preorderTraversalDFS(TreeNode* root, vector<int>& vecRet)
{
    if (NULL != root)
    {
        cout << root->val << " " << endl;
        vecRet.push_back(root->val);
        preorderTraversalDFS(root->left, vecRet);
        preorderTraversalDFS(root->right, vecRet);
    }
}

/*
 * param[in] : root 二叉树根节点
 * return 前序遍历数组
 */
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> vecRet = {};
    preorderTraversalDFS(root, vecRet);
    return vecRet;
}

/*
* param[in] : root 二叉树根节点
* return 前序遍历数组
*/
vector<int> preorderTraversal2(TreeNode* root) {
    vector<int> vecRet;
    stack<TreeNode*> st;
    TreeNode* p = root;

    while (NULL != p || !st.empty())
    {
        while (NULL != p)
        {
            cout << p->val << " -> ";
            vecRet.push_back(p->val);

            st.push(p);
            p = p->left;
        }

        if (!st.empty())
        {
            p = st.top();
            st.pop();

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

    vector<int> preTmp1 = preorderTraversal(n1);
    vector<int> preTmp2 = preorderTraversal2(n1);

	getchar();
    return 0;
}