/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
    int sumNumbers(TreeNode *root)
    {
        return dfs(root, 0);
    }
    // 辅函数 - 深度优先搜索
    int dfs(TreeNode *root, int preSum)
    {
        if (root == nullptr)
            return 0;
        int curSum = 10 * preSum + root->val;
        if (!root->left && !root->right)
            return curSum;
        else
            return dfs(root->left, curSum) + dfs(root->right, curSum);
    }
};
// @lc code=end
