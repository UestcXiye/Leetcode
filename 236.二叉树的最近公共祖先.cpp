/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 递归

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
            return root;
        // p 和 q 其中有一个正好是 root，直接返回 root 就行
        if (root == p || root == q)
            return root;
        // 通过递归，得到左右两棵子树的值
        TreeNode *leftLCA = lowestCommonAncestor(root->left, p, q);
        TreeNode *rightLCA = lowestCommonAncestor(root->right, p, q);
        // p 和 q 分别在 root 的不同子树，直接返回 root 就行
        if (leftLCA && rightLCA)
            return root;
        // p 和 q 在 root 的同一侧，且 root 不等于 p 或者 q 的任何一个，那么就找 p 和 q 在的那一侧子树
        return leftLCA == nullptr ? rightLCA : leftLCA;
    }
};
// @lc code=end
