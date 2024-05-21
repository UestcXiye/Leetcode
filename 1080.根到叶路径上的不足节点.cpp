/*
 * @lc app=leetcode.cn id=1080 lang=cpp
 *
 * [1080] 根到叶路径上的不足节点
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
public:
    TreeNode *sufficientSubset(TreeNode *root, int limit)
    {
        if (root == nullptr)
            return nullptr;
        limit -= root->val;
        if (root->left == nullptr && root->right == nullptr)
            return limit > 0 ? nullptr : root;
        if (root->left)
            root->left = sufficientSubset(root->left, limit);
        if (root->right)
            root->right = sufficientSubset(root->right, limit);
        // 如果左右子树递归完后，当前节点变成了叶子节点，
        // 那么当前节点也要被删除
        return (root->left || root->right) ? root : nullptr;
    }
};
// @lc code=end
