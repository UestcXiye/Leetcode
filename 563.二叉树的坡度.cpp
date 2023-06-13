/*
 * @lc app=leetcode.cn id=563 lang=cpp
 *
 * [563] 二叉树的坡度
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
class Solution
{
private:
    int getSum(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        return getSum(root->left) + getSum(root->right) + root->val;
    }

public:
    int findTilt(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        return findTilt(root->left) + findTilt(root->right) + abs(getSum(root->left) - getSum(root->right));
    }
};
// @lc code=end
