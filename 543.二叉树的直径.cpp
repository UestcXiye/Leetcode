/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    int maxDepth = 0;
    int dfs(TreeNode *node)
    {
        if (node == nullptr)
            return 0;
        int left = dfs(node->left), right = dfs(node->right);
        maxDepth = max(left + right, maxDepth);
        return max(left, right) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        dfs(root);
        return maxDepth;
    }
};
// @lc code=end
