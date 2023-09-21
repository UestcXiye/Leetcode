/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// BST树的中序遍历序列是单调递增的。
// 本题中要求我们将每个节点的值修改为原来的节点值加上所有大于它的节点值之和，
// 这样我们只需要反序中序遍历该二叉搜索树，记录过程中的节点值之和，并不断更新当前遍历到的节点的节点值，即可得到题目要求的累加树。

class Solution
{
private:
    int preSum = 0;

public:
    TreeNode *convertBST(TreeNode *root)
    {
        if (root)
        {
            convertBST(root->right);
            preSum += root->val;
            root->val = preSum;
            convertBST(root->left);
        }
        return root;
    }
};
// @lc code=end
