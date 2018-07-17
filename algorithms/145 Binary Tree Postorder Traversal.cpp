// LC_ClimbStair.cpp : 定义控制台应用程序的入口点。
//


#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
1. 迭代方式，二叉树后序遍历

时间复杂度：O(n)
空间复杂度：O(n)
*/
vector<int> postorderTraversal2(TreeNode* root) {
    vector<int> vec_value = {};
    stack<TreeNode*> stTree;
    if (root == NULL)
    {
        return vec_value;
    }

    stTree.push(root);
    TreeNode* cur;
    TreeNode* pre = NULL;
    
    while (!stTree.empty())
    {
        cur = stTree.top();
        if ((cur->left == NULL && cur->right == NULL) 
            || (pre != NULL && (cur->left == pre || cur->right == pre)))
        {
            cout << cur->val << " " << endl;
            vec_value.push_back(cur->val);
            stTree.pop();
            pre = cur;
        }
        else
        {
            if (cur->right != NULL)
            {
                stTree.push(cur->right);
            }
            if (cur->left != NULL)
            {
                stTree.push(cur->left); 
            }
        }
    }
    return vec_value;
}

/*
2. 递归方式，二叉树后序遍历

时间复杂度：O()
空间复杂度：O()
*/

/*
 * param[in] : root 二叉树根节点
 * param[out]: vecRet 存储数组
 */
void postorderTraversalTail(TreeNode* root, vector<int>& vecRet)
{
    if (NULL != root)
    {
        postorderTraversalTail(root->left, vecRet);
        postorderTraversalTail(root->right, vecRet);
        vecRet.push_back(root->val);
    }
}

/*
 * param[in] : root 二叉树根节点
 * return 后序遍历数组
 */
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> vecRet = {};
    postorderTraversalTail(root, vecRet);
    return vecRet;
}

int main()
{
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    n1->right = n2;
    n2->left = n3;

    vector<int> preTmp1 = postorderTraversal(n1);
    vector<int> preTmp2 = postorderTraversal2(n1);

	getchar();
    return 0;
}