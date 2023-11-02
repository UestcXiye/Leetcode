/*
 * @lc app=leetcode.cn id=1022 lang=cpp
 *
 * [1022] 从根到叶的二进制数之和
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
    int sum = 0;

public:
    int sumRootToLeaf(TreeNode *root)
    {
        vector<int> path;
        dfs(root, path);
        return sum;
    }
    // 辅函数 - 深度优先搜索
    void dfs(TreeNode *root, vector<int> path)
    {
        if (root == nullptr)
            return;
        path.push_back(root->val);
        if (!root->left && !root->right)
        {
            int n = path.size(), num = 0;
            for (int i = 0; i < n; i++)
                if (path[i] == 1)
                    num += pow(2, n - i - 1);
            sum += num;
            return;
        }
        if (root->left)
            dfs(root->left, path);
        if (root->right)
            dfs(root->right, path);
    }
};
// @lc code=end
