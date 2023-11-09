/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
    int maxPathSum(TreeNode *root)
    {
        int ans = INT_MIN;
        function<int(TreeNode *)> dfs = [&](TreeNode *node) -> int
        {
            if (node == nullptr)
                return 0;
            int left_sum = dfs(node->left);
            int right_sum = dfs(node->right);
            ans = max(ans, left_sum + right_sum + node->val);
            return max(max(left_sum, right_sum) + node->val, 0);
        };
        dfs(root);
        return ans;
    }
};
// @lc code=end
