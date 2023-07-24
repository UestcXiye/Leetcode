/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    int ans = __INT_MAX__;
    TreeNode *pre = nullptr;
    void inOrder(TreeNode *node)
    {
        if (node == nullptr)
            return;
        inOrder(node->left);
        if (pre != nullptr)
            ans = min(abs(node->val - pre->val), ans);
        pre = node;
        inOrder(node->right);
    }

public:
    int getMinimumDifference(TreeNode *root)
    {
        inOrder(root);
        return ans;
    }
};
// @lc code=end
