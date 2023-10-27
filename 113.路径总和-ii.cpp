/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> paths;

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<int> path;
        dfs(root, path, targetSum);
        return paths;
    }
    // 辅函数 - 深度优先搜索
    void dfs(TreeNode *root, vector<int> path, const int targetSum)
    {
        if (root == nullptr)
            return;
        path.push_back(root->val);
        int path_sum = accumulate(path.begin(), path.end(), 0);
        if (!root->left && !root->right && path_sum == targetSum)
        {
            paths.push_back(path);
            return;
        }
        if (root->left)
            dfs(root->left, path, targetSum);
        if (root->right)
            dfs(root->right, path, targetSum);
    }
};
// @lc code=end
