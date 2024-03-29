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
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int ans = 0;
        function<int(TreeNode *)> dfs = [&](TreeNode *root) -> int
        {
            if (root == nullptr)
                return 0;
            int left = dfs(root->left);
            int right = dfs(root->right);
            ans = max(ans, left + right + 1);
            return max(left, right) + 1;
        };
        dfs(root);
        return ans - 1;
    }
};
// @lc code=end
