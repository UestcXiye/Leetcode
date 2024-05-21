/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        if (nums.empty())
            return nullptr;

        int n = nums.size();
        // 以 nums[left,...,right] 建立最大二叉树
        function<TreeNode *(int, int)> dfs = [&](int left, int right) -> TreeNode *
        {
            if (left > right)
                return nullptr;
            int mx = INT_MIN, idx = -1;
            for (int i = left; i <= right; i++)
                if (mx < nums[i])
                {
                    mx = nums[i];
                    idx = i;
                }
            TreeNode *root = new TreeNode(nums[idx]);
            root->left = dfs(left, idx - 1);
            root->right = dfs(idx + 1, right);
            return root;
        };

        return dfs(0, n - 1);
    }
};
// @lc code=end
