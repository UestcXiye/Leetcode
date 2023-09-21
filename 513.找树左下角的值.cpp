/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    // 主函数
    int findBottomLeftValue(TreeNode *root)
    {
        int cur_val = 0;
        int cur_depth = 0;
        dfs(root, 0, cur_val, cur_depth);
        return cur_val;
    }
    // 辅函数 - 深度优先搜索
    void dfs(TreeNode *root, int depth, int &curVal, int &curDepth)
    {
        if (root == nullptr)
            return;
        depth += 1;
        dfs(root->left, depth, curVal, curDepth);
        dfs(root->right, depth, curVal, curDepth);
        if (depth > curDepth)
        {
            curDepth = depth;
            curVal = root->val;
        }
    }
};
// @lc code=end
